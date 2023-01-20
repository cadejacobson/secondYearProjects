/** **************************************************************************
 * @file
 ****************************************************************************/


 /** *************************************************************************
  * @mainpage Knights Tour
  *
  * @author Cade Jacobson
  *
  * @section program_section Program Information
  *
  * @details
  * This program is dedicated to solving the knight's tour, which is a knight
  * travelling across the chess board touching each spot only once. To do this,
  * this program has many subfunctions and member functions.
  *
  * First, the program checks the amount of command line arguments supplied by
  * the user. If this amount is not 1 or 2, then the function outputs an error
  * message and leaves the program. If the value is 1, then the program outputs
  * a menu allowing you to change the board size, starting position, or solve
  * the tour. Once a three is entered, it will create a board of the proper
  * size by dynamically allocating an array, and then recursively call the
  * permute function until all the array spots have been filled. Once this
  * happens, the program outputs the board and deletes the board.
  *
  * If the value is 2, then an input and output file stream are opened. The
  * program then reads in the board size followed by the starting X and Y
  * position. It then goes through the same order of building the proper array,
  * and calling the recursive function to solve for the order. Once this has
  * been solved or the function returns a 0, the program outputs the correct
  * message appended to the end of the file. It then deletes the allocated
  * memory and checks to see if another tour has been specified.
  *
  *
  * @section compile_section Compiling and Usage
  *
  * @par Compiling Instructions:
  *      none - a straight compile and link with no external libraries.
  *
  * @par Usage:
    @verbatim
    c:\> thpe3.exe
            //This will present the user with a menu to set up the board
                            or

    c:\> thpe3.exe fileName
            //This will read the information in the file and solve those tours

    @endverbatim
  *
  ****************************************************************************/
#include "knightsTour.h"


/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This is the primary function of the program. It calls all other accessory
 * functions listed here in the documentation to achieve the goal of solving
 * the knight's tour and outputting this information.
 *
 *
 * @param[in] argc - the number of arguments from the command prompt.
 * @param[in] argv - a 2d array of characters containing the arguments.
 *
 * @returns 0. Main will always return a zero as an integer.
 *
 * @par Example
 * @verbatim
         Usage: thpe3.exe inputFile     //this outputs to the file specified
                        --inputFile is optional
                        OR
                thpe3.exe     //this will output all information to the console


   @endverbatim
 *****************************************************************************/
int main(int argc, char** argv)
{
    int n = 8;                        //create a way to get our own values here
    int startX = 7;
    int startY = 7;
    ifstream fin;
    ofstream fout;
    int solutionFound = 0;
    int** board = nullptr;
    string inputFile;
    string outputFile = "Solutions.tours";
    int fileCount = 1;

    if (!(argc == 2 || argc == 1))     //check to ensure a correct number of
    {                                   //command lines were called
        printUsage();
        return 0;
    }
    else if (argc == 1)                 //check command line argument count
    {
        outputOptions(n, startX, startY);
        cout << endl;

        while (menu(n, startX, startY) != 3)       //output the menu until 3
        {
            outputOptions(n, startX, startY);
            cout << endl;
        }

        incrementValues(n, startX, startY);   //make the inputted data usable

        alloc2d(board, n);                    //build a board
        if (board == nullptr)
            return 0;

        totalConsoleOutput(board, n, startX, startY, fout);     //call output
    }
    else
    {
        inputFile = string(argv[1]);
        if (!openInputFile(fin, inputFile))     //open input and output file
            return 0;
        if (!openOutputFile(fout, outputFile))
            return 0;

        while (fin >> n >> startX >> startY)      //repeat until file is empty
        {
            totalFileOutput(board, n, startX, startY, fout, fileCount);
        }
        fout.close();
        fin.close();
    }

    return 0;
}




/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This function is called when a new board must be produced with the beginning
 * 1 in the correct spot, and the borders of -1 surrounding the board so that
 * our function knows its boundaries. Before calling the function, it should be
 * noted that your startX and startY must be padded with a 2 to get the correct
 * position, and your side length must be added with a 4 to accomodate this.
 *
 *
 * @param[in, out] board - a 2d pointer to the board as an NxN array.
 * @param[in] n - the side lengths of the square board.
 * @param[in] startX - the X coordinate of the knight's starting position
 * @param[in] startY - the Y coordinate of the knight's starting position
 *
 * @returns Nothing
 *
 * @par Example
 * @verbatim
        int ** board = nullptr;
        int n = 8;                          //side lengths of the board
        int startX = 0;                     //beginning x coordinate position
        int startY = 0;                     //beginning y coordinate position

        n += 4;                 //compensates for 4 rows/cols of -1's (borders)
        startX += 2;                     //compensates for 2 rows of -1 before
        startY += 2;                     //compensates for 2 cols of -1 before

        alloc2d( board, n );                //creates an 8x8 array

        buildBoard( board, n, startX, startY );  //stores a 1 in position (0,0)

        delete2d( board, n );               //frees the allocated array

   @endverbatim
 *****************************************************************************/
