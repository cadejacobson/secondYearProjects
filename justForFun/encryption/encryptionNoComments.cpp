#include <string>
#include <iostream>
#include <random>
#include <vector>

void encrypt(); 
void decrypt();     

using namespace std;

int main()
{
    string choice;

    cout << "Would you like to encrypt or decrypt a message?"
        << " (type \"encrypt\" or \"decrypt\")" << endl;

    getline(cin, choice);

    while(choice != "encrypt" && choice != "decrypt")
    {
        cout << "Please type \"encrypt\" or \"decrypt\":" << endl;
        getline(cin, choice);
    }

    if(choice == "encrypt")
        encrypt();
    else
        decrypt();

    return 0;
}


void encrypt()
{
    string userInput;
    int length;
    int code;
    default_random_engine generator(122);
    uniform_int_distribution<int> distribution(0, 255);
    vector<int> randomValues;

    cout << "Please enter the message you would like to encrypt:"
        << endl;

    getline(cin, userInput);

    cout << endl;

    length = userInput.length();
    randomValues.resize(length);

    cout << "Your code is: ";

    for (int i = 0; i < length; i++)
    {
        randomValues[i] = distribution(generator);
    }

    for (int i = 0; i < length; i++)
    {
        code = randomValues[i] ^ userInput[i];
        cout << code << " ";
    }

    cout << endl;
    return;
}


void decrypt()
{
    int count = 0;
    size_t spacePos;
    string userInput;
    int length;
    int value;
    default_random_engine generator(122);
    uniform_int_distribution<int> distribution(0, 255);
    vector<int> randomValues;

    cout << "Please enter the message you would like to decrypt:"
        << endl;

    getline(cin, userInput);

    cout << endl;

    length = userInput.length();
    randomValues.resize(length);

    for (int i = 0; i < length; i++)
    {
        randomValues[i] = distribution(generator);
    }

    cout << "Your plaintext is: ";

    spacePos = userInput.find_first_of(" ");

    while(spacePos != string::npos) 
    {
        value = stoi(userInput.substr(0, spacePos));
        value = value ^ randomValues[count]; 
        userInput = userInput.substr(spacePos + 1);
        cout << char(value);
        spacePos = userInput.find_first_of(" ");
        count++;
    }

    value = stoi(userInput.substr(0, spacePos));
    value = value ^ randomValues[count];
    cout << char(value);
    return;
}