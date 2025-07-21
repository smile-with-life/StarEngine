#pragma once

#include "Core/Core.h"
#include "Core/String/String.h"
#include "Core/File/File.h"

#include <Ultralight/Ultralight.h>
#include <AppCore/Platform.h>
#include <AppCore/AppCore.h>
#include <Ultralight/RefPtr.h>
#include <Ultralight/Renderer.h>
#include <Ultralight/View.h>
#include <Ultralight/platform/Config.h>
#include <Ultralight/platform/GPUDriver.h>
#include <Ultralight/platform/FileSystem.h>


namespace Star
{
class FileSystem :public ultralight::FileSystem
    {
    public:
        virtual ~FileSystem()
        {

        }

        virtual bool FileExists(const ultralight::String& file_path)
        {
            return File::Exists(file_path.utf8().data());
        }

        virtual ultralight::String GetFileMimeType(const ultralight::String& file_path) 
        {
            return "";
        }


        virtual ultralight::String GetFileCharset(const ultralight::String& file_path)
        {
            return "UTF-8";
        }

        virtual ultralight::RefPtr<ultralight::Buffer> OpenFile(const ultralight::String& file_path)
        {
            file_path.utf8();
            m_file.Open(file_path.utf8().data(), OpenMode::ReadOnly);

            m_file.ReadAll(m_buffer);

            return ultralight::Buffer::Create(m_buffer.Data(), m_buffer.Size(), nullptr, ultralight::DestroyBufferCallback());
        }
    private:
        File m_file;
        ByteBuffer m_buffer;
    };
// 自定义窗口监听器
class Win32WindowListener : public ultralight::WindowListener {
public:
    Win32WindowListener(HWND hwnd) : hwnd_(hwnd) {}

    virtual void OnClose(ultralight::Window* window) override {
        DestroyWindow(hwnd_);
    }

    virtual void OnResize(ultralight::Window* window, uint32_t width, uint32_t height) override {
        // 调整覆盖层大小
        if (overlay_) {
            overlay_->Resize(width, height);
        }
    }

    void SetOverlay(ultralight::RefPtr<ultralight::Overlay> overlay) { overlay_ = overlay; }

private:
    HWND hwnd_;
    ultralight::RefPtr<ultralight::Overlay> overlay_;
};
class GameUI : public ultralight::LoadListener, public ultralight::Logger
{
public:
    GameUI(){}
    ~GameUI() {
        view = nullptr;
        renderer = nullptr;
    }

    void Init(void* window)
    {
        using namespace ultralight;
        LogMessage(LogLevel::Info, "Starting Run(), waiting for page to load...");

        Config config;
        Platform& platform = Platform::instance();
        platform.set_config(config);
        platform.set_file_system(GetPlatformFileSystem("./Asset/"));
        platform.set_font_loader(ultralight::GetPlatformFontLoader());
        platform.set_logger(this);
        
        renderer = Renderer::Create();

        


        ViewConfig view_config;
        view_config.initial_device_scale = 2.0;
        view_config.is_accelerated = false;

        view = renderer->CreateView(1600, 800, view_config, nullptr);
        view->set_load_listener(this);

        view->LoadHTML("<h1>Hello World!</h1>");
        //view->LoadURL("file:///page.html");

        do {
            renderer->Update();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        } while (!done);

        renderer->RefreshDisplay(0);
        renderer->Render();

        BitmapSurface* bitmap_surface = (BitmapSurface*)view->surface();


        RefPtr<Bitmap> bitmap = bitmap_surface->bitmap();

        bitmap->WritePNG("result.png");

        LogMessage(LogLevel::Info, "Saved a render of our page to result.png.");

    }

    void Tick()
    {
        
    }

    void Exit()
    {
        delete m_file_system;
    }

    virtual void OnFinishLoading(ultralight::View* caller, uint64_t frame_id, bool is_main_frame,
        const ultralight::String& url) override {
        ///
        /// Our page is done when the main frame finishes loading.
        ///
        if (is_main_frame) {
            LogMessage(ultralight::LogLevel::Info, "Our page has loaded!");

            ultralight::String html = view->EvaluateScript("document.documentElement.outerHTML;");

            LogMessage(ultralight::LogLevel::Info, "HTML: " + html);
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            ///
            /// Set our done flag to true to exit the Run loop.
            ///
            /// 
            done = true;
        }
    }

    ///
    /// Inherited from Logger, this is called when the library wants to print a message to the log.
    ///
    virtual void LogMessage(ultralight::LogLevel log_level, const ultralight::String& message) override {
        std::cout << "> " << message.utf8().data() << std::endl << std::endl;
    }
private:
    // 渲染器
    ultralight::RefPtr<ultralight::Renderer> renderer;

    // 视图
    ultralight::RefPtr<ultralight::View> view;

    FileSystem* m_file_system;

    bool done = false;

    ultralight::RefPtr<ultralight::Window> m_window;
    ultralight::RefPtr<ultralight::Overlay> m_overlay;
    Win32WindowListener* m_window_listener;
};

}// namespace Star