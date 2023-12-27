//
// Created by mohamed-nagy on 26/12/23.
//

#ifndef SDL2TEST_STATICOBSTACLE_H
#define SDL2TEST_STATICOBSTACLE_H

#include "Obstacle.h"
#include <mutex>
#include <algorithm>

class StaticObstacle : public Obstacle {
public:
    StaticObstacle(Pose center, Shape shape, int size):
    Obstacle(center, shape, size) { init();};
    void render(SDL_Renderer*, SDL_Rect&) override;
    void init(){ constructBody();}
private:
    static std::mutex _mutex;
    void constructBody() override;
};


#endif //SDL2TEST_STATICOBSTACLE_H
