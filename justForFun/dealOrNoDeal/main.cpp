#include "inputOutput.h"
#include "random.h"
#include "rounds.h"

int main() {
    int selectedLookup[26] = {0};       //zero will not be used for simplicity
    int caseValues[26] = {0};

    randomizeCases(caseValues);
    outputChoices( selectedLookup );

    cout << "Please choose your case number: " << endl;

    int chosenCase;
    cin >> chosenCase;

    while( chosenCase > 25 || chosenCase < 1)
    {
        cout << "That is an invalid choice. Please choose again:" << endl;
        cin >> chosenCase;      //gotta limit this to only numbers
    }

    selectedLookup[chosenCase] = 1;

    outputChoices(selectedLookup );

    //debugging statements
    cout << endl;
    /*cout << "Your case value is: " << caseValues[chosenCase] << ". Shhhhh, it's a secret!" << endl;
    cout << "It's how we debug :) " << endl;*/

    playRound( chosenCase, 7, caseValues, selectedLookup);

    outputEndingMessage(caseValues[chosenCase]);  //move these inside of the playRound

    return 0;
}
