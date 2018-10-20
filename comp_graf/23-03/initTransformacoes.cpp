#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <math.h>
#define PI 3.1415926f

float tempo = 0;

void display ()
{
    /*float mt[16] = {
      1, 0, 0, 0,
      0, 1, 0, 0,
      0, 0, 1, 0,
      0.5, 0.5, 0, 1
    };  // Toda matriz no openGL tem tamanho 16; Essa, nesse caso é de translação; Move nosso desenho 0.5 pra cima e pro lado
    */

    /*float mt[16] = {
      0, -1, 0, 0,
      1, 0, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1
    }; // Toda matriz no openGL tem tamanho 16; Essa, nesse caso é de rotação; Rotaciona nosso desenho 90 graus pro sentido horário
    */

    float mt[16] = {
      0.5, 0, 0, 0,
      0, 0.5, 0, 0,
      0, 0, 1, 0,
      0, 0, 0, 1
    }; // Toda matriz no openGL tem tamanho 16; Essa, nesse caso é de escala; Nesse caso, multiplica o x e o y por 1/2;

    glMatrixMode(GL_MODELVIEW); // Diz pro openGl que a partir de agora voce vai mexer na ModelView; // Model view é uma matriz de transformação do openGL

    glLoadMatrixf(mt); // Vai carregar essa matriz como sendo a model view. o "f" é pra indicar que é uma matriz de floats

    tempo += 0.07;

    glClear(GL_COLOR_BUFFER_BIT);

    glLineWidth(1);

    glBegin(GL_LINES);
        glColor3f(0, 0, 0);

        glVertex2f(-1, 0);
        glVertex2f(0, 0);
        glVertex2f(0, 1);
        glVertex2f(0, -1);
        glVertex2f(0, 0);
        glVertex2f(1, 0);

    glEnd();

    glLineWidth(3);

    glBegin(GL_LINE_STRIP);
      for (float ang = -1; ang <= 1; ang += 0.01) // X varia de -1 a 1 na tela e no ciclo trigonométrico
      {
        glColor3f(0.4 , 0.78, 0.2);
        glVertex2f(ang, sin((ang * PI + PI) + tempo)); // Y em função de X é formulado por tal equação pois ao invés de -1 até 1, queremos variar y de 0 a 2pi.
      }
    glEnd();

    glFlush();

    glutPostRedisplay(); // Rechama a display()
    glutSwapBuffers(); // Troca o buffer com o novo desenho com o buffer do desenho velho, e escreve o novo na tela
}

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
    glutCreateWindow("Transformacao");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    /* cor de fundo*/
    glClearColor(1.0, 1.0, 1.0, 1);
    /* interact … */
    glutMainLoop();
    return 0;
}
