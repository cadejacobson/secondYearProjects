#include "knightsTour.h"


/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This is the function used to output a console menu if a file is not
 * specified. If a 1 is inputted, the side lengths of the board are being
 * changed. If a 2 is inputted, the starting position is going to be changed.
 * Finally, if a 3 is inputted, then the menu can be exited and the tours run.
 *
 *
 * @param[in, out] n - the side lengths of the square board.
 * @param[in, out] startX - the X coordinate of the knight's starting position
 * @param[in, out] startY - the Y coordinate of the knight's starting position
 *
 *
 * @returns 3 if the menu is work is done, 2 if the starting position must be
 * changed, and 1 if the board size must be changed.
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

        while( menu( n, startX, startY ) != 3 ) //a 3 must be chosen to run
        {
            cout << "Please select 1, 2, or 3" << endl;
        }

        alloc2d( board, n );                //creates an 8x8 array

        buildBoard( board, n, startX, startY );  //stores a 1 in position (0,0)

        permuteKnight( board, startX, startY, count, n, fout )
                                       //output is called inside permuteKnight

        delete2d( board, n );               //frees the allocated array

   @endverbatim
 *****************************************************************************/
int menu(int& n, int& startX, int& startY)
{
    int input, userChange;
    int newX, newY;
    cin >> input;

    switch (input)
    {                       //if 1, allow the user to change the board
    case 1:
        cout << "Enter the size of the NxN Board ( >3 ): " << endl;
        cin >> userChange;

        if (userChange <= startX)          //error check based on position
        {
            cout << "Invalid board size. ";
            cout << "Please change your starting position first." << endl;
            break;
        }

        if (userChange <= startY)
        {
            cout << "Invalid board size. ";
            cout << "Please change your starting position first." << endl;
            break;
        }

        if (userChange > 3)
            n = userChange;
        else
            cout << "Invalid board size. " << endl;
        break;

    case 2:                                 //if 2, allow change of position
        cout << "Enter Starting Coordinates [ row , col ]: " << endl;
        cin >> newX >> newY;
        if (newX < n && newX >= 0)          //error check negatives
        {
            startX = newX;
        }
        else
        {
            cout << "Invalid X Position" << endl;
        }

        if (newY < n && newY >= 0)
        {
            startY = newY;
        }
        else
        {
            cout << "Invalid Y Position" << endl;
        }
        break;

    case 3:                                        //if 3, solve
        break;

    default:
        cout << "Please enter 1, 2, or 3." << endl;
    }

    return input;
}



/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This is a minor accessory function that outputs four lines of a menu so that
 * the user can specify what option the would like to do. This tells the user
 * what inputting a 1, 2, or 3 will do for the switch statement.
 *
 *
 * @param[in] n - the side lengths of the square board.
 * @param[in] startX - the X coordinate of the knight's starting position
 * @param[in] startY - the Y coordinate of the knight's starting position

 *
 *
 * @returns nothing
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

         while( menu( n, startX, startY ) != 3 ) //a 3 must be chosen to run
        {
            cout << "Please select 1, 2, or 3" << endl;
            outputOptions( n, startX, startY );     //outputs the menu again
        }

        alloc2d( board, n );                //creates an 8x8 array

        buildBoard( board, n, startX, startY );  //stores a 1 in position (0,0)

        permuteKnight( board, startX, startY, count, n, fout )
                                       //output is called inside permuteKnight

        delete2d( board, n );               //frees the allocated array

   @endverbatim
 *****************************************************************************/
void outputOptions(int n, int startX, int startY)
{
    cout << "  1) Change Board Size from " << n << "x" << n << endl;
    cout << "  2) Change starting location from [" << startX << "," << startY;
    cout << "]" << endl;
    cout << "  3) Exit and Solve Tour" << endl;
    cout << "Enter Choice: ";

    return;
}

/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This is the output function for main. If an output file stream is opened,
 * this function will traverse the allocated arrays ignoring "-1s" on the
 * border and output them to the file. If not, they will be outputted to the
 * console stream.
 *
 *
 * @param[in, out] board - a 2d pointer to the board as an NxN array.
 * @param[in] n - the side lengths of the square board.
 * @param[in, out] fout - a file stream to be outputted to if specified
 *
 *
 * @returns nothing
 *
 * @par Example
 * @verbatim
        int ** board = nullptr;
        int n = 8;                          //side lengths of the board
        ofstream fout;
        fout.open( "Solutions.tours.txt" );     //open the output file

        alloc2d( board, n );                //creates an 8x8 array

        buildBoard( board, n, startX, startY );  //stores a 1 in position (0,0)

        outputBoard( board, n, fout );      //outputs a built board to the file

        delete2d( board, n );               //frees the allocated array

   @endverbatim
 *****************************************************************************/
void outputBoard(int**& board, int n, ofstream& fout)
{
    int i, j;

    if (!fout.is_open())
    {
        for (i = 2; i < n - 2; i += 1)
        {
            for (j = 2; j < n - 2; j += 1)        //print each valid board spot
            {                              //to the screen if no stream is open
                cout << setw(3) << board[i][j];
            }
            cout << endl;
        }
    }
    else
    {
        for (i = 2; i < n - 2; i += 1)
        {                                   //else, print to the file
            fout << "       ";
            for (j = 2; j < n - 2; j += 1)
            {
                fout << setw(3) << board[i][j];
            }
            fout << endl;
        }
    }

    return;
}



/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This is a minor accessory function that opens a file input stream with the
 * given file name specified by the user. It then returns a boolean value based
 * on if the stream was opened.
 *
 *
 * @param[in, out] fin - the input stream to be opened
 * @param[in] fileName - the file argument specified by the user to read from
 *
 *
 * @returns true if the stream was opened, false if not
 *
 * @par Example
 * @verbatim
        string fileName = "testTours.txt";
        ifstream fin;

        if( !openInputFile( fin, fileName ) )   //if the stream did not open
            exit(0);                           //exit
   @endverbatim
 *****************************************************************************/
