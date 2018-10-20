#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "Bitmap.h"
#include "camera.h"
#include "vec3d.h"
#include "cube.h"
#include "texture.h"
#include "snake.h"
#include <math.h>
#include <stdio.h>
#define PI 3.1415926f

float ang = 0;

Vec3D eye(0, 10, 0);
Vec3D center(0, 0, 0.01);
Vec3D up(0, 1, 0);

Cube cube;

Camera camera(eye, center, up);

Texture texture;

Snake snake;

float xAtual = 0;
float zAtual = 0;

void desenhaCirculo(float raio)
{
    glBegin(GL_POLYGON);
    for (float ang = 0; ang <= 2 * PI; ang += 0.01)
    {
        float x = cos(ang) * raio;
        float y = sin(ang) * raio;

        glTexCoord2f((x + 1) / 2, (y + 1) / 2);
        glVertex2f(x, y);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    camera.Render();

    snake.GenerateBorders();

    texture.Use();
    snake.Render();

    snake.Move();

    glutPostRedisplay(); // Rechama a display()
    glutSwapBuffers(); // Troca o buffer com o novo
}

void keypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        snake.TurnUp();
        break;

    case 's':
        snake.TurnDown();
        break;

    case 'a':
        snake.TurnLeft();
        break;

    case 'd':
        snake.TurnRight();
        break;
    /*
    case 'q':
        camera.RotateLeft(0.1);gay
        break;
    case 'e':
        camera.RotateRight(0.1);
        break;
    case 'z':
        camera.RotateLeftAroundCenter(0.1);
        break;
    case 'c':
        camera.RotateRightAroundCenter(0.1);
        break;*/
    }

}

void reshape(int w, int h)
{
    // Vamos mexer na matriz de projection
    glMatrixMode(GL_PROJECTION);
    /* Definir matriz de projeção:
    gluPerspective(angulo de visão da camera (fov), aspecto (largura da tela / altura da tela), distancia do near plane, distancia do far plane)
    */
    glLoadIdentity();
    gluPerspective(90, (float)w / h, 0.1, 1000);
    glViewport(0, 0, w, h);
}

int main(int argc, char* argv[])
{
    /* open GLUT */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    /* create window */
    glutCreateWindow("Snake");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keypress);
    /* cor de fundo*/
    glClearColor(1.0, 1.0, 1.0, 1);
    // Ativando texture
    texture.Load("hugo.bmp");
    // Ativando teste de profundidade
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    snake.GenerateSnake();
    /* interact … */
    glutMainLoop();
    return 0;
}