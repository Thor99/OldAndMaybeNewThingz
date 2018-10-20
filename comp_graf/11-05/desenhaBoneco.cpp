#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <math.h>
#define PI 3.1415926f

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
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, -0.15, 0); // Mexe no boneco todo.

    glPushMatrix(); // Duplica a identidade

    glScalef(0.5, 1, 1);
    glColor3f(0, 0, 0);
    desenhaQuadrado();

    glPopMatrix(); // Retira a matriz que afetamos
    glPushMatrix(); // Duplica a identidade

    glTranslatef(0.38, -0.63, 0);
    glRotatef(45, 0, 0, 1);
    glScalef(0.15, 0.3, 1);
    glColor3f(0.5, 0.2, 1);
    desenhaQuadrado();

    glPopMatrix(); // Retira a matriz que afetamos
    glPushMatrix(); // Duplica a identidade

    glTranslatef(-0.38, -0.63, 0);
    glRotatef(-45, 0, 0, 1);
    glScalef(0.15, 0.3, 1);
    glColor3f(0.5, 0.2, 1);
    desenhaQuadrado();

    glPopMatrix(); // Retira a matriz que afetamos
    glPushMatrix(); // Duplica a identidade

    glTranslatef(0, 0.75, 0);
    glColor3f(0.13, 0.53, 0.24);
    desenhaCirculo(0.25);

    glPopMatrix(); // Retira a matriz que afetamos
    glPushMatrix(); // Duplica a identidade

    glTranslatef(-0.5, 0.4, 0);
    glScalef(0.3, 0.13, 1);
    glColor3f(0.19, 0.35, 0.42);
    desenhaQuadrado();

    glPopMatrix(); // Retira a matriz que afetamos
    glPushMatrix(); // Duplica a identidade

    glTranslatef(0.5, 0.4, 0);
    glScalef(0.3, 0.13, 1);
    glColor3f(0.19, 0.35, 0.42);
    desenhaQuadrado();

    glTranslatef(0.01, 0.8, 0); // Soma de 0.5 + 0.01, 0.4 + 0.8
    glScalef(0.42, 0.4, 1);
    glColor3f(0.19, 0.35, 0.42);
    desenhaQuadrado();

    glTranslatef(0.01, 1.4, 0); // Soma de 0.5 + 0.01 + 0.01, 0.4 + 0.8 + 1.4
    glColor3f(0.19, 0.35, 0.42);
    desenhaQuadrado();

    glPopMatrix();

    glutPostRedisplay(); // Rechama a display()
    glutSwapBuffers(); // Troca o buffer com o novo
}

// void keypress(unsigned char key, int x, int y)
// {
// 	switch(key)
// 	{
// 		case 'w':
// 			scale += 0.05;
// 			break;
// 		case 's':
// 			scale -= 0.05;
// 			break;
// 		case 'a':
// 			ang += 0.05;
// 			break;
// 		case 'd':
// 			ang -= 0.05;
// 			break;
// 		case 'i':
// 			ty += 0.05;
// 			break;
// 		case 'k':
// 			ty -= 0.05;
// 			break;
// 		case 'j':
// 			tx += 0.05;
// 			break;
// 		case 'l':
// 			tx -= 0.05;
// 			break;
// 	}
// }

void reshape (int w, int h)
{
    glViewport(0, 0, w, h);
}

int main (int argc, char* argv[])
{
    /* open GLUT */
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    /* create window */
    glutCreateWindow("Boneco");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    // glutKeyboardFunc(keypress);
    /* cor de fundo*/
    glClearColor(1.0, 1.0, 1.0, 1);
    /* interact … */
    glutMainLoop();
    return 0;
}
