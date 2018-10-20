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
    

    glColor3f(0, 0, 0);
    desenhaQuadrado();

    glColor3f(1, 1, 1);
    desenhaCirculo(0.4);

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
    glutCreateWindow("func quad");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    // glutKeyboardFunc(keypress);
    /* cor de fundo*/
    glClearColor(1.0, 1.0, 1.0, 1);
    /* interact … */
    glutMainLoop();
    return 0;
}
