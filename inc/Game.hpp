#pragma once

#include <vector>
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "SDL.h"
#include "World.hpp"

class Game
{
public:
  Game();

private:
  void Finalize();
  bool Initialize();
  void InitializeModel();
  bool InitializeView();
  void RunController();
  void RunModel();
  void RunView();
  void Run();

  bool isRunning = true;
  Player player = Player(0, 0, 50, 50, Color{0, 0, 255, 255});
  World world = World(800, 600, Color{0, 150, 175, 255});
  Board board = Board(25, 10, 50, 10, 2, Color{255, 255, 255, 255}, Color{255, 255, 0, 255});
  SDL_Window *pWindow = nullptr;
  SDL_Renderer *pRenderer = nullptr;
  Uint32 ticksCount = 0;
};