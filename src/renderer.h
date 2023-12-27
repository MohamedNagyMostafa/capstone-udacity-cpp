#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"
#include "Border.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  // Copy
  Renderer(Renderer& source): screen_width(source.screen_width), screen_height(source.screen_height),
    grid_width(source.grid_width), grid_height(source.grid_height), sdl_window(source.sdl_window), sdl_renderer(source.sdl_renderer){};

  // Move
  Renderer(Renderer&& source): screen_width(source.screen_width), screen_height(source.screen_height),
  grid_width(source.grid_width), grid_height(source.grid_height)
  {
      sdl_window    = source.sdl_window;
      sdl_renderer  = source.sdl_renderer;

      source.sdl_window     = nullptr;
      source.sdl_renderer   = nullptr;
  }

  void Render(Snake const snake, SDL_Point const &food, Border& border);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif