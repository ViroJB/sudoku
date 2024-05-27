#include "game.h"

// TODO create a filled out sudoku board
// only one solution should be possible
// 1-9 in each row, column, and 3x3 grid
// first add the "1" to each 3x3 grid so they dont overlap, then 2-9

// TODO choose which numbers to show to make the game playable (huh?)
// TODO on input check if the number is even possible in that cell

Game::Game() {
    Generator generator;
    _board = generator.Generate(); 
    // createFilledOutBoard();
}

void Game::createFilledOutBoard() {
    // fill out the 3x3 grids
    for (int i = 0; i < 9; i++) {
        int number = i + 1;
        int x = i % 3 * 3;
        int y = i / 3 * 3;
        _board[x][y] = number;
        _board[x + 1][y + 1] = number;
        _board[x + 2][y + 2] = number;
    }

    // fill out the rest of the board
    for (int i = 0; i < 9; i++) {
        int number = i + 1;
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                if (_board[x][y] == 0) {
                    _board[x][y] = number;
                }
            }
        }
    }
}

std::vector<std::vector<int>>* Game::getBoard() {
    return &_board;
}

void Game::setBoardSize(int size) {
    _boardSize = size;
}

int Game::getBoardSize() {
    return _boardSize;
}

void Game::resetBoard() {
    _board = std::vector<std::vector<int>>(_boardSize, std::vector<int>(_boardSize, 0));
}

void Game::setNode(int x, int y, int value) {
    _board[x][y] = value;
}