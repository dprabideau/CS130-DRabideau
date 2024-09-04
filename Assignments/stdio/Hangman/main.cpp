/*
Author: Dayne P Rabideau
Date: 09-02-2024

Decription: Produces ASCII Hangman Stages
*/

#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    string name;
    cout << "What is your name?" << endl;
    cin >> name;
    cout << "Nice to meet you, " << name << "Sadly the Hangman game does not work yet. Here is what the stages would look like: " << endl;
    this_thread::sleep_for(chrono::seconds(3));

    //Stage 0
    string stage0 = "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n";
    cout << "Stage 0\n" << stage0 << endl;
    this_thread::sleep_for(chrono::seconds(1));

    //Stage 1
    string stage1 = "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n";
    cout << "Stage 1\n" << stage1 << endl;
    this_thread::sleep_for(chrono::seconds(1));

    //Stage 2
    string stage2 = "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n";
    cout << "Stage 2\n" << stage2 << endl;
    this_thread::sleep_for(chrono::seconds(1));

    //Stage 3
    string stage3 = "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n";
    cout << "Stage 3\n" << stage3 << endl;
    this_thread::sleep_for(chrono::seconds(1));

    //Stage 4
    string stage4 = "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n";
    cout << "Stage 4\n" << stage4 << endl;
    this_thread::sleep_for(chrono::seconds(1));

    //Stage 5
    string stage5 = "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n";
    cout << "Stage 5\n" << stage5 << endl;
    this_thread::sleep_for(chrono::seconds(1));

    //Stage 6
    string stage6 = "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n";
    cout << "Stage 6\n" << stage6 << endl;
    this_thread::sleep_for(chrono::seconds(1));

    cin.ignore();
    cout << "Press enter to close program...";
    cin.get();

    return 0;
}