bool openInputFile(ifstream& fin, string fileName)
{
    fin.open(fileName);                 //open the file and check success
    if (!fin.is_open())
    {
        cout << "Unable to open output file: " + fileName << endl;
        return false;
    }
    return true;
}

/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This is a minor accessory function that opens a file output stream with the
 * given file name specified by the user. It then returns a boolean value based
 * on if the stream was opened.
 *
 *
 * @param[in, out] fout - the output stream to be opened
 * @param[in] fileName - the file argument specified by the user to output to
 *
 *
 * @returns true if the stream was opened, false if not
 *
 * @par Example
 * @verbatim
        string fileName = "Solutions.tours.txt";
        ifstream fout;

        if( !openOutputFile( fin, fileName ) )   //if the stream did not open
            exit(0);                             //exit
   @endverbatim
 *****************************************************************************/
bool openOutputFile(ofstream& fout, string fileName)
{
    fout.open(fileName, fstream::app);    //open the file to append, check
    if (!fout.is_open())
    {
        cout << "Unable to open output file: " + fileName << endl;
        return false;
    }

    return true;
}


/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This is a minor accessory function that outputs the header for each tour
 * solved from a file. It ouputs the tour number, and where the knight started
 * at.
 *
 *
 * @param[in, out] fout - an opened output stream to put data into
 * @param[in] fileCount - the amount of tours solved in the file
 * @param[in] n - the side lengths of the board
 * @param[in] startX - the knight's starting x position
 * @param[in] startY - the knight's starting y position
 *
 *
 * @returns nothing
 *
 * @par Example
 * @verbatim

    buildBoard(board, n, startX, startY);

    fileOutputHeader(fout, fileCount, n, startX, startY);
    solutionFound = permuteKnight(board, startX, startY, 1, n, fout);
    if (solutionFound == 0)
        fout << "       No solutions found" << endl;
    delete2d(board, n);

   @endverbatim
 *****************************************************************************/
void fileOutputHeader(ofstream& fout, int fileCount, int n, int startX,
                      int startY)
{
    fout << "Tour # " << fileCount << endl;
    fout << "        " << n - 4 << " X " << n - 4 << " ";
    fout << "starting at (" << startX - 2 << ", " << startY - 2 << ")";
    fout << endl << endl;
}

/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This function handles many different tasks as allocated by main for file
 * tours. This first corrects the side lengths and starting positions then
 * allocates a board of the correct size, and builds that board. It then calls
 * the permute function and outputs the data before deleting the dynamically
 * allocated array and exiting.
 *
 *
 * @param[in, out] board - A 2D pointer to our board
 * @param[in, out] n - The side lengths of our board
 * @param[in, out] startX - The beginning x position
 * @param[in, out] startY - The beginning Y position
 * @param[in, out] fout - an opened output stream to put data into
 * @param[in, out] fileCount - a measure of how many tours have been solved
 *
 *
 * @returns nothing
 *
 * @par Example
 * @verbatim
        while( fin >> n >> startX >> startY )
        {
            totalFileOutput( board, n, startX, startY, fout, fileCount );
        }
   @endverbatim
 *****************************************************************************/
void totalFileOutput(int** board, int& n, int& startX, int& startY,
                     ofstream& fout, int& fileCount)
{
    int solutionFound;

    incrementValues(n, startX, startY);

    alloc2d(board, n);                      //allocate the memory for a board
    if (board == nullptr)
        return;

    buildBoard(board, n, startX, startY);           //build the board

    fileOutputHeader(fout, fileCount, n, startX, startY);     //output a header
    solutionFound = permuteKnight(board, startX, startY, 1, n, fout);
    if (solutionFound == 0)
        fout << "        No solutions found" << endl;
    delete2d(board, n);                             //delete the board
    fout << endl;                                   //output an end line
    fileCount++;

    return;
}






/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This function handles many different tasks as allocated by main for console
 * tours. This first builds the correct size board, then calls the permutation
 * function and, depending on the outcome of this function, either outputs
 * the solution or "no solution found."
 *
 *
 * @param[in, out] board - A 2D pointer to our board
 * @param[in, out] n - The side lengths of our board
 * @param[in, out] startX - The beginning x position
 * @param[in, out] startY - The beginning Y position
 * @param[in, out] fout - an opened output stream to put data into
 *
 *
 * @returns nothing
 *
 * @par Example
 * @verbatim

   @endverbatim
 *****************************************************************************/
void totalConsoleOutput(int** board, int& n, int& startX, int& startY,
                        ofstream& fout)
{
    int solutionFound;
    buildBoard(board, n, startX, startY);           //build the board

    solutionFound = permuteKnight(board, startX, startY, 1, n, fout);
    if (solutionFound == 0)                     //permute the choices
        cout << "No solutions found" << endl;

    delete2d(board, n);                              //delete allocated memory

    return;
}



/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This is a minor accessory function that outputs a series of usage
 * instructions in the event that the wrong number of command line arguments
 * are supplied.
 *
 * @returns nothing
 *
 * @par Example
 * @verbatim
        if( argc != 2 )
        {
            printUsage();
            return 0;
        }
   @endverbatim
 *****************************************************************************/
void printUsage()
{
    cout << "c:\\ > thpe3.exe" << endl;
    cout << "          --This will present the user with a menu to set up the";
    cout << " board" << endl << endl;
    cout << "               OR" << endl << endl;
    cout << "c:\\ > thpe3.exe fileName" << endl;
    cout << "          --This will read the information in the file and solve";
    cout << " those tours" << endl;

    return;
}