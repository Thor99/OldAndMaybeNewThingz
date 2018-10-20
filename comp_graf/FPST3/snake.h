#ifndef SNAKE_H
#define SNAKE_H
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

class Snake
{
public:
    Snake();
    void AddBlock(float x, float y);

    bool Exists(float x, float y);

    void GenerateBorders();

    void Render() const;

    void GenerateSnake();

	void GenerateFood(float x, float z);

	bool CheckFood(float xFood,float zFood);

    void TurnRight();

  	void TurnLeft();

  	void TurnUp();

  	void TurnDown();

  	void Move();

private:
    vector<Point2D> m_cubos;

    bool goingLeft = false;
  	bool goingRight = false;
  	bool goingUp = true;
  	bool goingDown = false;
};

#endif