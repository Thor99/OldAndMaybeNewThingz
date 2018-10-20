#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <math.h>
#include "Bitmap.h"
#define PI 3.1415926f

float tx = 0;
float ty = 0;

void display ()
{
	  float d = sqrt(tx * tx + ty * ty); // distancia entre o ponto (tx,ty) e (0, 0);

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_TEXTURE);
    glTranslatef(0.5, 0.5, 0);
    glRotatef(0.5, 0, 0, 1);
    glTranslatef(-0.5, -0.5, 0);

    glMatrixMode(GL_MODELVIEW); // Diz pro openGl que a partir de agora voce vai mexer na ModelView; // Model view é uma matriz de transformação do openGL

    glLoadIdentity(); // Carrega a matriz identidade, reseta a transformacao

    glEnable(GL_TEXTURE_2D);

    glBegin(GL_QUADS);
      glTexCoord2f(0, 0);
      glVertex2f(-1, -1);

      glTexCoord2f(0, 1);
      glVertex2f(-1, 1);

      glTexCoord2f(1, 1);
      glVertex2f(1, 1);

      glTexCoord2f(1, 0);
      glVertex2f(1, -1);
    glEnd();

    glLineWidth(3);

    glTranslatef(tx, ty, 0); // Eixo X, Eixo Y, Eixo Z

    glBegin(GL_POLYGON);
    	for (float ang = 0; ang <= 2 * PI; ang += 0.01)
    	{
        float x = cos(ang);
        float y = sin(ang);

      	glColor3f(1, 1, 1);

        glTexCoord2f((x + 1) / 2, (y + 1) / 2); // Pra x e y ir de 0 a 1
      	glVertex2f(x * 0.1, y * 0.1); // * 0.1 Pra deixar a bola pequena
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
    glutCreateWindow("Texturaa");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keypress);
    /* cor de fundo*/
    glClearColor(1.0, 1.0, 1.0, 1);
    /* Carrega textura */
    Bitmap bmp;
  	if(bmp.loadBMP("hugo.bmp"))
  	{
  		GLuint texture;
  		glGenTextures(1, &texture); // Gera 1 textura vazia

  		glBindTexture(GL_TEXTURE_2D, texture); // Comando que diz que mexeremos com a textura texture nos comandos abaixo
  		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); // Como deve esticar a imagem
  		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); // Como deve reduzir a imagem
  		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmp.width, bmp.height, 0,GL_RGB, GL_UNSIGNED_BYTE, bmp.data); // Carrega a imagem e joga pro openGL

  		// select modulate to mix texture with color for shading
  		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
      // Modulate: cor = color * tex
      // Replace: cor = tex

  		// if wrap is true, the texture wraps over at the edges (repeat)
  		//       ... false, the texture ends at the edges (clamp)
  		bool wrap = true;
  		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap ? GL_REPEAT : GL_CLAMP ); // Se wrap for true, repetira a imagem, senão, finalizara na borda
  		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap ? GL_REPEAT : GL_CLAMP ); // Se wrap for true, repetira a imagem, senão, finalizara na borda
  	}
  	else
  	{
  		printf("Erro com a textura\n");
  	}
    /* interact … */
    glutMainLoop();
    return 0;
}
