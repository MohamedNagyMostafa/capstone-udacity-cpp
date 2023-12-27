//
// Created by mohamed-nagy on 26/12/23.
//

#ifndef SDL2TEST_OBSTACLE_H
#define SDL2TEST_OBSTACLE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "SDL.h"



struct Color
{
    int red, green, blue;
};

enum Shape{ Vertical, Horizontal};

struct Pose
{
    int x, y;
};

struct ScreenGridRatio
{
    int dx;
    int dy;
};

class Obstacle {

public:
    Obstacle(Pose center, Color color, Shape shape, int size, int gridWidth, int gridHeight): _pose(center), _color(color),
    _shape(shape), _size(size), _gridWidth(gridWidth), _gridHeight(gridHeight){std::cout<< "static obstacle is generated at: " << center.x << ", "<< center.y << " color " << color.red << ", " << color.green<<std::endl;};

    bool ObstacleCell(int& x, int& y) {

        return std::any_of(_body.begin(), _body.end(), [&x, &y](SDL_Point& point){
            return (x == point.x && y == point.y);
        });

    };

    virtual void render(SDL_Renderer*, SDL_Rect&) = 0;

protected:
    std::vector<SDL_Point> _body;
    Pose _pose;     // Center
    Color _color;
    Shape _shape;
    size_t _size;

    bool isFeasible(const Pose& pose) const{ return (pose.x >= 0 && pose.x <= _gridWidth) && (pose.y >= 0 && pose.y <= _gridHeight);};

    virtual void constructBody() = 0;

private:

    int _gridWidth;
    int _gridHeight;


};



#endif //SDL2TEST_OBSTACLE_H
