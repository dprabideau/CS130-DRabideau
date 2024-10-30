/*
Author: Dayne Rabideau
Date: 10-27-2024
Description: Program is given inputs (number of pieces and value of pieces) outputs the 
    sum of value for two people dividing the pieces.
*/

#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

void calculateScores(int pieces[], int n, int& scoreAlice, int& scoreBob) {
    sort(pieces, pieces + n, greater<int>());
    
    scoreAlice = 0;
    scoreBob = 0;

    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            scoreAlice += pieces[i];
        } else {
            scoreBob += pieces[i]; 
        }
    }
}

void test(){
    int pieces1[] = {1, 3, 6, 7, 2, 1};
    int alice1, bob1;
    calculateScores(pieces1, 6, alice1, bob1);
    assert(alice1 == 11 && bob1 == 9);

    int pieces2[] = {7, 5, 2};
    int alice2, bob2;
    calculateScores(pieces2, 3, alice2, bob2);
    assert(alice2 == 9 && bob2 == 5);

    int pieces3[] = {10, 10, 5, 3};
    int alice3, bob3;
    calculateScores(pieces3, 4, alice3, bob3);
    assert(alice3 == 15 && bob3 == 13);

    int pieces4[] = {10};
    int alice4, bob4;
    calculateScores(pieces4, 1, alice4, bob4);
    assert(alice4 == 10 && bob4 == 0);
    
    cerr << "All test cases passed..." << endl;
}

int main(int argc, char* argv[]) {
    int n;
    int aliceScore, bobScore;

    if (argc > 1 && string(argv[1]) == "test") {
        test();
    } else {
        cin >> n;
        int pieces[100];
        for (int i = 0; i < n; ++i) {
            cin >> pieces[i];
        }

        calculateScores(pieces, n, aliceScore, bobScore);
        
        cout << aliceScore << " " << bobScore << endl;
    }
    return 0;
}
