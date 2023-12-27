//
// Created by mohamed-nagy on 27/12/23.
//
#include "Database.h"

void Database::load(Snake& snake, Game& game)
{
    std::ifstream file( std::filesystem::current_path().parent_path().append(DATA_PATH));
    std::ifstream fileSettings( std::filesystem::current_path().parent_path().append(DATA_SETT_PATH));

    if(file.is_open() && fileSettings.is_open())
    {
        std::string line;

        // Snake head
        std::getline(file, line);
        std::istringstream istringstream(line);

        if(line.empty())
        {
            std::cout <<" No data "<<std::endl;
            file.close();
            fileSettings.close();
            return;
        }

        istringstream >> snake.head_x;
        istringstream >> snake.head_x;

        // Snake body
        while(std::getline(file, line))
        {
            std::istringstream istringstream(line);
            SDL_Point point;

            istringstream >> point.x >> point.y;

            snake.body.emplace_back(point);
        }

        snake.size = snake.body.size() + 1;

        file.close();

        // Speed & Score
        std::getline(fileSettings, line);
        std::istringstream istringstreamSett(line);
        istringstreamSett >> snake.speed;
        int dir;
        istringstreamSett >> dir;
        snake.direction = static_cast<Snake::Direction>(dir);
        int score;
        istringstreamSett >> score;
        game.SetScore(score);

    }


}


void Database::save(Snake& snake, Game& game)
{
    std::ofstream file( std::filesystem::current_path().parent_path().append(DATA_PATH));
    std::ofstream fileSett( std::filesystem::current_path().parent_path().append(DATA_SETT_PATH));

    if(!snake.alive)
    {
        file.clear();
        fileSett.clear();
        file.close();
        fileSett.close();
        return;
    }
    if(file.is_open() && fileSett.is_open())
    {
        file << snake.head_x <<" " << snake.head_y << "\n";

        std::for_each(snake.body.begin(), snake.body.end(), [&file](SDL_Point& point){file << point.x <<" " << point.y <<"\n";});
        file.close();

        fileSett << snake.speed << " " << snake.direction << " " << game.GetScore();

        fileSett.close();
    }
}