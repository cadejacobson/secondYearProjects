#include "rounds.h"
#include "inputOutput.h"

void playRound( int selectedCase, int caseCount, int *cases, int* lookup )
{
    string continuePlaying;
    int userInput;

    if(caseCount < 1)
        caseCount = 1;

    for(int i = 0; i < caseCount; i++ )
    {
        cout << "Please choose a case:" << endl;
        cin >> userInput;

        while(userInput < 1 || userInput > 25 || lookup[userInput] == 1)
        {
            cout << "That is invalid. Please choose another: " << endl;
            cin >> userInput;
        }

        lookup[userInput] = 1;
        outputSingleValue(cases[userInput]);

    }

    outputChoices(lookup);

    //add a way of outputting the remaining values here
    //add the calculation here as well

    outputRemainingValues(cases, lookup);

    cout << "Your offer is one Billion dollars." << endl;
    cout << "Deal or no deal?" << endl;

    cin.ignore();

    getline(cin, continuePlaying);
    if( continuePlaying == "No deal" || continuePlaying == "no deal")
    {
        playRound(selectedCase, caseCount - 1, cases, lookup);
    }

    //put an accept or decline version here.
    //if accept, return END GAME
    //if not, run the function again,

    return;
}