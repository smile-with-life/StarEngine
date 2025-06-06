#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Core/String/String.h"

namespace Star
{
/* GPU最大资源限制 */ 
/* 定义图形API的硬件限制常量，确保跨平台兼容性 */

constexpr uint32 TEXTURE_SAMPLERS_MAX = 16; // 最大纹理采样器数量

constexpr uint32 VERTEX_ATTRIBUTES_MAX = 24; // 最大顶点属性数量

constexpr uint32 BUFFER_BINDINGS_MAX = 31; // 最大缓冲区绑定数

constexpr uint32 UNIFORM_BLOCKS_BINDING_MAX = 16;// 可以绑定的统一缓冲区的最大数量

constexpr uint32 COLOR_ATTACHMENTS_MAX = 4;// 渲染目标中可以附加的颜色附件的最大数量

constexpr uint32 DRAW_ELEMENTS_INDIRECT_COMMAND_SIZE = 4 * 5;// 间接绘制命令的大小

// ​​资源存储模式
enum class MemoryMode 
{
    None,         
    Private,      // GPU访问专用内存（最快）
    Shared,       // CPU和GPU共享内存
    Managed,      // CPU和GPU之间同步的内存对
    Memoryless    // 内存只能由GPU访问，并且只能在渲染过程中临时存在              
};

// 剔除模式
enum class CullMode : uint8
{ 
    Disabled, // 禁用剔除
    Front, // 剔除正面三角形（通常用于从内部观察物体时）
    Back // 剔除背面三角形（默认情况，通常用于从外部观察物体时）
};

// 环绕模式
enum class WindingMode : uint8 
{ 
    Clockwise, // 顶点按顺时针顺序排列的三角形为正面
    CounterClockwise // 顶点按逆时针顺序排列的三角形为正面
};

// 深度范围归一化
enum class NormalizedZRange : uint8 
{ 
    NegOneToOne, // 深度值归一化到 [-1, 1] 范围
    ZeroToOne  // 深度值归一化到 [0, 1] 范围
};

// 基本图元类型
enum class PrimitiveType : uint8 
{
    Point, // 点
    Line, // 线段
    LineStrip, // 连续的折线
    Triangle, // 三角形面
    TriangleStrip, // 连续的三角形面
};

// 操作的结果状态
struct Result {
    enum class ErrorCode 
    {
        Ok, // 操作成功
        ArgumentInvalid, // 无效参数
        ArgumentNull,// 非空参数传递了nullptr
        ArgumentOutOfRange, // 参数超出有效范围
        InvalidOperation,// 当前状态下无法执行操作
        Unsupported,// 当前硬件或软件不支持的功能
        Unimplemented,// 功能尚未实现
        RuntimeError,// 内部发生未知错误
    };

    ErrorCode Code = ErrorCode::Ok;
    String Message = "";

    explicit Result() = default;

    explicit Result(ErrorCode code)
        : Code(code)
        , Message("")
    {

    }

    Result(ErrorCode code, String message)
        : Code(code)
        , Message(message)
    {

    } 
};

// 图形API类型
enum class GraphicAPIType {
    None,
    OpenGL,
    Metal,
    Vulkan,
    D3D11,
    D3D12
};

// 裁剪区域
struct ScissorRect 
{
    uint32 x = 0;
    uint32 y = 0;
    uint32 width = 0;
    uint32 height = 0;

    [[nodiscard]] bool IsNull() const 
    {
        return !width && !height;
    }
};
}// namespace Star
