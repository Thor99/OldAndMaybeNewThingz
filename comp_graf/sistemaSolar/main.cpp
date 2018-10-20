/*
695.500 sol
2.440 mercurio 57.910.000 = 54 500 000
6.052 venus 108.200.000 = 102 500 000
6.371 terra 149.600.000 = 143 500 000
3.390 marte 225.400.000 = 221 500 000
69.911 jupiter 765.400.000 = 695 000 000
58.232 saturno 1.433.000.000 = 1 434 500 000
25.362 urano 2 287.600.000 = 2 289 500 000
24.622 netuno 4.498.000.000 = 4 499 500 000

Mercurio - 47.36 km/s - 0.001
Venus - 35.02 km/s - 0.00074
Terra - 29.78 km/s - 0.00063
Marte - 24.07 km/s - 0.00051
Jupiter - 13.07 km/s - 0.00028
Saturno - 9.69 km/s - 0.0002
Urano - 6.80 km/s - 0.00014
Netuno - 5.43 km/s - 0.00011
*/

#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include <math.h>
#define PI 3.1415926f

float posX[1000];
float posY[1000];

float tmerc=0;
float tven=0;
float tter=0;
float tmart=0;
float tjupt=0;
float tsat=0;
float turan=0;
float tnet=0;

float scale = 1;
float tx = 0;
float ty = 0;

void onInitialization()
{
    glEnable(GL_POINT_SMOOTH);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glPointSize(6.0);
}

