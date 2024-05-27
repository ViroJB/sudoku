#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <ctime>

class Generator {
   public:
    Generator();
    ~Generator();
    std::vector<std::vector<int>> Generate();
    bool IsSafe(int row, int col, int num);
    void FillRemaining();
    std::vector<int> GetFillers();
    void FillBox(int start_row, int start_col);
    void PrintState();

   private:
    // do we go for vector<vector> or with a map<std::string, vector<int>>?
    // with a map we could go for A1, B4, C7 etc
    std::vector<std::vector<int>> m_solution;
};