# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## Code Structure

The code has the following modules: 
* Controller: Allows user to use their keyboard to control the snake inside the game. 
* Game: Controls the state of the game.
* PrintData: Formats outputs to the console and I/O from the user.
* Renderer: Renders the game using SDL library. 
* Snake: Controls how snake moves and grows inside the game. 

## Rubric Submission Compliance
* REQUIRED: 
  * README with instructions, chosen project, rubric points addressed and runs. 
* Loops, Functions, I/O
  * project demonstates an understanding of C++ functions and control structures. 
    * This code contains functions, methods, for/if loops, classes, initializations, declarations and other fundamental C++ concepts. 
  * project reads data from a file and process the data or the program writes data to a file
    * This code writes data to a file in the PrintData class.
  * project accepts user input and processes the input
    * This code accepts user data and uses it to display data to the user.
* Object Oriented Programming
  *program uses Object Oriented Programming techniques
    * This code uses OOP in the forms of classes, acess modifiers, encapsulation, abstrations abnd others.
  * classes use appropriate access specifiers for class members
    * This code edits the starter repo class members and with the custom class PrintData, access modifiers are used. 
  * classes abstract implementation details from their interfaces
    * This code is self documenting and has comments to describe why/how they work. 
  * classes encapsulate behavior
    * This code has classes and function grouped together in the code or within classes.
  * overloaded functions allow the same function to operate on different parameters
    * This code has an overloaded function in the PrintData class. 
* Memory Management
  * project uses destructors appropriately
    * This code uses destructors to initialize variables that are needed for displaying to the user their scores for the game when the game is finished.
  * project uses move semantics to move data, instead of copying it, where possible
    * this project uses move semantics in the PrintData class to deal with user input.