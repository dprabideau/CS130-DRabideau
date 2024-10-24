#include <iostream>
#include <string>

using namespace std;

int main() {
    int num;
    bool isDescend = true, isAscend = true;
    string names[20];

    cin >> num;
    for(int i=0;i<num;i++)
    {
        cin >> names[i];
    }

    for(int i=0;i<num-1;i++)
    {
        int result = names[i].compare(names[i+1]);
        if (result > 0) {
            isAscend = false;
        } else if (result < 0) {
            isDescend = false;
        } else {/*Could be Equal if same name*/}
    }

    cout << endl;
    if (isAscend == true){
        cout << "INCREASING" << endl;
    }
    else if (isDescend == true){
        cout << "DECREASING" << endl;
    }
    else {
        cout << "NEITHER" << endl;
    }

    return 0;
}