#ifndef GAME_H
#define GAME_H

#include <random>
#include <chrono>
#include <string>
#include <functional>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include "printdata.h"

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  ~Game();
  int GetScore() const;
  int GetSize() const;
  //my code below
  int64_t GetTime() const; 
  void PrintEndData();
  void PrintFormat(std::string string, int i);
  void PrintFormat(std::string string, int64_t i);
  //my code above

 private:
  Snake snake;
  SDL_Point food;
  
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  //my code below
  PrintData printdata;
  std::string _score = "Score: ";
  std::string _size = "Size: ";
  std::string _time = "Time: ";

  std::chrono::high_resolution_clock::time_point t1;
  std::chrono::high_resolution_clock::time_point t2;
  //my code above
  void PlaceFood();
  void Update();
};

#endif