void buildBoard(int**& board, int n, int startX, int startY)
{
    int i, j;


    for (i = 0; i < n; i += 1)          //allocate every valid spot to a zero
    {
        for (j = 0; j < n; j += 1)
        {
            board[i][j] = 0;
        }
    }

    for (i = 0; i < n; i += 1)
    {                               //build boundaires with -1
        board[i][0] = -1;
        board[i][1] = -1;
        board[i][n - 1] = -1;
        board[i][n - 2] = -1;
    }

    for (j = 0; j < n; j += 1)
    {                               //build boundaries with -1
        board[0][j] = -1;
        board[1][j] = -1;
        board[n - 2][j] = -1;
        board[n - 1][j] = -1;
    }

    board[startX][startY] = 1;

    return;
}


/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This is the primary function of the program and is what uses a brute force
 * searching method to find a path from 1 to N * N of knight moves on a square
 * board. When one of these is found, permuteKnight calls an output function
 * and exits the function.
 *
 *
 * @param[in, out] board - a 2d pointer to the board as an NxN array.
 * @param[in] n - the side lengths of the square board.
 * @param[in] startX - the X coordinate of the knight's starting position
 * @param[in] startY - the Y coordinate of the knight's starting position
 * @param[in] count - how many knights have been made placed to this call
 * @param[in, out] fout - a file stream to be outputted to if specified
 *
 *
 * @returns 1 if a path is found, 0 if a path is not
 *
 * @par Example
 * @verbatim
        int ** board = nullptr;
        int n = 8;                          //side lengths of the board
        int startX = 0;                     //beginning x coordinate position
        int startY = 0;                     //beginning y coordinate position
        int count = 1;       //starts at one as first knight is placed earlier
        ofstream fout;

        n += 4;                 //compensates for 4 rows/cols of -1's (borders)
        startX += 2;                     //compensates for 2 rows of -1 before
        startY += 2;                     //compensates for 2 cols of -1 before

        alloc2d( board, n );                //creates an 8x8 array

        buildBoard( board, n, startX, startY );  //stores a 1 in position (0,0)

        permuteKnight( board, startX, startY, count, n, fout )
                                       //output is called inside permuteKnight

        delete2d( board, n );               //frees the allocated array

   @endverbatim
 *****************************************************************************/
int permuteKnight(int**& board, int startX, int startY, int count, int n,
                  ofstream& fout)
{
    int ans = 0;
    int fileCount = 1;
    if (count == (n - 4) * (n - 4))             //if the count is the same as 
    {                                           //the space count, output
        outputBoard(board, n, fout);
        return 1;
    }

    if (board[startX - 2][startY + 1] == 0 && ans == 0)                     //a
    {
        board[startX - 2][startY + 1] = count + 1;
        ans += permuteKnight(board, startX - 2, startY + 1, count + 1, n,
                             fout);
        board[startX - 2][startY + 1] = 0;
    }
    if (board[startX - 1][startY + 2] == 0 && ans == 0)                     //b
    {
        board[startX - 1][startY + 2] = count + 1;
        ans += permuteKnight(board, startX - 1, startY + 2, count + 1, n,
                             fout);
        board[startX - 1][startY + 2] = 0;
    }
    if (board[startX + 1][startY + 2] == 0 && ans == 0)                     //c
    {
        board[startX + 1][startY + 2] = count + 1;
        ans += permuteKnight(board, startX + 1, startY + 2, count + 1, n,
                             fout);
        board[startX + 1][startY + 2] = 0;
    }
    if (board[startX + 2][startY + 1] == 0 && ans == 0)                     //d
    {
        board[startX + 2][startY + 1] = count + 1;
        ans += permuteKnight(board, startX + 2, startY + 1, count + 1, n,
                             fout);
        board[startX + 2][startY + 1] = 0;
    }
    if (board[startX + 2][startY - 1] == 0 && ans == 0)                     //e
    {
        board[startX + 2][startY - 1] = count + 1;
        ans += permuteKnight(board, startX + 2, startY - 1, count + 1, n,
                             fout);
        board[startX + 2][startY - 1] = 0;
    }
    if (board[startX + 1][startY - 2] == 0 && ans == 0)                     //f
    {
        board[startX + 1][startY - 2] = count + 1;
        ans += permuteKnight(board, startX + 1, startY - 2, count + 1, n,
                             fout);
        board[startX + 1][startY - 2] = 0;
    }
    if (board[startX - 1][startY - 2] == 0 && ans == 0)                     //g
    {
        board[startX - 1][startY - 2] = count + 1;
        ans += permuteKnight(board, startX - 1, startY - 2, count + 1, n,
                             fout);
        board[startX - 1][startY - 2] = 0;
    }
    if (board[startX - 2][startY - 1] == 0 && ans == 0)                     //h
    {
        board[startX - 2][startY - 1] = count + 1;
        ans += permuteKnight(board, startX - 2, startY - 1, count + 1, n,
                             fout);
        board[startX - 2][startY - 1] = 0;
    }

    return ans;
}






/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This is a very minor accessory function that increments three variables so
 * that they are usable on the backend of this program.
 *
 *
 * @param[in, out] n - The side lengths of our board
 * @param[in, out] startX - The beginning x position
 * @param[in, out] startY - The beginning Y position
 *
 *
 * @returns nothing
 *
 * @par Example
 * @verbatim
        int n = 4;
        int startX = 2;
        int startY = 2;

        incrementValues( n, startX, startY );//n == 8, startX == 4, startY == 4

   @endverbatim
 *****************************************************************************/
void incrementValues(int& n, int& startX, int& startY)
{
    n += 4;                             //change board size and start pos
    startX += 2;
    startY += 2;
    return;
}
