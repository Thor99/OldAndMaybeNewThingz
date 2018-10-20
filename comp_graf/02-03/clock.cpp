#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <time.h>
#include <math.h>
#define PI 3.1415926f

void display ()
{
    time_t now = time(NULL);
    struct tm* horario = localtime(&now);
    int hora = horario->tm_hour;
    int minutos = horario->tm_min;
    int segundos = horario->tm_sec;
    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    for (float ang = 0; ang <= 2 * PI; ang += 0.01)
    {
        glColor3f(0.9, 0.9, 0.9);
        glVertex2f(cos(ang), sin(ang));
    }
    glEnd();

    glLineWidth(5);

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    for (float ang = 0; ang <= 2 * PI; ang += PI / 6.0) // Marcacoes da hora - O angulo entre cada marcador é 2pi / 12
    {
        glVertex2f(cos(ang), sin(ang));
        glVertex2f(0.8*cos(ang), 0.8*sin(ang)); // Vai de 0.8 a 1 (Se mudar, muda o tamanho da linha que marca a hora)
    }
    glEnd();

    glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glVertex2f(0, 0);
        glVertex2f(sin(segundos*PI/30), cos(segundos*PI/30));

        float angminuto = minutos*PI / 30.0 + segundos*PI / 30.0 / 60.0;
        glColor3f(0, 0, 0);
        glVertex2f(0, 0);
        glVertex2f(sin(angminuto), cos(angminuto));
        float anghora = hora*PI/6.0 + angminuto/12.0;
        glVertex2f(0, 0);
        glVertex2f(0.5*sin(anghora), 0.5*cos(anghora));
    glEnd();

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
    glutCreateWindow("Clock");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    /* cor de fundo*/
    glClearColor(1.0, 1.0, 1.0, 1);
    /* interact … */
    glutMainLoop();
    return 0;
}
