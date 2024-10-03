
/*
    Loops Lab
    Updated By: Dayne Rabideau
    CSCI 111
    Date: 10-03-2024

    Program prints geometric shapes of given height with * using loops
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;


void printTriangle(int height) {
    //Function takes height as an argument to print the triangle
    //of that height with *
    int row = 1;
    // row
    while (row <= height) {
        // column
        for(int col = 1; col<=row; col++)
            cout << "* ";
        row += 1;
        cout << endl;
    }
    cout << endl;
}


void printFlippedTriangle(int height) {
    /* 
    Implement the function that takes height as an argument
    and prints a triangle with * of given height.
    Triangle of height 5, e.g., should look like the following.
    * * * * *
    * * * *
    * * *
    * *
    *
    
    */
    // FIXME3 ... FIXED
    int row = height;
    while (row >= 0) {
        for(int col = 1; col<=row; col++)
            cout << "* ";
        row -= 1;
        cout << endl;
    }
}


/*  
FIXME4
Design and implement a function that takes an integer as height and
prints square of the given height with *.
Square of height 5, e.g., would look like the following.

*  *  *  *  *  
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   
*  *  *  *  *   

*/
void printSquare(int height) {
    int row = 1;
    while (row <= height) {
        for(int col = 1; col<=height; col++)
            cout << "* ";
        cout << endl;
        row ++;
    }
}

// function clears the screen system call
// NOTE: system call is not a security best pracice!
void clearScreen() {
    // use "cls" in windows and "clear" command in Mac and Linux
    #ifdef _WIN32
        system("clS");
    #else
        system("clear");
    #endif
}

int main(int argc, char* argv[]) {
    // FIXME5 add a loop to make the program to continue to run until the user wants to quit
    bool choice = true;
    while (choice==true){
    // FIXME6 call clearScreen function to clear the screen for each round of the loop
    clearScreen();
    int height;
    cout << "Program prints geometric shapes of given height with *\n";
    cout << "Please enter the height of the shape: ";
    cin >> height;
    // call printTriangle function passing user entered height
    printTriangle(height);

    // FIXME7
    // Call printFlippedTriangle passing proper argument
    // Manually test the function
    printFlippedTriangle(height);

    // FIXME6
    // Call the function defined in FIXME4 passing proper argument
    // Manually test the function
    printSquare(height);

    // FIXME9
    // prompt user to enter y/Y to continue anything else to quit
    cout << "Would you like to find another set of shapes (y/n): ";
    string str_choice;
    cin >> str_choice;
    
    // FIXME10
    // Use conditional statements to break the loop or continue the loop
    if (str_choice == "n" || str_choice == "N"){
        choice = false;
        }
    }
    cout << "Thank you for using my program";
    return 0;
}
