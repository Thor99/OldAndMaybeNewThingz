#ifdef _WIN32
  #include <windows.h>
#endif
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

/*
Sistema de coordenadas (X, Y):

Canto superior esquerdo: -1, 1
Canto superior direito: 1, 1
Meio: 0, 0
Canto inferior esquerdo: -1, -1
Canto inferior direito: 1, -1
*/

void display()
{
  /* Clear window */

  glClear(GL_COLOR_BUFFER_BIT);

  /* draw a triangle */
  glColor3f(0, 0, 0); // 3: Número de variáveis (1, 2, 3) (para RGB), f: Tipo de variável (float, double, int); Parâmetros: RGB
  glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, 1); // 2: Número de coordenadas (2, 3, 4), f: tipo de coordenada (float, double, int) ; Parâmetros: coordenadas dos pontos, em eixo x e y, no caso.
    glVertex2f(0, 0.1);
    glVertex2f(1, 0.6);
  glEnd();
  glBegin(GL_TRIANGLES);
    glColor3f(0.9, 0.98, 0);
    glVertex2f(-1, -1);

    glColor3f(0.343, 0, 1);
    glVertex2f(0, 0);

    glColor3f(0.57, 0, 0.8);
    glVertex2f(1, -1);
  glEnd();

  glFlush();

}

void reshape(int w, int h)
{
  glViewport(0, 0 , w, h);
  glutPostRedisplay();
}

int main(int argc, char **argv)
{
  /* Open GLUT */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(600, 600);

  /* Create window */
  glutCreateWindow("BOTELHO");
  glutReshapeFunc(reshape); // Função para chamar quando a janela redimensionar
  glutDisplayFunc(display); // Função chamada para desenhar

  /* OpenGL settings */
  glClearColor(1, 1, 0, 0); // 0 mais escuro, 1 mais claro

  /* Interact */
  glutMainLoop();
  return 0;
}