#pragma once

#include "Color.hpp"
#include "SDL.h"
#include <vector>

class Board
{
public:
  Board(int shift, int size, int spacer, int numOfDots, int numOfPlayers, 
    Color dotDolor, Color hlColor);
  void Draw(SDL_Renderer *pRenderer);

  std::vector< Color > playerColors;
  int numOfPlayers = 0;
  int mouseMotionX = 0;
  int mouseMotionY = 0;
  int linesRows[9][10] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0
  };
  int linesCols[10][9] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0
  };

private:
  void DrawDots(SDL_Renderer *pRenderer);
  void DrawHighlighter(SDL_Renderer *pRenderer);
  void DrawLines(SDL_Renderer *pRenderer);

  int shift;
  int size;
  int spacer;
  int numOfDots;
  Color dotColor;
  Color hlColor;
};