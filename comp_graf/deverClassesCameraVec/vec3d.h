#ifndef Vec3D_H
#define Vec3D_H

struct Vec3D
{
    Vec3D();
    Vec3D(float x, float y, float z);

    Vec3D operator+(Vec3D v);
    Vec3D operator-();
    Vec3D operator-(Vec3D v);
    Vec3D operator*(float val); //escala
    Vec3D operator*(Vec3D v); //x1*x2, y1*y2, z1*z2
    Vec3D operator/(float val);
    void operator+=(Vec3D v);
    void operator-=(Vec3D v);
    void operator*=(float val);
    void operator*=(Vec3D v);
    void operator/=(float val);
    float Length() const; // sqrt(x*x + y*y + z*z)
    Vec3D CrossProduct(Vec3D v); //this * v
    float x, y, z;
};

#endif