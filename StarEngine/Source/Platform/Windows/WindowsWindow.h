#pragma once

#include "Platform/Window.h"

#include <windows.h>
#include <windowsx.h>


namespace Star
{
class WindowsWindow : public Window
{
public:
	WindowsWindow() = default;
	virtual ~WindowsWindow() = default;

	// 初始化
	virtual void Init() override;

	// 更新
	virtual void Tick() override;

	// 退出
	virtual void Exit() override;

	// 设置窗口标题
	virtual void SetTitle(const String& title) override;

	// 设置窗口的模式
	virtual void SetWindowMode(WindowMode mode) override;

	// 设置窗口的透明度
	virtual void SetOpacity(const float opacity) override;

	// 设置垂直同步
	virtual void SetVSync(bool enabled) override;

	// 将窗口置于最前面
	virtual void BringFront() override;

	// 改变窗口大小
	virtual void ResizeWindow(int32 Width, int32 Height) override;

	// 移动窗口到指定位置
	virtual void MoveWindow(int32 x, int32 y) override;

	// 使窗口获得焦点
	virtual void FocusWindow() override;

	// 关闭窗口
	virtual void CloseWindow() override;

	// 最小化
	virtual void MinimizeWindow() override;

	// 最大化
	virtual void MaximizeWindow() override;

	// 恢复原状
	virtual void RestoreWindow() override;

	// 显示窗口
	virtual void ShowWindow() override;

	// 隐藏窗口
	virtual void HideWindow() override;

	// 启用或禁用窗口
	virtual void EnableWindow(bool enabled) override;

	// 判断窗口是否在前台
	virtual bool IsFront() const override;

	// 判断平台是否支持全屏模式
	virtual bool IsSupportFullscreen() const override;

	// 判断窗口是否最大化
	virtual bool IsMax() const override;

	// 判断窗口是否最小化
	virtual bool IsMin() const override;

	// 判断窗口是否可见
	virtual bool IsVisible() const override;

	// 判断指定坐标是否在窗口内
	virtual bool IsPointInWindow(int32 x, int32 y) const override;

	// 判断是否是垂直同步
	virtual bool IsVSync() const override;

	// 获取窗口标题
	virtual std::string GetTitle() const override;

	// 获取窗口宽度
	virtual int32 GetWidth() const override;

	// 获取窗口高度
	virtual int32 GetHeight() const override;

	// 获取窗口水平位置
	virtual int32 GetPositionX() const override;

	// 获取窗口垂直位置
	virtual int32 GetPositionY() const override;

	// 获取当前窗口的模式
	virtual WindowMode GetWindowMode() const override;

	// 获取与窗口关联的原生操作系统句柄
	virtual void* GetNativeHandle() const override;
private:
	// Windows窗口句柄
	HWND m_hWnd;

	// 设备上下文
	HDC m_hDC;

	// 渲染上下文
	HGLRC m_hRC;

	// 像素格式
	PIXELFORMATDESCRIPTOR m_pixelFormat;
};

}// namespace Star