void display ()
{

    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW); 

    glLoadIdentity(); 

    glTranslatef(0, 0, 0); 
    glScalef(scale, scale, 1); 

    glBegin(GL_POINTS);
          for(int i = 0; i < 1000; ++i)
          {
              glColor3f(1, 1, 1);
              if(i % 2 == 0)
              {
                if(i > 500)
                {
                  glVertex2f(-posX[i], -posY[i]);
                }
                else
                {
                  glVertex2f(posX[i], -posY[i]);
                }
              }
              else
              {
                if(i > 500)
                {
                  glVertex2f(posX[i], posY[i]);
                }
                else
                {
                  glVertex2f(-posX[i], posY[i]);
                }
              }
          }
      glEnd();

    glLineWidth(3);

    glLoadIdentity();
    glScalef(scale, scale, 1);;
    glBegin(GL_POLYGON); //sol
      for (float ang = 0; ang <= 2 * PI; ang += 0.01)
      {
          float x = cos(ang)* 0.07;
          float y = sin(ang)* 0.07;

          glColor3f(1.000, 0.549, 0.000);
          glVertex2f(x, y); 
      }
    glEnd();

    glLoadIdentity();
    glRotatef(tmerc, 0 , 0, 1);
    glTranslatef( 0.083*scale, 0, 0);
    glScalef(scale, scale, 1);
    glBegin(GL_POLYGON); //mercurio
      for (float ang = 0; ang <= 2 * PI; ang += 0.01)
      {
          float x = cos(ang)* 0.07;
          float y = sin(ang)* 0.07;

          glColor3f(0.804, 0.522, 0.247);
          glVertex2f(x/47, y/47); 
          tmerc += 0.001;
      }
    glEnd();

    glLoadIdentity();
    glRotatef(tven, 0 , 0, 1);
    glTranslatef( 0.093*scale, 0, 0);
    glScalef(scale, scale, 1);
    glBegin(GL_POLYGON); //venus
      for (float ang = 0; ang <= 2 * PI; ang += 0.01)
      {
          float x = cos(ang)* 0.07;
          float y = sin(ang)* 0.07;

          glColor3f(1.000, 0.498, 0.314);

          glVertex2f(x/23, y/23); 
          tven += 0.00074;
      }
    glEnd();

    glLoadIdentity();
    glRotatef(tter, 0 , 0, 1);
    glTranslatef( 0.1055*scale, 0, 0);
    glScalef(scale, scale, 1);
    glBegin(GL_POLYGON); //terra
      for (float ang = 0; ang <= 2 * PI; ang += 0.01)
      {
          float x = cos(ang)* 0.07;
          float y = sin(ang)* 0.07;

          glColor3f(0.529, 0.808, 0.922);

          glVertex2f(x/21.8, y/21.8); 

          tter += 0.00063;
      }
    glEnd();

    glLoadIdentity();
    glRotatef(tmart, 0 , 0, 1);
    glTranslatef( 0.119*scale, 0, 0);
    glScalef(scale, scale, 1);
    glBegin(GL_POLYGON); //marte
      for (float ang = 0; ang <= 2 * PI; ang += 0.01)
      {
          float x = cos(ang)* 0.07;
          float y = sin(ang)* 0.07;

          glColor3f(1.000, 0.498, 0.314);

          glVertex2f(x/40, y/40); 

          tmart += 0.00051;
      }
    glEnd();

    glLoadIdentity();
    glRotatef(tjupt, 0 , 0, 1);
    glTranslatef( 0.223*scale, 0, 0);
    glScalef(scale, scale, 1);
    glBegin(GL_POLYGON); //jupiter
      for (float ang = 0; ang <= 2 * PI; ang += 0.01)
      {
          float x = cos(ang)* 0.07;
          float y = sin(ang)* 0.07;

          glColor3f(1.000, 0.894, 0.710);

          glVertex2f(x/3.5, y/3.5); 

          tjupt += 0.00028;
      }
    glEnd();

    glLoadIdentity();
    glRotatef(tsat, 0 , 0, 1);
    glTranslatef( 0.37*scale, 0, 0);
    glScalef(scale, scale, 1);
    glBegin(GL_POLYGON); //saturno
      for (float ang = 0; ang <= 2 * PI; ang += 0.01)
      {
          float x = cos(ang)* 0.07;
          float y = sin(ang)* 0.07;

          glColor3f(0.871, 0.722, 0.529);

          glVertex2f(x/5, y/5); 

      }
    glEnd();

    glLoadIdentity();
    glRotatef(tsat, 0 , 0, 1);
    glTranslatef( 0.37*scale, 0, 0);
    glScalef(scale, scale, 1);
    glLineWidth(3);
    glBegin(GL_LINES); // anel de saturno
      for (float ang = 0; ang <= 2 * PI; ang += 0.01)
      {
          float x = cos(ang)* 0.07;
          float y = sin(ang)* 0.07;

          glColor3f(0.8, 0.8, 0.8);

          glVertex2f(x/3.2, y/3.5); 
          glVertex2f(x/2.8, y/2.8);
          tsat += 0.0002;
      }
    glEnd();

    glLoadIdentity();
    glRotatef(turan, 0 , 0, 1);
    glTranslatef( 0.615*scale, 0, 0);
    glScalef(scale, scale, 1);
    glBegin(GL_POLYGON); //urano
      for (float ang = 0; ang <= 2 * PI; ang += 0.01)
      {
          float x = cos(ang)* 0.07;
          float y = sin(ang)* 0.07;

          glColor3f(0.000, 1.000, 1.000);

          glVertex2f(x/7, y/7); 

          turan += 0.00014;
      }
    glEnd();

    glLoadIdentity();
    glRotatef(tnet, 0 , 0, 1);
    glTranslatef( 0.97*scale, 0, 0);
    glScalef(scale, scale, 1);
    glBegin(GL_POLYGON); //netuno
      for (float ang = 0; ang <= 2 * PI; ang += 0.01)
      {
          float x = cos(ang)* 0.07;
          float y = sin(ang)* 0.07;

          glColor3f(0.118, 0.565, 1.000);

          glVertex2f(x/7, y/7); 

          tnet += 0.00011;
      }
    glEnd();


    glFlush();

    glutPostRedisplay(); 
    glutSwapBuffers(); 
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
    glutCreateWindow("Sistema Solar");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keypress);
    /* cor de fundo*/
    glClearColor(0, 0, 0, 1);

    for(int i = 0; i < 1000; i++)
    {
      posX[i] = ((float) rand() / (float) (RAND_MAX)) * 1.0;
    }

    for(int i = 0; i < 1000; i++)
    {
      posY[i] = ((float) rand() / (float) (RAND_MAX)) * 1.0;
    }
    /* interact … */
    glutMainLoop();
    return 0;
}

