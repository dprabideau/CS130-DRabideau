/*======================================================
    Author: Dayne Rabideau
    Date: 09-11-2024
    Description: Calculates a Projectiles Max Height 
    reached, Flight time and Distance travelled given 
    that the initial angle and speed are inputted
========================================================*/
#include <iostream>

using namespace std;

double alpha, muzzle_velocity, target_distance;
bool unit_type_meters = true;

int main(){
    do {
        cout << "Please input an angle between 0 and 90 degrees: ";
        cin >> alpha;
    }
    while ( alpha > 90 || alpha < 0 );

    bool flag = false;
    cout << "Would you like to input your Muzzle Velocity / Launch Speed in either:" << endl << "a) Feet per second" << endl << "b) Meters per second" << endl << "Please type either a or b: ";
    do {
        string choice1;
        cin >> choice1;
        if (choice1 == "a"){
            cout << "a";
            unit_type_meters = false;
            flag = true;
        }
        else if (choice1 == "b"){
            cout << "b";
            flag = true;
        }
        else{
            cout << "Please chose a valid option: ";
        }
    }
    while (flag==false);
    cout << "Please enter your muzzle velocity / launch speed: ";
    cin >> muzzle_velocity;
    if (unit_type_meters==false){
        muzzle_velocity = muzzle_velocity*0.3048;
    }
    else {}
    
    
}