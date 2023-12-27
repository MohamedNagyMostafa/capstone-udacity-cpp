//
// Created by mohamed-nagy on 27/12/23.
//

#ifndef SDL2TEST_BORDER_H
#define SDL2TEST_BORDER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <future>
#include <thread>

#include "StaticObstacle.h"
class Border {

public:
    Border(Color color, std::size_t gridWidth, std::size_t gridHeight): _gridHeight(gridHeight), _gridWidth(gridWidth), _color(color)
    {
        init();
    };

    void render(SDL_Renderer*, SDL_Rect&);

    bool BorderCell(int& x, int& y)
    {
        return std::any_of(_borders.begin(), _borders.end(), [&x, &y](StaticObstacle&  staticObstacle){
            return staticObstacle.ObstacleCell(x, y);
        });
    }

private:
    std::vector<StaticObstacle> _borders;
    std::vector<std::future<void>> _futures;

    Color _color;
    std::size_t _gridWidth;
    std::size_t _gridHeight;

    void init();
};


#endif //SDL2TEST_BORDER_H
