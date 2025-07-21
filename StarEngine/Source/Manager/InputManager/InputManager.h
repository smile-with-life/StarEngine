#pragma once
#include "Core/Core.h"

namespace Star
{
enum class MouseMode
{
    None,
    // 鼠标光标可见且可以自由移动
    Visible,
    // 鼠标光标被隐藏
    Hidden,
    // 鼠标光标被捕获，鼠标移动不会导致光标离开窗口
    Captured,
    // 鼠标光标被限制在窗口内，光标在到达窗口边缘时会停止
    Confined,
};
// 输入类型
enum class InputType
{
    None,
    Mouse,
    Keybord,
    Joypad,
    Touch
};
class InputManager
{
public:
    InputManager() = default;
public:
    void Init();

    void Tick();

    void Exit();
};
}// namespace Star