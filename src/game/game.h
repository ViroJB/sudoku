#pragma once

#include <vector>
#include "generator/generator.h"

class Game {
   public:
    Game();
    std::vector<std::vector<int>> *getBoard();
    int getBoardSize();
    void resetBoard();
    void setNode(int x, int y, int value);
    void setBoardSize(int size);
    void createFilledOutBoard();

   private:
    std::vector<std::vector<int>> _board;
    int _boardSize = 9;
};