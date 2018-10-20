#ifndef TEXTURE_H
#define TEXTURE_H
#include "GL/gl.h"
#include "GL/glu.h"
#include "GL/glut.h"

class Texture
{
public:
    Texture() = default;
    bool Load(const char* file);

    void Use() const;

    void SetRepeat();
    void SetWrap();

private:
    GLuint m_texture;
    bool m_wrap = true;
};

#endif