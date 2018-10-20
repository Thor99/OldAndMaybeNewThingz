#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <math.h>
#define PI 3.1415926f

float ang = 0;

void desenhaQuadrado()
{
    // Quadrado de lado 1 em torno do eixo 0
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

void desenhaCirculo(float raio)
{
    glBegin(GL_POLYGON);
        for(float ang = 0; ang <= 2 * PI; ang += 0.01)
        {
            float x = cos(ang) * raio;
            float y = sin(ang) * raio;

            glTexCoord2f((x + 1) / 2, (y + 1) / 2);
            glVertex2f(x, y);
        }
    glEnd();
}

void display ()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(0, 0, -8); // eixo z translada negativamente (o que vier abaixo vai para trás)
    glRotatef(ang, 0, 1, 0); // Rotaciona em torno de Y
    glColor3f(0, 0, 0);
    desenhaQuadrado();

    glPopMatrix();

    glTranslatef(-1, 0, -2);
    glRotatef(ang, 0, 1, 0); // Rotaciona em torno de Y
    desenhaQuadrado();

    glPopMatrix();

    ang += 1.5;

    glutPostRedisplay(); // Rechama a display()
    glutSwapBuffers(); // Troca o buffer com o novo
}

void reshape (int w, int h)
{
    // Vamos mexer na matriz de projection
    glMatrixMode(GL_PROJECTION);
    /* Definir matriz de projeção:
    gluPerspective(angulo de visão da camera (fov), aspecto (largura da tela / altura da tela), distancia do near plane, distancia do far plane)
    */
    gluPerspective(90, (float) w/h, 0.1, 1000);
    glViewport(0, 0, w, h);
}

int main (int argc, char* argv[])
{
    /* open GLUT */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    /* create window */
    glutCreateWindow("ini 3d");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    // glutKeyboardFunc(keypress);
    /* cor de fundo*/
    glClearColor(1.0, 1.0, 1.0, 1);
    // Ativando teste de profundidade
    glEnable(GL_DEPTH_TEST);
    /* interact … */
    glutMainLoop();
    return 0;
}
