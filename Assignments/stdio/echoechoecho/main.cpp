/*
Author: Dayne Rabideau
Date: 09-08-2024

Description: User inputs string, string is echoed back
*/

#include <iostream>
using namespace std;
int main() {
    string echoWord;
    cout << "Please yell the word that will bounce of the monument: ";
    cin >> echoWord;
    //This loops the comand 3 times, yes its overcomplicated but its good practice for me
    for (int i = 0; i < 3; i++) {
        cout << echoWord << " ";
    }
    cout << endl;
}