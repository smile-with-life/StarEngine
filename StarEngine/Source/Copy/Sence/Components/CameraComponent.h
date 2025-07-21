#pragma once
#include "Runtime/Core/Core.h"
#include "Runtime/Sence/Component.h"
#include "Runtime/Core/Math/Math.h"
#include "Runtime/Core/Math/Vector3.h"
#include "Runtime/Core/Math/Matrix4.h"

namespace Star
{
enum class CameraType
{
    None,
    Orthogonal, // 正交投影
    Perspective // 透视投影
};

class CameraComponent :public Component
{
public:
    CameraComponent();

    virtual ~CameraComponent();
public:
    void UpdateViewMatrix();

    void UpdateProjectionMatrix();
public:
    // 相机类型
    CameraType m_type;

    // 观察矩阵
    Matrix4<float> m_view;

    // 投影矩阵
    Matrix4<float> m_projection;

    // 相机的位置
    Vector3<float> m_position;

    // 相机的朝向
    Vector3<float> m_front;

    // 相机的上方向
    Vector3<float> m_up;

    // 相机的右方向
    Vector3<float> m_right;

    // 近裁剪面距离
    float m_nearClip;

    // 远裁剪面距离
    float m_farClip;

    // 视野角度
    float m_fov;


};
}// namespace Star