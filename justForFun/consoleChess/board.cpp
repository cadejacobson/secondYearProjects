#include "board.h"

void outputBoard(vector<vector<string>> &board)
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            cout << board[i][j] << "   ";
        }
        cout << endl;
    }
}


bool makeMove(vector<vector<string>>& board, string& userInput, int& sideMove)
{
    if( userInput.find_first_of("abcdefgh") == 0)
    {
        return makePawnMove(board, userInput, sideMove);
    }
    return true;    //change?
}

bool makePawnMove(vector<vector<string>> &board, string &userInput, int &sideMove)
{
    int startFile = userInput[0] - 97;
    int endPosition =  userInput[1] - 48;
    endPosition = 8 - endPosition;
    string color = "wp";
    bool take = false;
    

    if(sideMove % 2 == 1)
        color = "bp";
    /*
    if(userInput.size() != 2)
    {
        take = true;
    } */                           


    for(int i = 0; i < 8; i++)
    {
        if(board[i][startFile] == color)
        {
            if(abs(endPosition - i) == 1 && board[endPosition][startFile] == "  ")
            {
                board[endPosition][startFile] = color;
                board[i][startFile] = "  ";
                return true;
            }
            else if((abs(endPosition - i) == 2) && board[endPosition][startFile] == "  ")
            {
                board[endPosition][startFile] = color;
                board[i][startFile] = "  ";
                return true;
            }
        }
    }


    return false;


    /*
    * add in takes to either side
    */
}


bool makeBishopMove(vector<vector<string>>& board, string& userInput, int& sideMove)
{


    return false;
}