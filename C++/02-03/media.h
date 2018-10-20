#ifndef MEDIA_H
#define MEDIA_H

class Media
{
    public:
        Media();
        Media(float a, float b, float c);
        float Calcula();
        void SetValues(float a, float b, float c);
    private:
        float m_1;
        float m_2;
        float m_3;
};

#endif
