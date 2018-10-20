#include "STLModel.h"
#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"

bool STLModel::Load(const char * filename)
{
    FILE* f = fopen(filename, "rb");
    if (f == nullptr)
    {
        return false;
    }

    char solidHeader[80];
	unsigned int nOfFacets;
	fscanf(f, "%80c%4c", solidHeader, &nOfFacets);
    for (int i = 0; i <= nOfFacets; i++)
    {
        while (ReadFacet(f));
    }

    fclose(f);

    return true;
}

bool STLModel::ReadFacet(FILE * f)
{
    Facet facet;
    // Ler normal
    if (fscanf(f, "%4c%4c%4c", &facet.normal.x, &facet.normal.y, &facet.normal.z) != 3)
    {
        return false;
    }

    // Ler vértice 1
    if (fscanf(f, "%4c%4c%4c", &facet.v1.x, &facet.v1.y, &facet.v1.z) != 3)
    {
        return false;
    }

    // Ler vértice 2
    if (fscanf(f, "%4c%4c%4c", &facet.v2.x, &facet.v2.y, &facet.v2.z) != 3)
    {
        return false;
    }

    // Ler vértice 3
    if (fscanf(f, "%4c%4c%4c", &facet.v3.x, &facet.v3.y, &facet.v3.z) != 3)
    {
        return false;
    }

    // Ler 2 bytes
    if (fseek(f, 2, SEEK_CUR) != 0)
    {
        return false;
    }

    m_facets.push_back(facet);

    return true;
}

void STLModel::Draw() const
{   
    glBegin(GL_TRIANGLES);
    for (auto it = m_facets.begin(); it != m_facets.end(); ++it)
    {
        glNormal3f(it->normal.x, it->normal.y, it->normal.z);
        glVertex3f(it->v1.x, it->v1.y, it->v1.z);
        glVertex3f(it->v2.x, it->v2.y, it->v2.z);
        glVertex3f(it->v3.x, it->v3.y, it->v3.z);
    }
    glEnd();
}