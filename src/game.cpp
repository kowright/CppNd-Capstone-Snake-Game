#include "game.h"
#include <iostream>
#include <string>
#include <chrono>
#include <functional>
#include "SDL.h"


Game::Game(std::size_t grid_width, std::size_t grid_height)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width)),
      random_h(0, static_cast<int>(grid_height)) {
  PlaceFood();
}

Game::~Game() {   
  std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;
  int64_t duration = 0;
  int64_t timelength = 0;
  //my code below
  t1 = std::chrono::high_resolution_clock::now();
  //my code above
  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      t2 = std::chrono::high_resolution_clock::now();
      timelength = (std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count())/1000000; // convert time to seconds
      if (timelength < 1)
      {
      timelength = 0;
      }

      renderer.UpdateWindowTitle(score, frame_count, timelength);
      frame_count = 0;
      

      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
  //my code below
   t2 = std::chrono::high_resolution_clock::now();
   //my code above
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item before placing
    // food.
    if (!snake.SnakeCell(x, y)) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::Update() {
  if (!snake.alive)
  {
    return;
  }
  snake.Update();

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food where the head is 
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake and increase speed.
    snake.GrowBody();
    snake.speed += 0.02;
  }
}

//my code below

int Game::GetScore() const { return score; }

int Game::GetSize() const { return snake.size;}

int64_t Game::GetTime() const
{
    auto duration = (std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count())/1000000; // convert time to seconds
    
    if (duration < 1)
    {
      return 0;
    }
    return duration;
 }


//print the ending score, snake size and time length of game
void Game::PrintEndData()
{ 
std::cout << "Game has terminated successfully!\n";
int _endscore = GetScore();
int _snakesize = GetSize();
int64_t _gametime = GetTime();

std::cout << printdata.GetPlayerName() << " got the following stats: " << "\n";

printdata.PrintFormat(_score, _endscore);
printdata.PrintFormat(_size, _snakesize);
printdata.PrintFormat(_time, _gametime);

printdata.PrintCSV(_endscore, _snakesize, _gametime);

}



