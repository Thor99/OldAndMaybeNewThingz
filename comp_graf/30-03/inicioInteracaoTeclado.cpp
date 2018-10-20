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
float scale = 1;
float ang = 0;
float tx = 0;
float ty = 0;

void display ()
{
	tempo += 0.07;
	
    glMatrixMode(GL_MODELVIEW); // Diz pro openGl que a partir de agora voce vai mexer na ModelView; // Model view é uma matriz de transformação do openGL

    glLoadIdentity(); // Carrega a matriz identidade, reseta a transformacao
    
    glTranslatef(tx, ty, 0); // Eixo X, Eixo Y, Eixo Z
    glRotatef(ang, 0, 0, 1); // Angulo, Eixo X, Eixo Y, Eixo Z -- Nesse caso, os parametros dos eixos que tiverem 1, iram rodar o angulo do parametro.
    glScalef(scale, scale, 1); // Eixo X, Eixo Y, Eixo Z	

    /* Executará na ordem: scale, rotate e translate. */

    /* OBS: quando o translate é chamado antes do rotate, o objeto não roda mais no próprio eixo, e faz movimento circular */	

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
    glutSwapBuffers(); // Troca o buffer com o novo 
}

void keypress(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'w':
			scale += 0.05;
			break;
		case 's':
			scale -= 0.05;
			break;
		case 'a':
			ang += 0.05;
			break;
		case 'd':
			ang -= 0.05;
			break;
		case 'i':
			ty += 0.05;
			break;
		case 'k':
			ty -= 0.05;
			break;
		case 'j':
			tx += 0.05;
			break;
		case 'l':
			tx -= 0.05;
			break;
	}				
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
    glutKeyboardFunc(keypress);
    /* cor de fundo*/
    glClearColor(1.0, 1.0, 1.0, 1);
    /* interact … */
    glutMainLoop();
    return 0;
}
