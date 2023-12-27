# CPPND: Capstone Snake Game

This is the capstone project of Udacity [C++ Nanodegree](https://www.udacity.com/enrollment/nd213/3.4.8). 

<img src="https://github.com/MohamedNagyMostafa/capstone-udacity-cpp/assets/20774864/66e5b3c0-47b2-42aa-9069-4712c0aa58eb" width="380">

## Features:
The additional features have been added to the project as follows:
1. Set up static obstacles in the Snake environment. (Borders)
2. The software automatically saves and restores the last state of the game after termination.

## Project Rubric:
### (1) Loops, Functions, I/O
* `The project demonstrates an understanding of C++ functions and control structures.`, `The project reads data from a file and process the data, or the program writes data to a file.`, `The project uses data structures and immutable variables.`: When the software terminates, the software writes Snake's `body` and `head` points into `database/data.txt` file as well as the Game's Settings, like snake's `speed`, `direction`,  and user's `score`, into `database/settings.txt` file. In the process, if the snake is dead, no data is stored, and previous data are cleared.
When the software is relaunching, it loads data from these files. It will launch the game in the initial state if they do not have data. 
Relevant files: `src/Database.h`, `src/Database.cpp`.

### (2) Object Oriented Programming
* `One or more classes are added to the project with appropriate access specifiers for class members.`: `Database.h`, `Obstacle.h`, `StaticObstacle.h`, and `Border.h` classes have been added to the project. Obstacle is defined by cell points `std::vector<SDL_Point>`, shape `Shape:enum(Vertical|Horizontal)`, size `size_t`, and center position `Pose:struct(x,y)`. Some data members are `protected` to be accessed only by child classes like `StaticObstacle` class.

*  `Class constructors utilize member initialization lists.`: All member variables have been initialized through constructors as shown in classes `Obstacle.h`, `StaticObstacle.h`, and `Border.h`.

* `Classes follow an appropriate inheritance hierarchy with virtual and override functions.`: Since obstacles are expected to be vary in shape and while rendering, `Obstacle.h` class has `virtual void render(SDL_Renderer*, SDL_Rect&)` and `virtual void constructBody()` as virtual functions to be overridden on the child class to work according to the target obstacle. For instance, `StaticObstacle.h` class overrides `void constructBody()` to construct obstacles in either vertical or horizontal shapes.

### (3) Memory Management
* `The project makes use of references in function declarations.`: There are plenty of functions/methods that use pass-by-reference such as `bool ObstacleCell(int& x, int& y)` in file `Obstacle.h`, `void StaticObstacle::render(SDL_Renderer* sdlRenderer, SDL_Rect& block)` in file `StaticObstacle.cpp`.
* `The project uses destructors appropriately.`: One of the best practices of using destructors in the project has been done while saving the game state before termination. As shown in the destructor of the `Game.h` class, the software stores the data in the files once the class's destructor is called as an indication of termination of the software.
* `The project uses smart pointers instead of raw pointers.`, `The project uses move semantics to move data instead of copying it, where possible.`: Inside `Game` class, we use **unique** smart pointers to handle memory allocation of `Snake` and `Border` objects, where the pointer has been initialized and moved semantically in the constructor.
* `The project follows the Rule of 5.`: Rule of five has been considered for classes like `Game`.

### (4) Concurrency
* `The project uses multithreading.`, `A promise and future is used in the project`, `A mutex or lock is used in the project.`: Since rendering data on screen one of the heavy processes, we render the border obstacles using multi-tasking. As shown at `Border::render(SDL_Renderer* sdlRenderer, SDL_Rect& block)` in `Border.cpp`, each border has been rendered in a separate thread asynchronously with other borders. Since `sdlRenderer` is a shared resource between the threads, we assign a lock guard, check line 22 in `StaticObstacle.cpp` file, to lock the resource while rendering a cell of the border. 

In summary, a border (`Border.h`) is **a side** of the environment that represents a static obstacle (`StaticObstacle.h`), which is a form of obstacle (`Obstacle.h`). We handle food placement and snakehead/body not to be placed within a cell belonging to an obstacle. As shown in the screenshot above, the user loses of the snake head hits any obstacle in the environment, borders in this case. 

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
