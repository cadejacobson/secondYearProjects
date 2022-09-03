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


void outputSingleValue(int caseValue)
{
    cout << "This case was worth: " << caseValue << " dollars." << endl;

    return;
}



void outputEndingMessage(int winnings)
{
    cout << endl;
    cout << "Congratulations! You have won "  << winnings << " dollars!" << endl;
    cout << "Thank you for playing!" << endl;
}