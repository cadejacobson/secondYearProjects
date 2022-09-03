#include "random.h"

void randomizeCases(int *cases) //cant pass by *reference for some reason
{
    int caseValues[26] = {0, 1, 5, 10, 25, 50, 75, 100, 200, 300, 400, 500,
                          750,1000, 5000, 10000, 25000, 50000, 75000, 100000,
                          200000,300000, 400000, 500000, 750000, 1000000};

    int used[26] = {0};

    default_random_engine generator(time(nullptr));
    uniform_int_distribution<int> distribution(1, 25);
    int placementCount = 1;
    int rand;

    while(placementCount < 26)
    {
        rand = distribution(generator);

        if( used[rand] == 0 )
        {
            cases[placementCount] = caseValues[rand];
            placementCount++;
            used[rand] = 1;
        }
    }

    return;
}