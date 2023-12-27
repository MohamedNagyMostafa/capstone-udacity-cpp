#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "Border.h"
#include <memory>

class Game {
 public:
    Game(std::size_t grid_width, std::size_t grid_height);
    ~Game();
    // Copy
    Game(Game const& source)
    {
        snake   = std::unique_ptr<Snake>(source.snake.get());
        border  = std::unique_ptr<Border>(source.border.get());
        food    = source.food;
        score   = source.score;
    }
    Game& operator=(Game const& source)
    {
        snake   = std::unique_ptr<Snake>(source.snake.get());
        border  = std::unique_ptr<Border>(source.border.get());
        food    = source.food;
        score   = source.score;

        return *this;
    }
    //Move
    Game(Game&& source)
    {
        snake   = std::unique_ptr<Snake>(std::move(source.snake.release()));
        border  = std::unique_ptr<Border>(std::move(source.border.release()));
        food    = source.food;
        score   = source.score;
    }
    Game& operator=(Game&& source)
    {
        snake   = std::unique_ptr<Snake>(std::move(source.snake.release()));
        border  = std::unique_ptr<Border>(std::move(source.border.release()));
        food    = source.food;
        score   = source.score;

        return *this;
    }

    void Run(Controller const& controller, Renderer& renderer,
           std::size_t target_frame_duration);
    int GetScore() const;
    void SetScore(int score){ this->score = score;};
    int GetSize() const;

 private:
    std::unique_ptr<Snake> snake;
    std::unique_ptr<Border>border;
    SDL_Point food;

    std::random_device dev;
    std::mt19937 engine;
    std::uniform_int_distribution<int> random_w;
    std::uniform_int_distribution<int> random_h;

    int score{0};

    void PlaceFood();
    void Update();
};

#endif