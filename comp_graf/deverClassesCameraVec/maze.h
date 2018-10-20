#ifndef MAZE_H
#define MAZE_H
#include <vector>

using namespace std;

struct Point2D
{
    float x;
    float z;

    bool operator == (Point2D p2)
    {
        return x == p2.x && z == p2.z;
    }
};

class Maze
{
public:
    Maze();
    void AddBlock(float x, float y);
    void RemoveBlock(float x, float y);

    bool Exists(float x, float y);

    void Render() const;
private:
    vector<Point2D> m_cubos;
};

#endif
