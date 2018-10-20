#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "bullet.h"
#include "camera.h"
#include "vec3d.h"
#include <iostream>
#include <cmath>

void Bullet::Move()
{
	Vec3D d = m_center - m_eye;
	float tam = d.Length();
	d /= tam;
	m_center += d * 0.1;
	m_eye += d * 0.1;
}

void Bullet::Draw()
{
	glPushMatrix();
	glTranslatef(m_eye.x, m_eye.y, m_eye.z);
	glutSolidSphere(0.1, 100, 100);
	glPopMatrix();

}

void Bullet::Set(Vec3D eye, Vec3D center)
{
	m_eye = eye;
	m_center = center;
}