#include <vector>
#include <string>
#include <iostream>

using namespace std;

void outputBoard(vector<vector<string>> &board);
bool makeMove(vector<vector<string>> &board, string &userInput, int &sideMove);
bool makePawnMove(vector<vector<string>>& board, string& userInput, int &sideMove);
bool makeBishopMove(vector<vector<string>>& board, string& userInput, int& sideMove);