#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "cube.h"
#include "snake.h"
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

Snake::Snake()
{

}

void Snake::AddBlock(float x, float z)
{
    if (find(m_cubos.begin(), m_cubos.end(), Point2D{ x, z }) == m_cubos.end()) // Não existe um cubo nessa posição
    {
        m_cubos.push_back(Point2D{ x, z });
    }
}

bool Snake::Exists(float x, float z)
{
    if (find(m_cubos.begin(), m_cubos.end(), Point2D{ x, z }) == m_cubos.end())
    {
        return false;
    }

    return true;
}

void Snake::Render() const
{
    Cube cube;
    for (auto it = m_cubos.begin(); it != m_cubos.end(); ++it) {
        glPushMatrix();
        glTranslatef((*it).x, 0, (*it).z);
        cube.Render();
        glPopMatrix();
    }
}

void Snake::GenerateBorders()
{
	Cube cube;
  	for (int z = -10; z <=10; z++)
	{
      	glPushMatrix();
        glTranslatef(-10, 0, z);
        cube.Render();
        glPopMatrix();
	}
    for (int z = -10; z <=10; z++)
	{
		glPushMatrix();
        glTranslatef(10, 0, z);
        cube.Render();
        glPopMatrix();
	}
    for(int x = -10; x <= 10; x++)
	{
		glPushMatrix();
        glTranslatef(x, 0, -10);
        cube.Render();
        glPopMatrix();
	}
    for(int x = -10; x <= 10; x++)
    {
        glPushMatrix();
        glTranslatef(x, 0, 10);
        cube.Render();
        glPopMatrix();
    }
}
void Snake::GenerateSnake()
{
	m_cubos.push_back(Point2D{ 0, 0 });
  	m_cubos.push_back(Point2D{ 0, -1 });
	m_cubos.push_back(Point2D{ 0, -2 });

}

void Snake::GenerateFood(float x, float z)
{
    if(x == 100 && z == 100)
    {
        x = rand() % 18 + 1;
        z = rand() % 18 + 1;
        x -= 10;
        z -= 10;
        m_cubos.push_back(Point2D{x, z});
    }
    else
    {
        m_cubos.push_back(Point2D{x, z});
    }
}

bool Snake::CheckFood(float xFood, float zFood)
{
    auto it = m_cubos.begin();
    if( (*it).x >= xFood && (*it).x <= xFood - 1 && (*it).z >= zFood && (*it).z <= zFood + 1  )
    {
        return true;
    }
}
void Snake::TurnLeft()
{
    if(!goingRight)
    {
        auto it = m_cubos.begin();
        if(goingUp)
        {
          (*it).x += 1;
          //(*it).z -= 1;
        }
        else if(goingDown)
        {
          (*it).x += 1;
          //(*it).z += 1;
        }
        goingLeft = true;
        goingRight = false;
        goingUp = false;
        goingDown = false;
    }
}

void Snake::TurnRight()
{
    if(!goingLeft)
    {
        auto it = m_cubos.begin();
        if(goingUp)
        {
          (*it).x -= 1;
          //(*it).z -= 1;
        }
        else if(goingDown)
        {
          (*it).x -= 1;
          //(*it).z += 1;
        }
        goingLeft = false;
        goingRight = true;
        goingUp = false;
        goingDown = false;
    }
}

void Snake::TurnUp()
{
  if(!goingDown)
  {
    auto it = m_cubos.begin();
    if(goingRight)
    {
      //(*it).x += 1;
      (*it).z += 1;
    }
    else if(goingLeft)
    {
      //(*it).x -= 1;
      (*it).z += 1;
    }
    goingLeft = false;
    goingRight = false;
    goingUp = true;
    goingDown = false;
  }
}

void Snake::TurnDown()
{
  if(!goingUp)
  {
    auto it = m_cubos.begin();
    if(goingRight)
    {
       //(*it).x += 1;
       (*it).z -= 1;
    }
    else if(goingLeft)
    {
      //(*it).x -= 1;
      (*it).z -= 1;
    }
    goingLeft = false;
    goingRight = false;
    goingUp = false;
    goingDown = true;
  }
}

void Snake::Move()
{
    auto it = m_cubos.begin();

    int xAnterior =  (*it).x;
    int zAnterior = (*it).z;
    int xTemp;
    int zTemp;


    if(goingRight)
    {
        (*it).x -= 1;
    }
    else if(goingLeft)
    {
        (*it).x += 1;
    }
    else if(goingUp)
    {
        (*it).z += 1;
    }

    else if(goingDown)
    {
        (*it).z -= 1;
    }

    for(it = m_cubos.begin()+1; it != m_cubos.end(); ++it)
    {
        xTemp = (*it).x;
        zTemp = (*it).z;
        (*it).x = xAnterior;
        (*it).z = zAnterior;
        xAnterior = xTemp;
        zAnterior = zTemp;
    }
}