#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "camera.h"
#include "vec3d.h"
#include <iostream>
#include <cmath>

Camera::Camera(Vec3D eye, Vec3D center, Vec3D up)
{
    m_eye = eye;
    m_center = center;
    m_up = up;
}

void Camera::SetEye(Vec3D eye)
{
    m_eye.x = eye.x;
    m_eye.y = eye.y;
    m_eye.z = eye.z;
}

void Camera::SetEye(float x, float y, float z)
{
    m_eye.x = x;
    m_eye.y = y;
    m_eye.z = z;
}

void Camera::SetCenter(Vec3D center)
{
    m_center.x = center.x;
    m_center.y = center.y;
    m_center.z = center.z;
}

void Camera::SetCenter(float x, float y, float z)
{
    m_center.x = x;
    m_center.y = y;
    m_center.z = z;
}

void Camera::SetUp(Vec3D up)
{
    m_up.x = up.x;
    m_up.y = up.y;
    m_up.z = up.z;
}

void Camera::SetUp(float x, float y, float z)
{
    m_up.x = x;
    m_up.y = y;
    m_up.z = z;
}

void Camera::MoveForward(float speed)
{
    Vec3D d = m_center - m_eye;

    float tam = d.Length();

    d /= tam;

    m_center += d * speed;
    m_eye += d * speed;
}

void Camera::MoveBackward(float speed)
{
    MoveForward(-speed);
}

void Camera::MoveLeft(float speed)
{
    Vec3D d = m_up.CrossProduct(m_center - m_eye);

    float tam = d.Length();

    d /= tam;

    m_center += d * speed;
    m_eye += d * speed;
}

void Camera::MoveRight(float speed)
{
    MoveLeft(-speed);
}

void Camera::RotateLeft(float speed)
{

    Vec3D d = m_up.CrossProduct(m_center - m_eye);

    float tam = d.Length();

    d /= tam;

    m_center += d * speed;
}

void Camera::RotateRight(float speed)
{
    RotateLeft(-speed);
}

void Camera::RotateLeftAroundCenter(float speed)
{
    Vec3D d = m_up.CrossProduct(m_center - m_eye);

    float tam = d.Length();

    d /= tam;

    m_eye += d * speed;
}

void Camera::RotateRightAroundCenter(float speed)
{
    RotateLeftAroundCenter(-speed);
}

void Camera::Render()
{
    gluLookAt(m_eye.x, m_eye.y, m_eye.z, m_center.x, m_center.y, m_center.z, m_up.x, m_up.y, m_up.z);
}