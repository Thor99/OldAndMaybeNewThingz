#include "media.h"

Media::Media()
{
    m_1 = 0;
    m_2 = 0;
    m_3 = 0;
}

Media::Media(float a,float b, float c)
{
    m_1=a;
    m_2=b;
    m_3=c;
}

float Media::Calcula()
{
    return (m_1 + m_2 + m_3) / 3.0;
}

void Media::SetValues(float a, float b, float c)
{
    m_1 = a;
    m_2 = b;
    m_3 = c;
}
