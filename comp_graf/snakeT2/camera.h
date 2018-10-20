#ifndef CAMERA_H
#define CAMERA_H
#include "vec3d.h"

class Camera
{
public:
    Camera(Vec3D eye, Vec3D center, Vec3D up);

    void SetEye(Vec3D eye);
    void SetEye(float x, float y, float z);

    void SetCenter(Vec3D center);
    void SetCenter(float x, float y, float z);

    void SetUp(Vec3D up);
    void SetUp(float x, float y, float z);

    void MoveForward(float speed);
    void MoveBackward(float speed);
    void MoveLeft(float speed);
    void MoveRight(float speed);
    void RotateLeft(float speed);
    void RotateRight(float speed);
    void RotateLeftAroundCenter(float speed);
    void RotateRightAroundCenter(float speed);

    void Render();

private:
    Vec3D m_eye;
    Vec3D m_center;
    Vec3D m_up;
};

#endif