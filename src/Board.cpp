#include <math.h>
#include "Board.hpp"

Board::Board(int shift, int size, int spacer, int numOfDots, int numOfPlayers,
  Color dotColor, Color hlColor)
    : shift(shift), size(size), spacer(spacer), numOfDots(numOfDots), 
      numOfPlayers(numOfPlayers),dotColor(dotColor), hlColor(hlColor)
{}

void Board::Draw(SDL_Renderer *pRenderer)
{
  DrawLines(pRenderer);
  DrawDots(pRenderer);
  DrawHighlighter(pRenderer);
}

void Board::DrawDots(SDL_Renderer *pRenderer)
{
  SDL_SetRenderDrawColor(pRenderer, dotColor.r, dotColor.g, dotColor.b, dotColor.a);
  for (int i = 0; i < numOfDots; i++)
  {
    for (int j = 0; j < numOfDots; j++)
    {
      SDL_Rect rect{
          (int)round(shift + i * (size + spacer)),
          (int)round(shift + j* (size + spacer)),
          (int)round(size),
          (int)round(size)};
      SDL_RenderFillRect(pRenderer, &rect);
    }
  }
}

void Board::DrawHighlighter(SDL_Renderer *pRenderer) {
  SDL_SetRenderDrawColor(pRenderer, hlColor.r, hlColor.g, hlColor.b, hlColor.a);
  double col = (mouseMotionX - 30) / 60.0;
  double extraCol = col - (int)col;
  double row = (mouseMotionY - 30) / 60.0;
  double extraRow = row - (int)row;
  if (col > numOfDots -1 || row > numOfDots -1) {
    return;
  }
  if (extraCol < 0.2) {
    if (extraRow < 0.2 || extraRow > 0.8) {
      return;
    }
    SDL_Rect rect{ shift + (int)col * (spacer + size), shift + (int)row * (spacer + size), size, size + spacer};
    SDL_RenderFillRect(pRenderer, &rect);
  } else if (extraCol > 0.8) {
    if (extraRow < 0.2 || extraRow > 0.8) {
      return;
    }
    SDL_Rect rect{ shift + (int)(col + 1) * (spacer + size), shift + (int)row * (spacer + size), 
      size, size + spacer};
    SDL_RenderFillRect(pRenderer, &rect);
  }
  if (extraRow < 0.2) {
    SDL_Rect rect{ shift + (int)col * (spacer + size), shift + (int)row * (spacer + size), size + spacer, size};
    SDL_RenderFillRect(pRenderer, &rect);
  } else if (extraRow > 0.8) {
    SDL_Rect rect{ shift + (int)col * (spacer + size), shift + (int)(row + 1) * (spacer + size), size + spacer,
      size};
    SDL_RenderFillRect(pRenderer, &rect);
  }
}

void Board::DrawLines(SDL_Renderer *pRenderer) {
  // for (linesRows)
}