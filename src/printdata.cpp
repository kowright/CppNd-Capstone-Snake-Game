#include "printdata.h"
#include <iostream>
#include <string>
#include <chrono>
#include <functional>
#include <unistd.h>
#include <fstream>
#include "SDL.h"

//my code below

//score and size format
void PrintData::PrintFormat(std::string string, int64_t i)
{
  if ( i == 1)
  {
   std::cout << _time << i << " second" << "\n";
  }
  else if (i > 1)
  {
  std::cout << _time << i << " seconds" << "\n";
  }
 
}

//time format
void PrintData::PrintFormat(std::string string, int i)
{
  std::cout << string << i << "\n";
}

//player input for name
void PrintData::SetPlayerName()
{
  std::string _name;
  std::cout << "Welcome to the Snake Game! What is your name?" << "\n";
  std::cin >> _name;
  std::cout << "Hi " << _name << ", let's start the game! Good Luck!" << "\n";
  sleep(3);

  _playername= std::move(_name);
}

//retrieve player name
std::string PrintData::GetPlayerName(){ return _playername;}

//create csv file if player wants it 
void PrintData::PrintCSV(int csvScore, int csvSize, int64_t csvTime)
{
  std::string answer;
  std::cout << "Would you like a file of your scores? Type yes or no" << "\n";
  std::cin >> answer;

  if (answer == "yes")
  {
  std::cout << "You chose to receive a file of your scores." <<"\n";
  std::ofstream csvFile("SnakeGameScore.csv");
  csvFile << _score << csvScore << "\n";
  csvFile << _size << csvSize << "\n";
  csvFile << _time << csvTime << "\n";
  std::cout << "Thanks for playing!" <<"\n";
  }
  else 
  {
    std::cout << "You chose not to receive a file of your scores." <<"\n";
    std::cout << "Thanks for playing!" <<"\n";
  }
}