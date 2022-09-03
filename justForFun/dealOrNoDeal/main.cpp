#include "inputOutput.h"
#include "random.h"

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
    cout << "Your case value is: " << caseValues[chosenCase] << ". Shhhhh, it's a secret!" << endl;
    cout << "It's how we debug :) " << endl;

    

    outputEndingMessage(caseValues[chosenCase]);

    return 0;
}
