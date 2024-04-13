#include "Precompiled.h"
#include "SpMath.h"

using namespace SpringEngine::Math;

const Vector2 Vector2::Zero(0.0f);
const Vector2 Vector2::One(1.0f, 1.0f);
const Vector2 Vector2::XAxis(1.0f, 0.0f);
const Vector2 Vector2::YAxis(0.0f, 1.0f);

const Vector3 Vector3::Zero(0.0f);
const Vector3 Vector3::One(1.0f);
const Vector3 Vector3::XAxis(1.0f, 0.0f, 0.0f);
const Vector3 Vector3::YAxis(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::ZAxis(0.0f, 0.0f, 1.0f);

const Matrix4 Matrix4::Zero({ 0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0 });

const Matrix4 Matrix4::Identity({ 1, 0, 0, 0,
                                0, 1, 0, 0,
                                0, 0, 1, 0,
                                0, 0, 0, 1 });

const Quaternion Quaternion::Identity = { 0.0f, 0.0f, 0.0f, 1.0f };
const Quaternion Quaternion::Zero = { 0.0f, 0.0f, 0.0f, 0.0f };

//member function
void Quaternion::Conjugate()
{

};
void Quaternion::Inverse()
{

};
void Quaternion::Magnitude() const noexcept
{

};
void Quaternion::MagnitudeSquared() const noexcept
{

};
void Quaternion::Normalize() noexcept
{

};
float Quaternion::Dot(const Quaternion& q)const noexcept
{

};
//static funtions
Quaternion Quaternion::Conjugate(const Quaternion& q)
{

};
float Quaternion::Magnitude(const Quaternion& q)
{

};
Quaternion Quaternion::Normalize(const Quaternion& q)
{

};
Quaternion Quaternion::CreateFromAxisAngle(const Vector3& axis, float angle)noexcept
{

};
Quaternion Quaternion::CreateFromYawPitchRoll(float yaw, float pitch, float roll)
{
    const float cy = cos(yaw * 0.5f);
    const float sy = sin(yaw * 0.5f);
    const float cp = cos(pitch * 0.5f);
    const float sp = sin(pitch * 0.5f);
    const float cr = cos(roll * 0.5f);
    const float sr = sin(roll * 0.5f);

    return
    {
        sr * cp * cy - cr * sp * sy,
        cr * sp * cy + sr * cp * sy,
        cr * cp * sy - sr * sp * cy,
        cr * cp * cy + sr * sp * sy
    }
};
Quaternion Quaternion::CreateFromRotationMatrix(const Matrix4& m)noexcept
{

};
Quaternion Quaternion::Lerp(const Quaternion& q0, const Quaternion& q1, float t)
{

};
Quaternion Quaternion::Slerp(const Quaternion& q0, const Quaternion& q1, float t)
{
    float dot = q0.Dot(q1);
    float q1Scale = 1.0f;
    if (dot < 0.0f)
    {
        dot = -dot;
        q1Scale = -1.0f;
    }
    if (dot > 0.9999f)
    {
        return Normalize(Lerp(q0, q1, t));
    }
    const float theta = acosf(dot);
    const float sinTheta = sinf(theta);
    const float scale0 = sinf(theta * (1.0f - t) / sinTheta);
    const float scale1 = q1Scale * sinf(theta * t) / sinTheta;
};