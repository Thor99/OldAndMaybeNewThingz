#ifndef STLMODEL_H
#define STLMODEL_H

#include "vec3d.h"
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class STLModel
{
    struct Facet
    {
        Vec3D normal;
        Vec3D v1;
        Vec3D v2;
        Vec3D v3;
    };

public:

    bool Load(const char* filename);
    void Draw() const;

private:

    bool ReadFacet(FILE* f);

    vector<Facet> m_facets;
};

#endif