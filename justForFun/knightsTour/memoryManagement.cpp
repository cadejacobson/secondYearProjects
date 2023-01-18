#include "knightsTour.h"


/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This function is called when a new board must be allocated to solve the
 * tour problem. It first allocates N number of pointers and then allocates N
 * number of arrays to each of those pointers.
 *
 *
 * @param[in, out] board - a 2d pointer to the board as an NxN array.
 * @param[in] n - the side lengths of the square board.
 *
 * @returns Nothing
 *
 * @par Example
 * @verbatim
        int ** board = nullptr;
        int n = 8;                          //side lengths of the board

        alloc2d( board, n );                //creates an 8x8 array

        delete2d( board, n );               //frees the allocated array
   @endverbatim
 *****************************************************************************/
void alloc2d(int**& board, int n)
{
    int i;
    board = new (nothrow) int* [n];

    if (board == nullptr)
    {
        return;
    }

    for (i = 0; i < n; i += 1)
    {
        board[i] = new (nothrow) int[n];
        if (board[i] == nullptr)
        {
            delete2d(board, i);
            return;
        }
    }
    return;
}



/** ***************************************************************************
 * @author Cade Jacobson
 *
 * @par Description
 * This function is called when an existing board must be deleted after solving
 * a tour problem. It first deletes the N number of arrays stored in each
 * pointer, and then deletes the pointers to those arrays.
 *
 *
 * @param[in, out] board - a 2d pointer to the board as an NxN array.
 * @param[in] n - the side lengths of the square board.
 *
 * @returns Nothing
 *
 * @par Example
 * @verbatim
        int ** board = nullptr;
        int n = 8;                          //side lengths of the board

        alloc2d( board, n );                //creates an 8x8 array

        delete2d( board, n );               //frees the allocated array
   @endverbatim
 *****************************************************************************/
void delete2d(int**& board, int n)
{
    int i;

    for (i = 0; i < n; i += 1)
        delete[] board[i];

    delete[] board;

    return;
}