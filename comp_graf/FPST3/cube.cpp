#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "cube.h"

void Cube::DrawSurface() const
{
    glBegin(GL_QUADS);
        glTexCoord2f(0, 1);
        glVertex2f(-0.5, 0.5);

        glTexCoord2f(1, 1);
        glVertex2f(0.5, 0.5);

        glTexCoord2f(1, 0);
        glVertex2f(0.5, -0.5);

        glTexCoord2f(0, 0);
        glVertex2f(-0.5, -0.5);
    glEnd();
}

void Cube::Render() const
{
    // Gera cubo centrado na origem
    // Ordem: face da frente, face de trás, lado esquerdo, lado direito, parte de cima, parte de baixo

    // Frente
    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glColor3f(0, 0, 0);
    glNormal3f(0, 0, 1);
    DrawSurface();

    glPopMatrix();

    // Tras
    glPushMatrix();
    glTranslatef(0, 0, -0.5);
    glColor3f(0, 1, 0);
    glNormal3f(0, 0, -1);
    DrawSurface();

    glPopMatrix();

    // Esquerda
    glPushMatrix();
    glTranslatef(-0.5, 0, 0);
    glRotatef(90, 0, 1, 0);
    glColor3f(0, 0, 1);
    glNormal3f(0, 0, -1);
    DrawSurface();

    glPopMatrix();

    // Direita
    glPushMatrix();
    glTranslatef(0.5, 0, 0);
    glRotatef(90, 0, 1, 0);
    glColor3f(1, 0, 0);
    glNormal3f(0, 0, 1);
    DrawSurface();

    glPopMatrix();

    // Cima
    glPushMatrix();
    glTranslatef(0, 0.5, 0);
    glRotatef(90, 1, 0, 0);
    glColor3f(0.6, 0.5, 0.8);
    glNormal3f(0, 0, -1);
    DrawSurface();

    glPopMatrix();

    // Baixo
    glPushMatrix();
    glTranslatef(0, -0.5, 0);
    glRotatef(90, 1, 0, 0);
    glColor3f(0.9, 0.1, 0.224);
    glNormal3f(0, 0, 1);
    DrawSurface();

    glPopMatrix();
}
