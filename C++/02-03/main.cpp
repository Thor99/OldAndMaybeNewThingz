#include "media.h"
#include <stdio.h>

int main()
{
    float x;
    float y;
    float z;
    float r;
    float s;
    float t;

    scanf("%f%f%f", &x, &y, &z);
    scanf("%f%f%f", &r, &s, &t);

    Media m1 = Media(); // Media::Media()
    float v1 = m1.Calcula();

    Media m2(x, y, z); // Media::Media(float a,float b, float c)
    float v2 = m2.Calcula();

    m2.SetValues(r, s, t); // void Media::SetValues(float a, float b, float c)
    float v3 = m2.Calcula();

    printf("%f\n%f\n%f\n", v1, v2, v3);
}
