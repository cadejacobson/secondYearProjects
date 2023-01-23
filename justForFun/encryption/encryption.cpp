// Anytime you see these two slashes, it is called a comment. These are english
// statements that are ignored by the compiler so a developer can leave cute, 
// secret, little notes to their friends. For real, They are actually used for 
//understanding code that was written well in the past.




#include <string>               //these are premade libraries of functions
#include <iostream>             //they provide us with certain data structures
#include <random>
#include <vector>



void encrypt();     //these are function declarations. These tell the compiler
void decrypt();     //how the the function call should look when it is called.




using namespace std;    //this helps so I do not have to put "std::" in front of basically everything



//here the actual code begins
int main()
{
    string choice;         // this is declaring a variable that holds a
                           // "string" or set of characters



    cout << "Would you like to encrypt or decrypt a message?"
        << " (type \"encrypt\" or \"decrypt\")" << endl;
    //this shows the user some text asking the user a question


    getline(cin, choice);       //this stores what you type into the variable "choice"


    // in plain english, below says "while the variable choice does not match 
    // 'encrypt' AND it does not match 'decrypt' make the user reenter their choice
    while(choice != "encrypt" && choice != "decrypt")
    {
        cout << "Please type \"encrypt\" or \"decrypt\":" << endl;
        getline(cin, choice);
    }



    if(choice == "encrypt")  //because there are only two options, we only need
        encrypt();           //an either/or. If what the user types matches
    else                     //"encrypt", call encrypt(). Otherwise, call "decrypt"
        decrypt();



    // 'int main' is the dfault function. a number must be returned, but it 
    // does not matter which one in this case
    return 0;
}




// whenever you see "encrypt()" like on line 53, the program redirects here
void encrypt()
{
    string userInput;
    int length;
    int code;
    default_random_engine generator(122);
    uniform_int_distribution<int> distribution(0, 255);
    vector<int> randomValues;  //this will be the key

    //once again, above this are all function declarations
    //if you recall, I told you 8 binary bits can range from 00000000 to 11111111,
    //or 0 - 255. The distribution shows this. the 122 was a seed I chose
    //so that we got the same values everytime we run the program.




    cout << "Please enter the message you would like to encrypt:"
        << endl;
    //this asks the user a question


    
    getline(cin, userInput);
    //this stores the user's response into the string "userInput"



    cout << endl;
    //this gives a little line break for appearance purposes :)



    length = userInput.length();
    randomValues.resize(length);
    //this calculates how many letters and spaces are in the response the user gave
    //after this, it resizes a data structure of integers to be that same size.
    //the data structure is currently empty, but think of this as marking off
    //where you plan to put your books on your shelf before you buy them
    //or setting the table with the amount of plates you need before dinner

    cout << "Your code is: ";

    for (int i = 0; i < length; i++)
    {
        randomValues[i] = distribution(generator);
        //distribution(generator) creates "random" numbers
        //here we actually store the randomValue data structure with those generated numbers
        //(placing the books now that we have them, or putting butts into dinner
        //table chairs)
    }

    for (int i = 0; i < length; i++)
    {
        code = randomValues[i] ^ userInput[i];
        cout << code << " ";

        //This is where we do the math I showed you on the white board.
        // ^ stands for "binary exlusive OR" the random values are the key that
        //only you and I have. it then exlcusive ORs one value of the key with 
        //one letter from the userInput
        //cout just sends the number to the screen
    }

    cout << endl;
    //one more pretty line break :)

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

    //above are function declarations again. Each function needs their own,
    //although they can be passed certain ones. Partially personal prefernce,
    //partially depends on the size of the variables




    cout << "Please enter the message you would like to decrypt:"
        << endl;

    getline(cin, userInput);
    //these two should be self explanatory at this point :)

    cout << endl;

    length = userInput.length();
    randomValues.resize(length);
    //once again, getting the length of what the user wrote into the console box
    //then resizing the empty data structure of numbers to be the same size

    for (int i = 0; i < length; i++)
    {
        randomValues[i] = distribution(generator);
        //filling the empty data structure with "random" numbers
    }

    cout << "Your plaintext is: ";

    spacePos = userInput.find_first_of(" ");
    //this finds the first space in the text given by the user


    //we continue this loop while there is a space in the string of characters.
    //string::npos represents the largest number in 32 bits, and the reason for
    //this is kind of difficult to explain. Everytime it is calculated here,
    //the position should be below 4, which is MUCH lower than that number which
    //is almost 10 billion
    while(spacePos != string::npos) 
    {
        value = stoi(userInput.substr(0, spacePos));
        //this combines two functions. First the "substr" command produces a string
        //of characters that is just the user's input from the first spot (position 0)
        //to wherever that space was found. Next, "stoi" turns this string of characters
        //into a single number



        value = value ^ randomValues[count]; 
        //here, we do the exlcusive or that we found in the last function. See
        //that for the explanation because my hands are tired



        userInput = userInput.substr(spacePos + 1);
        //this takes what the user inputted and basically chops off the first number,
        //before storing it back into the same variable.



        cout << char(value);
        //this is not done anywhere else, but is a process called "explicit
        //typecasting." This says take whatever integer is found in the variable
        // "value" and get its character rpresentation. The cout then puts this to the screen



        spacePos = userInput.find_first_of(" ");
        //this updates the position of the next space for the loop exit condition



        count++;
        //just a counter that helps me elsewhere :) the ++ at the end means "add one."
        //count++ could be rewritten as "count = count + 1"
    }

    value = stoi(userInput.substr(0, spacePos));
    value = value ^ randomValues[count];
    cout << char(value);
    //because the loop ends when a space is not found, it exits the loop one 
    //iteration too early. This simply repeats the loop one more time so that
    //the last character is translated.

    return;
}