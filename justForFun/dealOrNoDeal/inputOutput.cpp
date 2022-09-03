#include "inputOutput.h"

void outputChoices(int *temp)
{
    int i;
    for( i = 1; i < 26; i++)
    {
        if(temp[i] == 0)
            cout << setw(10) << i;
        else
            cout << setw(10) << " ";

        if( i % 5 == 0)
            cout << endl;
    }
    return;
}


void outputValues(int *temp)
{
    int i = 1;
    int* parse = temp;

    parse += 1;

    while(i < 26)
    {
        cout << setw(10) << *parse;

        if( i % 5 == 0)
            cout << endl;

        parse++;
        i++;
    }


    return;
}