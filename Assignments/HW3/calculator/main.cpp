/*
Author: Dayne Patrick Rabideau
Date: 09-17-2024

Description: program that performs some arithmetic operations on two given numbers entered by user
Note: uses integer math if integers are inputted by the user
*/
#include <iostream>
#include <math.h>
#include <cassert>

#define MAX_ERROR 1e-5

using namespace std;

template <class T1>
T1 add(T1 a, T1 b);

template <class T1>
T1 sub(T1 a, T1 b);

template <class T1>
T1 mul(T1 a, T1 b);

template <class T1>
T1 div(T1 a, T1 b);

template <class T1>
T1 mod(T1 a, T1 b);

template <class T1>
T1 poww(T1 a, T1 b);

template <class T1>
T1 sqrtt(T1 a);

template <class T1>
T1 greatest(T1 a, T1 b);

void testFunc();


int main () {
    testFunc();
    float a, b;
    cout << "Notes: Functions will be executed by order of numbers inputted; eg. #1 / #2." << endl << "When integers are inputted for both values integer math will be used." << endl;
    cout << "Please enter a value for the first number: ";
    cin >> a;
    cout << "Please enter a value for the second number: ";
    cin >> b;
    if (roundf(a) == a && roundf(b) == b){
        string choice;
        cout << "Sum: " << add<int>(a, b) << endl;
        cout << "Difference: " << sub<int>(a, b) << endl;
        cout << "Product: " << mul<int>(a, b) << endl;
        cout << "Quotient: " << div<int>(a, b) << endl;
        cout << "Division Remainder: " << mod<int>(a, b) << endl;
        cout << "1#^2#: " << poww<int>(a, b) << endl;
        cout << "Would you like to find the square root of A) " << a << " or B) " << b << endl << "Please type either A or B: ";
        cin >> choice;
        if (choice == "A"){
            cout << "Square Root: " << sqrtt<int>(a) << endl;
        }
        else {
            cout << "Square Root: " << sqrtt<int>(b) << endl;
        }
    }
    else {
        string choice;
        cout << "Sum: " << add<float>(a, b) << endl;
        cout << "Difference: "  << sub<float>(a, b) << endl;
        cout  << "Product: " << mul<float>(a, b) << endl;
        cout << "Quotient: " << div<float>(a, b) << endl;
        cout << "Cannot do division remainder for floats at current c++ experience." << endl;
        cout << "1#^2#: " << poww<float>(a, b) << endl;
        cout << "Would you like to find the square root of A) " << a << " or B) " << b << endl << "Please type either A or B: ";
        cin >> choice;
        if (choice == "A"){
            cout << "Square Root: " << sqrtt<int>(a) << endl;
        }
        else {
            cout << "Square Root: " << sqrtt<int>(b) << endl;
        }
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

template <class T1>
    T1 mod(T1 a, T1 b){
        return a%b;
    }

template <class T1>
    T1 poww(T1 a, T1 b){
        return pow(a,b);
    }

template <class T1>
    T1 sqrtt(T1 a){
        return sqrt(a);
    }

template <class T1>
    T1 greatest(T1 a, T1 b){
        if (a>b){
            return a;
        }
        else {
            return b;
        }
    }

void testFunc() {
    float a, b;
    float answer, expected;
    //add test cases
    a = 12;
    b = 6;
    answer = add<int>(a,b);
    expected = 18;
    assert(abs(answer-expected) < MAX_ERROR);
    a = 0.75;
    b = 0.30;
    answer = add<float>(a,b);
    expected = 1.05;
    assert(abs(answer-expected) < MAX_ERROR);
    //sub test cases1
    a = 95;
    b = 25;
    answer = sub<int>(a,b);
    expected = 70;
    assert(abs(answer-expected) < MAX_ERROR);
    a = 0.95;
    b = 0.25;
    answer = sub<float>(a,b);
    expected = 0.70;
    assert(abs(answer-expected) < MAX_ERROR);
    //mul test cases1
    a = 5;
    b = 6;
    answer = mul<int>(a,b);
    expected = 30;
    assert(abs(answer-expected) < MAX_ERROR);
    a = 20;
    b = 0.25;
    answer = mul<float>(a,b);
    expected = 5;
    assert(abs(answer-expected) < MAX_ERROR);
    //div test cases1
    a = 100;
    b = 25;
    answer = div<int>(a,b);
    expected = 4;
    assert(abs(answer-expected) < MAX_ERROR);
    a = 2;
    b = 0.25;
    answer = div<float>(a,b);
    expected = 8;
    assert(abs(answer-expected) < MAX_ERROR);
    //mod test cases1
    a = 95;
    b = 25;
    answer = mod<int>(a,b);
    expected = 20;
    assert(abs(answer-expected) < MAX_ERROR);
    a = 13;
    b = 3;
    answer = mod<int>(a,b);
    expected = 1;
    assert(abs(answer-expected) < MAX_ERROR);
    //poww test cases1
    a = 2;
    b = 5;
    answer = poww<int>(a,b);
    expected = 32;
    assert(abs(answer-expected) < MAX_ERROR);
    a = 2.5;
    b = 3;
    answer = poww<float>(a,b);
    expected = 15.625;
    assert(abs(answer-expected) < MAX_ERROR);
    //sqrtt test cases1
    a = 64;
    answer = sqrtt<int>(a);
    expected = 8;
    assert(abs(answer-expected) < MAX_ERROR);
    a = 13.5;
    answer = sqrtt<float>(a);
    expected = 3.67423461417;
    assert(abs(answer-expected) < MAX_ERROR);
}