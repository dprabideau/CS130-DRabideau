/*
Author: Dayne Patrick Rabideau
Date: 09-19-2024
*/
#include <iostream>
#include <math.h>

using namespace std;

int main (){
    int articles, impact_factor;
    float answer;
    cin >> articles >> impact_factor;
    answer = articles * (impact_factor-0.999);
    cout << ceil(answer);
}
