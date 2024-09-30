/*
Author: Dayne Rabideau
Date: 09-27-2024
Description: Takes two integer inputs and outputs them from smaller to larger
*/
#include <iostream>

using namespace std;

int main () {
    int a, b;
    cin >> a >> b;
    if (a>b){
        cout << b << " " << a;
    }
    else {
        cout << a << " " << b;
    }
    return 0;
}
