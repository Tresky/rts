// Compile: g++ -std=c++11 -Wall -Wextra -pedantic main.cpp
// Linking: g++ -std=c++11 -Wfatal-errors main.o src/tile_engine/* src/engine/* extlibs/TinyXML/tinyxml2.cpp -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

#include <iostream>

#include <SFML/Graphics.hpp>

#include "inc/engine/engine.h"

using namespace std;

int main()
{
  Engine engine;

  engine.Run();

  cin.get();
  return 0;
}