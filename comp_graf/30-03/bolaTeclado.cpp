#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <math.h>
#define PI 3.1415926f

float tx = 0;
float ty = 0;

void display ()
{	
	  float d = sqrt(tx * tx + ty * ty); // distancia entre o ponto (tx,ty) e (0, 0);

    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW); // Diz pro openGl que a partir de agora voce vai mexer na ModelView; // Model view é uma matriz de transformação do openGL

    glLoadIdentity(); // Carrega a matriz identidade, reseta a transformacao

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
    
    glTranslatef(tx, ty, 0); // Eixo X, Eixo Y, Eixo Z

    glBegin(GL_POLYGON);
    	for (float ang = 0; ang <= 2 * PI; ang += 0.01)
    	{
      		glColor3f(1 - d, 0, 0); // Cada vez maior a distancia da origem, mais preto irá ficar
      		glVertex2f(cos(ang) * 0.1, sin(ang) * 0.1); // * 0.1 Pra deixar a bola pequena
    	}
  	glEnd();
  	
  	glLoadIdentity(); // Carrega a matriz identidade, reseta a transformacao
  	glTranslatef(-tx, ty, 0); // Eixo X, Eixo Y, Eixo Z
  	
  	glBegin(GL_POLYGON);
    	for (float ang = 0; ang <= 2 * PI; ang += 0.01)
    	{
      		glColor3f(1 - d, 0, 0); // Cada vez maior a distancia da origem, mais preto irá ficar
      		glVertex2f(cos(ang) * 0.1, sin(ang) * 0.1); // * 0.1 Pra deixar a bola pequena
    	}
  	glEnd();
  	
  	glLoadIdentity(); // Carrega a matriz identidade, reseta a transformacao
  	glTranslatef(tx, -ty, 0); // Eixo X, Eixo Y, Eixo Z
  	
  	glBegin(GL_POLYGON);
    	for (float ang = 0; ang <= 2 * PI; ang += 0.01)
    	{
      		glColor3f(1 - d, 0, 0); // Cada vez maior a distancia da origem, mais preto irá ficar
      		glVertex2f(cos(ang) * 0.1, sin(ang) * 0.1); // * 0.1 Pra deixar a bola pequena
    	}
  	glEnd();
  	
  	glLoadIdentity(); // Carrega a matriz identidade, reseta a transformacao
  	glTranslatef(-tx, -ty, 0); // Eixo X, Eixo Y, Eixo Z
  	
  	glBegin(GL_POLYGON);
    	for (float ang = 0; ang <= 2 * PI; ang += 0.01)
    	{
      		glColor3f(1 - d, 0, 0); // Cada vez maior a distancia da origem, mais preto irá ficar
      		glVertex2f(cos(ang) * 0.1, sin(ang) * 0.1); // * 0.1 Pra deixar a bola pequena
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
			ty += 0.05;
			break;
		case 's':
			ty -= 0.05;
			break;
		case 'a':
			tx -= 0.05;
			break;
		case 'd':
			tx += 0.05;
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
