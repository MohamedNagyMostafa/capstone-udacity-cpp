//
// Created by mohamed-nagy on 26/12/23.
//

#include "StaticObstacle.h"

void StaticObstacle::constructBody()
{
    if(_shape == Shape::Vertical)
        for(int i = _pose.y - _size/2; i < _pose.y + _size/2; i++)
            _body.emplace_back(SDL_Point{_pose.x, i});

    if(_shape == Shape::Horizontal)
        for(int i = _pose.x - _size/2; i < _pose.x + _size/2; i++)
            _body.emplace_back(SDL_Point{i, _pose.y});
}

void StaticObstacle::render(SDL_Renderer* sdlRenderer, SDL_Rect& block)
{
    std::for_each(_body.begin(), _body.end(), [&block, &sdlRenderer](SDL_Point point)
    {
        std::unique_lock<std::mutex> ulock(_mutex);
        block.x = block.w * point.x;
        block.y = block.h * point.y;
        SDL_RenderFillRect(sdlRenderer, &block);

    });
}

std::mutex StaticObstacle::_mutex;
