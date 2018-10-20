#ifdef _WIN32
  #include <windows.h>
#endif
#include <math.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>

void display()
{
  /* Clear window */

  glClear(GL_COLOR_BUFFER_BIT);

  /* draw a triangle */
  glColor3f(0, 0, 0);
  glBegin(GL_TRIANGLES);
    glVertex2f(-1, -1);
    glVertex2f(1, 1);
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
  glutCreateWindow("ANCAP FLAG");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);

  /* OpenGL settings */
  glClearColor(1, 1, 0, 0);

  /* Interact */
  glutMainLoop();
  return 0;
}