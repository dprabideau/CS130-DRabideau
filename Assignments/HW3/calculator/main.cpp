/*
Author: Dayne Patrick Rabideau
Date: 09-17-2024

Description: program that performs some arithmetic operations on two given numbers entered by user
*/
#include <iostream>
#include <math.h>
#include <cassert>

using namespace std;

template <class T1>
T1 add(T1 a, T1 b);

template <class T1>
T1 sub(T1 a, T1 b);

template <class T1>
T1 mul(T1 a, T1 b);

template <class T1>
T1 div(T1 a, T1 b);



int main () {
    float a, b;
    a=3;
    b=4.125;
    if (roundf(a) == a && roundf(b) == b){
        cout << "Sum: " << add<int>(a, b) << endl;
        cout << "Difference: " << sub<int>(a, b) << endl;
        cout << "Product: " << mul<int>(a, b) << endl;
        cout << "Dividend: " << div<int>(a, b) << endl;
    }
    else {
        cout << "Sum: " << add<float>(a, b) << endl;
        cout << "Difference: "  << sub<float>(a, b) << endl;
        cout  << "Product: " << mul<float>(a, b) << endl;
        cout << "Dividend: " << div<float>(a, b) << endl;
    }

}

template <class T1>
    T1 add(T1 a, T1 b){
        return a+b;
    }

template <class T1>
    T1 sub(T1 a, T1 b){
        return a-b;
    }

template <class T1>
    T1 mul(T1 a, T1 b){
        return a*b;
    }

template <class T1>
    T1 div(T1 a, T1 b){
        return a/b;
    }