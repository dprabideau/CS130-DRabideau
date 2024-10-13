/* 
Author: Dayne Rabideau
Date: 10-12-2024
Description: 
*/

#include <iostream>    
#include <chrono>
#include <cassert>     

using namespace std;

//Declaring Functions to be used later
int randomNumber ();
int readNumber();
int checkGuess(const int &, const int &);
int game();
//test function for checkGuess function
void test(){
    assert(checkGuess(1,2)==-1);
    assert(checkGuess(2,1)==2);
    assert(checkGuess(3,3)==0);
    cout << "All test cases passed\n";
}

int main (){
    //Calls test function
    test();
    //counter for number of wins
    int wins=0;
    //count of total games, its a double so correct percentages can be calculated later
    double totalGames = 0;
    //menu choice
    string choice;
    do {
        //promts for user input for menu option
        cout << "Would you like to play a game(g), view your stats(s) or exit programe(e): ";
        cin >> choice;
        //if statement to direct the users menu choice
        if (choice == "g"){
            //intitializes game while also recording the result of game
            int result = game();
            //adds 1 to total game counter
            totalGames++;
            //the game was a win the 1 is added to win counter
            if (result==1){
                wins++;
            }
        }
        else if (choice == "s"){
            //if user wanted to view their stats, they are apropriatley given in the following code
            cout << "Total Games Played: " << totalGames << endl;
            printf("Percentage of times won: %.2f percent",wins/totalGames*100);
            cout << endl;
            printf("Percentage of times lost: %.2f percent",100-(wins/totalGames*100));
            cout << endl;
        }
        else if (choice == "e"){
            //Short exit message before exiting programe
            cout << "Thanks for playing!\n";
        }
        else {
            //ensures user actually enters one of the options
            cout << "Please input one of the options listed\n";
        }
    }
    while (choice!="e");//loops the main function until user choses to exit
}

int game () {
    //declares variable to be used in the game function
    int secretNum, guessNum;
    //declares the stats value to be used in exit code
    int stats = 0;
    //sets the secret number based of the return of the function
    secretNum = randomNumber();
    //temp output for testing
    cout << secretNum << endl;
    //loop counter so user gets 6 tries
    int loopCount = 0;
    //loop of guesses
    do {
        //sets the guessed number based of users input from the function
        guessNum = readNumber();
        //checks the guessed number vs the secret number to give hints (Higher or lower)
        switch (checkGuess(secretNum, guessNum))
        {
        case -1:
            cout << "The secret number is less than your last guess\n";
            break;
        case 2:
            cout << "The secret number is greater than your last guess\n";
            break;
        case 0:
            //changes stats to winning exit code to be used in following if statement ans exit code
            stats = 1;
            break;
        default:
            //I dont know why but i felt it would be better having an empty default case
            break;
        }
        //increases loop counter by 1
        loopCount++;
      //ensures the loop is only left when the user guesses correct or six guesses are used up
    } while (secretNum!=guessNum && loopCount < 6);
    //If statment for declaring win or loss
    if (stats == 1){
        cout << "Congrats you guessed the number in " << loopCount << " tries\n";
    }
    else{
        cout << "Sorry, but you lost. The secret number was " << secretNum << "\nBetter luck next time.\n";
    }
    return stats;
}

int randomNumber () {
    //Could not make the random number function work so instead I looked this line of code for finding the time in ms
    //it basically converts the current time in milliseconds into a number between 1 and 20, making it near random
    auto millis = chrono::duration_cast<chrono::milliseconds>(chrono::system_clock::now().time_since_epoch()).count();
    return millis % 20 + 1;
}

int readNumber(){
    int guess;
    do {
    cout << "Please guess a number between 1 and 20: ";
    cin >> guess;
    }
    while ( guess>20 || guess<1 );
    return guess;
}

int checkGuess(const int &a, const int &b){
    int checkcode;
    if (a==b){
        checkcode = 0;
    }
    else if (a<b){
        checkcode = -1;
    }
    else{
        checkcode = 2;
    }
    return checkcode;
}