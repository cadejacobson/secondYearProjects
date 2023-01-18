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
    else if (userInput[0] == 'r')
    {
        return makeRookMove(board, userInput, sideMove);
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


bool makeRookMove(vector<vector<string>>& board, string& userInput, int& sideMove)
{
    int newFile = userInput[1] - 97;      // currently jumps over other pawns
    int newRank = userInput[2] - 48;      // add more
    newRank = 8 - newRank;
    string color = "wr";

    if (sideMove % 2 == 1)
        color = "br";

    for (int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(board[i][j] == color && (newRank == i || newFile == j))
            {
                board[i][j] = "  ";
                board[newRank][newFile] = color;
                return true;
            }
        }
    }

    /*
        will eventually need to code for the same rooks on the same file
        may be out of the scope of this project though.
    */

    return false;
}


bool makeBishopMove(vector<vector<string>>& board, string& userInput, int& sideMove)
{


    return false;
}

