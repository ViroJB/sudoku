#include "generator.h"

// at very first: how do we store everything?
// we have: 9boxes, 9 rows, 9 columns
// ok, first we need to fill the diagonal boxes with 1-9. these dont overlap so we can just fill them in
// then i think we do these steps.
// 1. Randomly take any number 1-9.
// 2. Check if it is safe to put in the cell.(row , column and box)
// 3. If safe, place it and increment to next location and go to step 1.
// 4. If not safe, then without incrementing go to step 1.
// 5. Once matrix is fully filled, remove k no. of elements randomly to complete game.

// SOOO lets just use like 10-20 alreade created sudokus and just remove some numbers from them
// fuck generating them, like wtf?

Generator::Generator() {
    // initialize the 9x9 matrix
    m_solution = std::vector<std::vector<int>>(9, std::vector<int>(9, 0));
    std::srand(std::time(nullptr));
}

Generator::~Generator() {}

// this is just till we figure out a way to create a save and valid generator
std::vector<std::vector<int>> Generator::Generate() {
    std::vector<std::vector<int>> sudoku1 = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2}, {6, 7, 2, 1, 9, 5, 3, 4, 8}, {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3}, {4, 2, 6, 8, 5, 3, 7, 9, 1}, {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4}, {2, 8, 7, 4, 1, 9, 6, 3, 5}, {3, 4, 5, 2, 8, 6, 1, 7, 9}};

    std::vector<std::vector<int>> sudoku2 = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9}, {4, 5, 6, 7, 8, 9, 1, 2, 3}, {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {2, 3, 4, 5, 6, 7, 8, 9, 1}, {5, 6, 7, 8, 9, 1, 2, 3, 4}, {8, 9, 1, 2, 3, 4, 5, 6, 7},
        {3, 4, 5, 6, 7, 8, 9, 1, 2}, {6, 7, 8, 9, 1, 2, 3, 4, 5}, {9, 1, 2, 3, 4, 5, 6, 7, 8}};

    std::vector<std::vector<int>> sudoku4 = {
        {1, 4, 7, 2, 5, 8, 3, 6, 9}, {2, 5, 8, 3, 6, 9, 4, 7, 1}, {3, 6, 9, 4, 7, 1, 5, 8, 2},
        {4, 7, 1, 5, 8, 2, 6, 9, 3}, {5, 8, 2, 6, 9, 3, 7, 1, 4}, {6, 9, 3, 7, 1, 4, 8, 2, 5},
        {7, 1, 4, 8, 2, 5, 9, 3, 6}, {8, 2, 5, 9, 3, 6, 1, 4, 7}, {9, 3, 6, 1, 4, 7, 2, 5, 8}};

    std::vector<std::vector<int>> sudoku5 = {
        {6, 2, 4, 8, 7, 5, 3, 1, 9}, {7, 3, 1, 9, 2, 4, 6, 5, 8}, {9, 5, 8, 1, 6, 3, 7, 2, 4},
        {8, 1, 6, 7, 9, 2, 5, 4, 3}, {2, 4, 3, 5, 1, 8, 9, 7, 6}, {5, 9, 7, 3, 4, 6, 2, 8, 1},
        {3, 7, 9, 4, 8, 1, 2, 6, 5}, {1, 6, 2, 9, 5, 7, 4, 3, 8}, {4, 8, 5, 6, 3, 2, 1, 9, 7}};

    std::vector<std::vector<int>> sudoku6 = {
        {8, 1, 2, 7, 5, 3, 6, 4, 9}, {9, 4, 3, 6, 8, 2, 1, 7, 5}, {6, 7, 5, 4, 9, 1, 2, 8, 3},
        {1, 5, 4, 2, 3, 7, 8, 9, 6}, {3, 6, 9, 8, 4, 5, 7, 2, 1}, {2, 8, 7, 1, 6, 9, 5, 3, 4},
        {5, 2, 1, 9, 7, 4, 3, 6, 8}, {4, 3, 8, 5, 2, 6, 9, 1, 7}, {7, 9, 6, 3, 1, 8, 4, 5, 2}};

    std::vector<std::vector<int>> sudoku7 = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2}, {6, 7, 2, 1, 9, 5, 3, 4, 8}, {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3}, {4, 2, 6, 8, 5, 3, 7, 9, 1}, {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4}, {2, 8, 7, 4, 1, 9, 6, 3, 5}, {3, 4, 5, 2, 8, 6, 1, 7, 9}};

    std::vector<std::vector<int>> sudoku8 = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9}, {4, 5, 6, 7, 8, 9, 1, 2, 3}, {7, 8, 9, 1, 2, 3, 4, 5, 6},
        {2, 3, 4, 5, 6, 7, 8, 9, 1}, {5, 6, 7, 8, 9, 1, 2, 3, 4}, {8, 9, 1, 2, 3, 4, 5, 6, 7},
        {3, 4, 5, 6, 7, 8, 9, 1, 2}, {6, 7, 8, 9, 1, 2, 3, 4, 5}, {9, 1, 2, 3, 4, 5, 6, 7, 8}};

    std::vector<std::vector<int>> sudoku9 = {
        {9, 8, 7, 6, 5, 4, 3, 2, 1}, {2, 4, 6, 1, 7, 3, 9, 5, 8}, {3, 5, 1, 9, 8, 2, 7, 6, 4},
        {4, 6, 8, 5, 3, 7, 2, 1, 9}, {5, 7, 9, 2, 1, 6, 8, 4, 3}, {1, 3, 2, 8, 4, 9, 5, 7, 6},
        {6, 9, 3, 4, 2, 8, 1, 7, 5}, {7, 1, 5, 3, 6, 9, 4, 8, 2}, {8, 2, 4, 7, 9, 1, 6, 3, 5}};

    std::vector<std::vector<int>> sudoku10 = {
        {6, 2, 4, 8, 7, 5, 3, 1, 9}, {7, 3, 1, 9, 2, 4, 6, 5, 8}, {9, 5, 8, 1, 6, 3, 7, 2, 4},
        {8, 1, 6, 7, 9, 2, 5, 4, 3}, {2, 4, 3, 5, 1, 8, 9, 7, 6}, {5, 9, 7, 3, 4, 6, 2, 8, 1},
        {3, 7, 9, 4, 8, 1, 2, 6, 5}, {1, 6, 2, 9, 5, 7, 4, 3, 8}, {4, 8, 5, 6, 3, 2, 1, 9, 7}};

    std::vector<std::vector<int>> sudoku11 = {
        {8, 1, 2, 7, 5, 3, 6, 4, 9}, {9, 4, 3, 6, 8, 2, 1, 7, 5}, {6, 7, 5, 4, 9, 1, 2, 8, 3},
        {1, 5, 4, 2, 3, 7, 8, 9, 6}, {3, 6, 9, 8, 4, 5, 7, 2, 1}, {2, 8, 7, 1, 6, 9, 5, 3, 4},
        {5, 2, 1, 9, 7, 4, 3, 6, 8}, {4, 3, 8, 5, 2, 6, 9, 1, 7}, {7, 9, 6, 3, 1, 8, 4, 5, 2}};

    // save all the sudokus in a vector
    std::vector<std::vector<std::vector<int>>> sudokus = {sudoku1, sudoku2, sudoku4, sudoku5,  sudoku6,
                                                          sudoku7, sudoku8, sudoku9, sudoku10, sudoku11};

    // get a random sudoku from the vector
    int index = rand() % sudokus.size();
    std::vector<std::vector<int>> sudoku = sudokus[index];

    // TODO remove numbers the right way
    // remove some numbers randomly from the sudoku for now
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int chance = rand() % 100;
            if (chance < 50) {
                sudoku[i][j] = 0;
            }
        }
    }

    return sudoku;
}

