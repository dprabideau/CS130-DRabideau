/*======================================================
    Author: Dayne Rabideau
    Date: 09-11-2024
    Description: Calculates a Projectiles Max Height 
    reached, Flight time and Distance travelled given 
    that the initial angle and speed are inputted
========================================================*/
#include <iostream>
#include <math.h>

using namespace std;

float alpha, muzzle_velocity, target_distance, max_height, flight_time, launch_distance, max_distance;
bool unit_type_meters = true;
float const g = 9.81;

int main(){
    do {
        cout << "Please input an angle between 0 and 90 degrees: ";
        cin >> alpha;
    }
    while ( alpha > 90 || alpha < 0 );
    alpha = alpha*M_PI/180;

    bool flag = false;
    cout << "Would you like to input your Muzzle Velocity / Launch Speed in either:" << endl << "a) Feet per second" << endl << "b) Meters per second" << endl << "Please type either a or b: ";
    do {
        string choice1;
        cin >> choice1;
        if (choice1 == "a"){
            unit_type_meters = false;
            flag = true;
        }
        else if (choice1 == "b"){
            flag = true;
        }
        else{
            cout << "Please chose a valid option: ";
        }
    }
    while (flag==false);
    cout << "Please enter your muzzle velocity / launch speed (in same units as chose above): ";
    cin >> muzzle_velocity;
    if (unit_type_meters==false){
        muzzle_velocity = muzzle_velocity*0.3048;
    }
    else {}
    cout << "Please input the distance from the launcher to the target (in the same unit you chose before): ";
    cin >> target_distance; //feet and meters conversion
    if (unit_type_meters == false) {
        target_distance = target_distance*0.3048;
    }{}
    max_height = (pow(muzzle_velocity,2))*((pow(sin(alpha),2))/(2*g));
    flight_time = (2*muzzle_velocity*sin(alpha))/(g);
    launch_distance = (pow(muzzle_velocity, 2)*sin(2*alpha))/g;
    
    max_distance = pow(muzzle_velocity, 2)/g;
    if (target_distance-max_distance<0){
        cout << "Target is within range." << endl;
    }
    else {
        cout << "Target is not within range." << endl;
    }
        cout << "Here is details about your projectile: " << endl;
    if (unit_type_meters==true){
        printf("Max height of projectile with given angle: %.2f meters\n", max_height);
        printf("Flight time of projectile with given angle: %.2f seconds\n", flight_time);
        printf("Distanced projectile was launched with given angle: %.1f meters\n", launch_distance);
    }
    else {
        printf("Max height of projectile with given angle: %.2f feet\n", max_height*3.28);
        printf("Flight time of projectile with given angle: %.2f seconds\n", flight_time);
        printf("Distanced projectile was launched with given angle: %.1f feet\n", launch_distance*3.28);
    }
}