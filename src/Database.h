//
// Created by mohamed-nagy on 27/12/23.
//

#ifndef SDL2TEST_DATABASE_H
#define SDL2TEST_DATABASE_H
#include <filesystem>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "game.h"
#include "snake.h"

namespace Database
{
    const std::string DATA_PATH = "src/database/data.txt";
    const std::string DATA_SETT_PATH = "src/database/settings.txt";

    void load(Snake& snake, Game& game);

    void save(Snake& snake, Game& game);

}


#endif //SDL2TEST_DATABASE_H
