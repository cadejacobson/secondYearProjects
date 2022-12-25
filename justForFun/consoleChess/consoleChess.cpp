#include "board.h"

using namespace std;

int main()
{
    int side = 0;
    bool checkmate = false;
    int quit = 0;
    string userInput = "";

    vector<vector<string>> board = {{"br","bn","bb","bq","bk","bb","bn","br"},
                                    {"bp","bp","bp","bp","bp","bp","bp","bp"},
                                    {"  ","  ","  ","  ","  ", "  ","  ","  "}, 
                                    {"  ","  ","  ","  ","  ","  ","  ","  "}, 
                                    {"  ","  ","  ","  ","  ","  ","  ","  "}, 
                                    {"  ","  ","  ","  ","  ","  ","  ","  "}, 
                                    {"wp","wp","wp","wp","wp","wp","wp","wp"}, 
                                    {"wr","wn","wb","wq","wk","wb","wn","wr"}};

    while(userInput != "quit" && checkmate != true)
    {
        outputBoard(board);
        getline(cin, userInput);
        makeMove(board, userInput, side);

        side++;
    }
}