// lets try to fill everything one by one, line by line
// also not working, gets stuck in a perma loop because of duplicates
void Generator::FillRemaining() {
    std::vector<int> fillers;
    int num;
    int index;
    int counter;
    for (int i = 0; i < 9; i++) {
        fillers = GetFillers();
        for (int j = 0; j < 9; j++) {
            if (m_solution[i][j] == 0) {
                index = rand() % fillers.size();
                num = fillers[index];
                counter = 0;
                while (!IsSafe(i, j, num)) {
                    // std::cout << "Problem in row, col: " << i << ", " << j << ", num: " << num << std::endl;
                    index = rand() % fillers.size();
                    num = fillers[index];
                    counter++;
                    if (counter > 5000) {
                        std::cout << "Counter exceeded" << std::endl;
                        PrintState();
                        counter = 0;
                        break;
                    }
                }

                m_solution[i][j] = num;
                fillers.erase(fillers.begin() + index);
            }
        }
    }
}

// this one doesnt fully generate, it gets stuck in a perma loop because of duplicates
// conflict
// void Generator::FillRemaining() {
//     // get the next empty cell, generate a random number and check if it is safe to put there
//     // if it is safe, put it there and move on to the next cell

//     int row, col;
//     for (row = 0; row < 9; row++) {
//         for (col = 0; col < 9; col++) {
//             if (m_solution[row][col] == 0) {
//                 // TODO save used numbers to increase performance
//                 int counter = 0;
//                 int num = rand() % 9 + 1;
//                 while (!IsSafe(row, col, num)) {
//                     std::cout << "Row: " << row << ", Col: " << col << ", Number: " << num << std::endl;
//                     num = rand() % 9 + 1;
//                     counter++;
//                     if (counter > 10000) {
//                         PrintState();
//                         break;
//                     }
//                 }

//                 // extra check just to make sure..
//                 if (IsSafe(row, col, num)) {
//                     std::cout << "Good one" << std::endl;
//                     m_solution[row][col] = num;
//                 }
//             }
//         }
//     }
// }

// thanks copilot! (changed my mind: fuck you!)
bool Generator::IsSafe(int row, int col, int num) {
    // check row
    for (int i = 0; i < 9; i++) {
        if (m_solution[row][i] == num) {
            // std::cout << "Problem in row, m_solution: " << m_solution[row][i] << ", Num: " << num << std::endl;
            return false;
        }
    }

    // check column
    for (int i = 0; i < 9; i++) {
        if (m_solution[i][col] == num) {
            // std::cout << "Problem in column" << std::endl;
            return false;
        }
    }

    // check box
    int start_row = row - row % 3;
    int start_col = col - col % 3;
    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            if (m_solution[i][j] == num) {
                // std::cout << "Problem in box" << std::endl;
                return false;
            }
        }
    }

    return true;
}

void Generator::FillBox(int start_row, int start_col) {
    std::vector<int> fillers = GetFillers();
    int num;

    for (int i = start_row; i < start_row + 3; i++) {
        for (int j = start_col; j < start_col + 3; j++) {
            int index = rand() % fillers.size();
            num = fillers[index];
            m_solution[i][j] = num;
            fillers.erase(fillers.begin() + index);
        }
    }
}

std::vector<int> Generator::GetFillers() {
    std::vector<int> fillers;
    // put numbers in random order in the vector?
    for (int i = 1; i <= 9; i++) {
        fillers.push_back(i);
    }
    return fillers;
}

void Generator::PrintState() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << m_solution[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}