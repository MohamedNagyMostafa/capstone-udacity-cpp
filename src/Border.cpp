//
// Created by mohamed-nagy on 27/12/23.
//

#include "Border.h"

void Border::init()
{
    // Vertical Border.
    Pose leftBorder{0,static_cast<int>(_gridHeight/2) };
    _borders.emplace_back(leftBorder, _color, Shape::Vertical, _gridHeight, _gridWidth, _gridHeight);

    Pose rightBorder{static_cast<int>(_gridWidth) - 1, static_cast<int>(_gridHeight/2)};
    _borders.emplace_back(rightBorder, _color, Shape::Vertical, _gridHeight, _gridWidth, _gridHeight);

    // Horizontal Border
    Pose topBorder{static_cast<int>(_gridWidth/2), 0};
    _borders.emplace_back(topBorder, _color, Shape::Horizontal, _gridWidth, _gridWidth, _gridHeight);

    Pose bottomBorder{static_cast<int>(_gridWidth/2), static_cast<int>(_gridHeight) - 1};
    _borders.emplace_back(bottomBorder, _color, Shape::Horizontal, _gridWidth, _gridWidth, _gridHeight);
}

void Border::render(SDL_Renderer* sdlRenderer, SDL_Rect& block)
{
    SDL_SetRenderDrawColor(sdlRenderer, _color.red, _color.green, _color.blue, 0xFF);

    std::for_each(_borders.begin(), _borders.end(), [sdlRenderer, &block, this](StaticObstacle& staticObstacle){
        this->_futures.emplace_back(std::async(std::launch::async, &StaticObstacle::render, std::ref(staticObstacle), sdlRenderer, std::ref(block)));
    });

    std::for_each(_futures.begin(), _futures.end(), [](const std::future<void> &future){ future.wait();});
}
