#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <math.h>
#include <stdio.h>
#define PI 3.1415926f

float ang = 0;
float EyeX = 0;
float EyeY = 0;
float EyeZ = 0;
float CenterX = 0;
float CenterY = 0;
float CenterZ = -1;

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

void desenhaCubo(){
    // Gera cubo centrado na origem
    // Ordem: face da frente, face de trás, lado esquerdo, lado direito, parte de cima, parte de baixo

    glPushMatrix();
    glTranslatef(0, 0, 0.5);
    glColor3f(0, 0, 0);
    desenhaQuadrado();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -0.5);
    glColor3f(0, 1, 0);
    desenhaQuadrado();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.5, 0, 0);
    glRotatef(90, 0, 1, 0);
    glColor3f(0, 0, 1);
    desenhaQuadrado();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5, 0, 0);
    glRotatef(90, 0, 1, 0);
    glColor3f(1, 0, 0);
    desenhaQuadrado();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0.5, 0);
    glRotatef(90, 1, 0, 0);
    glColor3f(0.6, 0.5, 0.8);
    desenhaQuadrado();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -0.5, 0);
    glRotatef(90, 1, 0, 0);
    glColor3f(0.9, 0.1, 0.224);
    desenhaQuadrado();

    glPopMatrix();
}

void ProdutoVetorial(float ax, float ay, float az, float bx, float by, float bz, float* rx, float* ry, float* rz){ // Produto vetorial entre a e b
    *rx = ay * bz - az * by;
    *ry = az * bx - ax * bz;
    *rz = ax * by - ay * bx;
}

void MoveFrente(float speed)
{
    float dx = CenterX - EyeX;
    float dy = CenterY - EyeY;
    float dz = CenterZ - EyeZ;

    float tam = sqrt(dx * dx + dy * dy + dz * dz);

    dx /= tam;
    dy /= tam;
    dz /= tam;

    CenterX += dx * speed;
    CenterY += dy * speed;
    CenterZ += dz * speed;

    EyeX += dx * speed;
    EyeY += dy * speed;
    EyeZ += dz * speed;
}

void MoveTras(float speed)
{
    MoveFrente(-speed);
}

void MoveEsquerda(float speed)
{
    float dx;
    float dy;
    float dz;

    ProdutoVetorial(0, 1, 0, (CenterX - EyeX), (CenterY - EyeY), (CenterZ - EyeZ), &dx, &dy, &dz);

    float tam = sqrt(dx * dx + dy * dy + dz * dz);

    dx /= tam;
    dy /= tam;
    dz /= tam;

    CenterX += dx * speed;
    CenterY += dy * speed;
    CenterZ += dz * speed;

    EyeX += dx * speed;
    EyeY += dy * speed;
    EyeZ += dz * speed;
}

void MoveDireita(float speed)
{
    MoveEsquerda(-speed);
}

void RotateLeft(float speed)
{
    float dx;
    float dy;
    float dz;

    ProdutoVetorial(0, 1, 0, (CenterX - EyeX), (CenterY - EyeY), (CenterZ - EyeZ), &dx, &dy, &dz);

    float tam = sqrt(dx * dx + dy * dy + dz * dz);

    dx /= tam;
    dy /= tam;
    dz /= tam;

    CenterX += dx * speed;
    CenterY += dy * speed;
    CenterZ += dz * speed;
}

void RotateRight(float speed)
{
    RotateLeft(-speed);
}

void RotateLeftAround(float speed) // Gira pra esquerda em torno do próprio eixo
{
    float dx;
    float dy;
    float dz;

    ProdutoVetorial(0, 1, 0, (CenterX - EyeX), (CenterY - EyeY), (CenterZ - EyeZ), &dx, &dy, &dz);

    float tam = sqrt(dx * dx + dy * dy + dz * dz);

    dx /= tam;
    dy /= tam;
    dz /= tam;

    EyeX += dx * speed;
    EyeY += dy * speed;
    EyeZ += dz * speed;
}

void RotateRightAround(float speed) // Gira pra direita em torno do próprio eixo
{
    RotateLeftAround(-speed);
}

void display ()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(EyeX, EyeY, EyeZ, CenterX, CenterY, CenterZ, 0, 1, 0); // (EyeX, EyeY, EyeZ, CenterX, CenterY, CenterZ, UpX, UpY, Upz)

    glPushMatrix();
    glTranslatef(1, 0, -8);
    glRotatef(ang, 1, 1, 0);
    desenhaCubo();

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7, 0, -3);
    glRotatef(ang, 1, 1, 0);
    desenhaCubo();

    glPopMatrix();

    ang += 1.5;

    glutPostRedisplay(); // Rechama a display()
    glutSwapBuffers(); // Troca o buffer com o novo
}

void keypress(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'w':
			MoveFrente(0.1);
			break;
		case 's':
			MoveTras(0.1);
			break;
        case 'a':
            MoveEsquerda(0.1);
            break;
        case 'd':
            MoveDireita(0.1);
            break;
        case 'q':
            RotateLeft(0.1);
            break;
        case 'e':
            RotateRight(0.1);
            break;
        case 'z':
            RotateLeftAround(0.1);
            break;
        case 'c':
            RotateRightAround(0.1);
            break;
	}
}

void reshape (int w, int h)
{
    // Vamos mexer na matriz de projection
    glMatrixMode(GL_PROJECTION);
    /* Definir matriz de projeção:
    gluPerspective(angulo de visão da camera (fov), aspecto (largura da tela / altura da tela), distancia do near plane, distancia do far plane)
    */
    glLoadIdentity();
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
    glutCreateWindow("ini camera");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keypress);
    /* cor de fundo*/
    glClearColor(1.0, 1.0, 1.0, 1);
    // Ativando teste de profundidade
    glEnable(GL_DEPTH_TEST);
    /* interact … */
    glutMainLoop();
    return 0;
}
