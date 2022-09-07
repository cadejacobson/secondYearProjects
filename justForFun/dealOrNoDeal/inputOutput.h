#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

#pragma once

using namespace std;

void outputChoices( int* cases );
void outputRemainingValues(int *values, int *lookup);
void outputEndingMessage(int winnings);
void outputSingleValue(int caseValue);
void outputOffer(vector<int> cases);