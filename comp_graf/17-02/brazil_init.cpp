#ifdef _WIN32
  #include <windows.h>
#endif
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

void display()
{
  /* Os últimos elementos a serem chamados, são os que ficam mais por cima (Pois são chamados por último) */
  
  /* Clear window */
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1, 1, 0);
  glBegin(GL_QUADS);
    glVertex2f(-1, 0);
    glVertex2f(0, 1);
    glVertex2f(1, 0);
    glVertex2f(0, -1);
  glEnd();

  glColor3f(0, 0, 1);
  glBegin(GL_QUADS);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
  glEnd();

  glColor3f(1, 1, 1);
  glBegin(GL_QUADS);
    glVertex2f(-0.5, 0.1);
    glVertex2f(0.5, 0.1);
    glVertex2f(0.5, -0.1);
    glVertex2f(-0.5, -0.1);
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
  glutCreateWindow("BRAZIL FLAG");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);

  /* OpenGL settings */
  glClearColor(1, 1, 1, 0);

  /* Interact */
  glutMainLoop();
  return 0;
}