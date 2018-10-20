#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"
#include "cube.h"
#include "maze.h"
#include <vector>
#include <algorithm>

using namespace std;

Maze::Maze()
{

}

void Maze::AddBlock(float x, float z)
{
    if (find(m_cubos.begin(), m_cubos.end(), Point2D{ x, z }) == m_cubos.end()) // Não existe um cubo nessa posição
    {
        m_cubos.push_back(Point2D{ x, z });
    }
}

void Maze::RemoveBlock(float x, float z)
{
    auto it = find(m_cubos.begin(), m_cubos.end(), Point2D{ x, z });
    if (it != m_cubos.end())
    {
        m_cubos.erase(it);
    }
}

bool Maze::Exists(float x, float z)
{
    if (find(m_cubos.begin(), m_cubos.end(), Point2D{ x, z }) == m_cubos.end())
    {
        return false;
    }

    return true;
}

void Maze::Render() const
{
    Cube cube;
    for (auto it = m_cubos.begin(); it != m_cubos.end(); ++it) {
        glPushMatrix();
        glTranslatef((*it).x, 0, (*it).z);
        cube.Render();
        glPopMatrix();
    }
}
