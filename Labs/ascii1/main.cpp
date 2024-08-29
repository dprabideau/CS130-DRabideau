/*
    StdIO Lab
    ASCII Art - using literals and variables
    
    Updated By: Dayne Rabideau
    Date: 08-29-2024
    
    This program produces an ASCII art on the console.

    Algorithm steps: 
    1. Use variables to store data/values
    2. Write a series of cout statements to print the data/values
*/

#include <iostream> //library for input and output
#include <string> //library for string data
 
using namespace std; //resolve cout, cin, and endl names
 
//main entry point of the program
int main()
{
    //FIXME3: declare a variable to store name #Fixed#
    string name;
    //FIXME4: prompt user to enter their name and store the value into name variable using getline function #Fixed#
    cout << "Type your first name: "; cin >> name;

    //FIXME5: greet the name using the variable as the following output #Fixed#
    //must output: Nice meeting you, <name>!
    cout << "Nice meeting you, " << name << endl;

    cout << "Hope you like my Tom and Jerry ASCII art...\n\n";

    string line1 = "     |\\_/|          	*****************************  	   (\\_/)\n";
    cout << line1;
    //FIXME6: use variable to print the second line line of the graphic #Fixed#
    string line2 = "    / @ @ \\      	*         ASCII Lab         *  	  (='.'=)\n";
    cout << line2;
    //FIXME7: print the third line of the graphics #Fixed#
    cout << "   ( > 0 < )            *         By: Dayne         *   ( \" )( \" )\n";
    //FIXME8: use variable to print the fourth line #Fixed#
    string line4 = "     >>x<<        	*         CSCI 130          *\n";
    cout << line4;
    //FIXME9: use variable to print the fifth line #Fixed#
    string line5 = "    /  O  \\       	*****************************\n";
    cout << line5;

    cout << "\nGood bye... hit enter to exit the program: " << '\n';
    //FIXME10: make the console wait for user input #Fixed#
    cin.get();
    
    return 0; //exit program by returning 0 status to the system
}