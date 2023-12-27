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


class Obstacle {

public:
    Obstacle(Pose center, Shape shape, int size): _pose(center),
    _shape(shape), _size(size){};

    bool ObstacleCell(int& x, int& y) {

        return std::any_of(_body.begin(), _body.end(), [&x, &y](SDL_Point& point){
            return (x == point.x && y == point.y);
        });

    };

    virtual void render(SDL_Renderer*, SDL_Rect&) = 0;

protected:
    std::vector<SDL_Point> _body;
    Pose _pose;     // Center
    Shape _shape;
    size_t _size;

    virtual void constructBody() = 0;

};



#endif //SDL2TEST_OBSTACLE_H
