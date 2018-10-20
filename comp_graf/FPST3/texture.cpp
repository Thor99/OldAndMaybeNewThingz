#ifdef _WIN32
#include <windows.h>
#define _USE_MATH_DEFINES
#endif
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "texture.h"
#include "Bitmap.h"

bool Texture::Load(const char* file)
{
    Bitmap bmp;
  	if(bmp.loadBMP(file))
  	{
  		glGenTextures(1, &m_texture); // Gera 1 textura vazia
        glBindTexture(GL_TEXTURE_2D, m_texture); // Comando que diz que mexeremos com a textura texture nos comandos abaixo
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); // Como deve esticar a imagem
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST); // Como deve reduzir a imagem
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bmp.width, bmp.height, 0,GL_RGB, GL_UNSIGNED_BYTE, bmp.data); // Carrega a imagem e joga pro openGL
        return true;
  	}
  	else
  	{
  		printf("Erro com a textura\n");
        return false;
  	}
}

void Texture::Use() const
{
    glBindTexture(GL_TEXTURE_2D, m_texture); // Comando que diz que mexeremos com a textura texture nos comandos abaixo

    // select modulate to mix texture with color for shading
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  // Modulate: cor = color * tex
  // Replace: cor = tex

    // if wrap is true, the texture wraps over at the edges (repeat)
    //       ... false, the texture ends at the edges (clamp)

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_wrap ? GL_REPEAT : GL_CLAMP ); // Se wrap for true, repetira a imagem, senão, finalizara na borda
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_wrap ? GL_REPEAT : GL_CLAMP ); // Se wrap for true, repetira a imagem, senão, finalizara na borda
}

void Texture::SetRepeat()
{
    m_wrap = false;
}

void Texture::SetWrap()
{
    m_wrap = true;
}