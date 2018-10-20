#include "vec3d.h"
#include <iostream>
#include <cmath>

Vec3D::Vec3D()
{
    x = 0;
    y = 0;
    z = 0;
}

Vec3D::Vec3D(float a, float b, float c)
{
    x = a;
    y = b;
    z = c;
}

Vec3D Vec3D::operator+(Vec3D vec)
{
    return Vec3D(x + vec.x, y + vec.y, z + vec.z);
}

void Vec3D::operator+=(Vec3D vec)
{
    x += vec.x;
    y += vec.y;
    z += vec.z;
}

Vec3D Vec3D::operator-(Vec3D vec)
{
    return Vec3D(x - vec.x, y - vec.y, z - vec.z);
}

Vec3D Vec3D::operator-()
{
    return Vec3D(-x, -y, -z);
}

void Vec3D::operator-=(Vec3D vec)
{
    x -= vec.x;
    y -= vec.y;
    z -= vec.z;
}

Vec3D Vec3D::operator*(Vec3D vec)
{
    return Vec3D(x * vec.x, y * vec.y, z * vec.z);
}

Vec3D Vec3D::operator*(float val)
{
    return Vec3D(x * val, y * val, z * val);
}

void Vec3D::operator*=(Vec3D vec)
{
    x *= vec.x;
    y *= vec.y;
    z *= vec.z;
}

void Vec3D::operator*=(float val)
{
    x *= val;
    y *= val;
    z *= val;
}

Vec3D Vec3D::operator/(float val)
{
    return Vec3D(x/val, y/val, z/val);
}

void Vec3D::operator/=(float val)
{
    x /= val;
    y /= val;
    z /= val;
}

float Vec3D::Length() const
{
    return sqrt(x*x + y*y + z*z);
}

Vec3D Vec3D::CrossProduct(Vec3D vec)
{
    return Vec3D(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
}