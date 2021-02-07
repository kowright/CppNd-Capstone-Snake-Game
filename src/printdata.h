#ifndef PRINTDATA_H
#define PRINTDATA_H

#include <random>
#include <chrono>
#include <string>
#include <functional>
#include <fstream>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
//my code below

//class to format items printed to console
class PrintData
{
public: 
void PrintFormat(std::string string, int i);
void PrintFormat(std::string string, int64_t i);
void PrintCSV(int csvScore, int csvSize, int64_t csvTime);

void SetPlayerName();
std::string GetPlayerName();

private:
std::string _score = "Score: ";
std::string _size = "Size: ";
std::string _time = "Time: ";

std::string _playername = "Player";

};

#endif