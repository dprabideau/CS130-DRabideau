/*
Author: Dayne Rabideau
Date: 10-26-2024
Description:  Takes input consisting of number of names and the names, then 
    determines if alpabetical and increasing or decreasing
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string determineOrder(const string names[], int num) {
    bool isDescend = true, isAscend = true;

    for(int i = 0; i < num - 1; i++) {
        int result = names[i].compare(names[i + 1]);
        if (result > 0) {
            isAscend = false;
        } else if (result < 0) {
            isDescend = false;
        }
    }

    if (isAscend) {
        return "INCREASING";
    } else if (isDescend) {
        return "DECREASING";
    } else {
        return "NEITHER";
    }
}

void test() {
    string names1[]= {"A", "B", "C", "D"};
    int nums = sizeof(names1);
    assert(determineOrder(names1, nums)=="INCREASING");
    string names2[]= {"E", "D", "C", "B", "A"};
    nums = sizeof(names2);
    assert(determineOrder(names2, nums)=="DECREASING");
    string names3[]= {"B", "A", "C"};
    nums = sizeof(names3);
    assert(determineOrder(names3, nums)=="NIETHER");
    string names4[]= {"B", "A", "C"};
    nums = sizeof(names4);
    assert(determineOrder(names4, nums)=="NIETHER");
    cerr << "All test cases passed..." << endl;
}

int main(int argc, char* argv[]) {
    int num;
    string names[20];

    if (argc > 1 && string(argv[1]) == "test") {
        test();
    } else {
        cin >> num;
        for (int i = 0; i < num; i++) {
            cin >> names[i];
        }

        cout << determineOrder(names, num) << endl;
    }
    return 0;
}