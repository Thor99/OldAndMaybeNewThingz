#ifdef _WIN32
  #include <windows.h>
#endif
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#define PI 3.1415926f

void display()
{
  /* Clear window */

  /* Os últimos elementos a serem chamados, são os que ficam mais por cima. */

  /*
    y = R * sen @                    --> R = raio
    x = R * cos @                    --> R = raio
  */

  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_POLYGON);
    for (float ang = 0; ang <= 2 * PI; ang += 0.01)
    {
      glColor3f(ang/(2*PI), 0, 1.0f - ang/(2*PI));
      glVertex2f(cos(ang), sin(ang)); // No caso é a tela toda, então R = 1
    }
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
  glutCreateWindow("CIRCLE FIRST");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);

  /* OpenGL settings */
  glClearColor(1, 1, 1, 0);

  /* Interact */
  glutMainLoop();
  return 0;
}