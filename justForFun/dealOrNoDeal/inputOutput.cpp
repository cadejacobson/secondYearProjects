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


void outputRemainingValues(int *values, int *lookup)
{
    int i, j;
    bool found;
    vector<int> remainingValues;
    vector<int> orderedValues = {0, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500,
                           750,1000, 5000, 10000, 25000, 50000, 75000, 100000,
                           200000,300000, 400000, 500000, 750000, 1000000};

    cout << endl;

    for(i = 1; i < 26; i++)
    {
        if(lookup[i] == 0)
            remainingValues.push_back(values[i]);
    }

    for(i = 1; i < 26; i++)
    {
        found = false;
        for(j = 0; j < remainingValues.size(); j++)
        {
            if(remainingValues[j] == orderedValues[i])
            {
                found = true;
            }
        }
        if (found)
            cout << setw(10) << orderedValues[i];
        else
            cout << setw(10) << " ";

        if (i % 2 == 0)
            cout << endl;
    }

    cout << endl;

    outputOffer(remainingValues);

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

void outputOffer(vector<int> cases)
{
    int i;
    long long int squaredValues;
    double offerValue;

    for(i = 1; i < cases.size(); i++)
    {
        squaredValues += cases[i] * cases[i];
    }

    offerValue = pow(sqrt(sqrt(squaredValues / cases.size())), 1.3);


    cout << "Your offer is: " << fixed << setprecision(2 ) << offerValue << "." << endl;
    cout << "Deal or no deal?"<< endl;

    return;
}
