#ifndef BULLET_H
#define BULLET_H
#include "vec3d.h"

class Bullet
{
public:
	bool atirou = false;
	void Move();
	void Draw();
	void Set(Vec3D eye, Vec3D camera);
private:
	Vec3D m_eye;
	Vec3D m_center;
};

#endif