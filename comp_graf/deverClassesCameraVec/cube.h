#ifndef CUBE_H
#define CUBE_H

class Cube
{
public:
    Cube() = default;
    void Render() const;
private:
    void DrawSurface() const;
};

#endif