/*
Kattis - Simon Says

Updated By: Dayne Rabideau
Date: 10/24/2024

Problem Statement: https://open.kattis.com/problems/simonsays 
Algorithm steps:
1. Read N
2. Loop N times:
  i. Read a line
  ii. If the line starts with "Simon says",
    print the rest of the string. Note: print the leading space after says as well!
  iii. Otherwise, skip the line
*/

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// function prototypes
string answer(const string &line);
void testAnswer();
void solve();

int main(int argc, char* argv[]) {
  if (argc == 2 and string(argv[1]) == "test") {
    // FIXME1: call testAnswer function
    //FIXED
    testAnswer();
  }
  else
    solve();
}

string answer(const string &line) {
  // FIXME2: If the line starts with "Simon says", return rest of the line after says
  // including the space after says, otherwise return empty string ""
  // Hint: use find method on line object
  //FIXED
  if (line.find("Simon says")==0) {
    //cout << line.substr(11);
    return line.substr(11);
  }
  else {
    return "";
  }
}

// unit testing answer()
void testAnswer() {
  string ans = answer("Simon says laugh!");
  // let's double check what the returned answer is
  cerr << "ans = " << ans << endl;
  assert(ans == " laugh!"); 
  assert(answer("Write more programs.") == "");
  // FIXME3: write at least two test cases to test answer()
  //FIXED
  ans = answer("Simon says jump");
  cerr << "ans = " << ans << endl;
  assert(ans == " jump"); 
  assert(answer("Write more programs.") == "");
  ans = answer("Simon says spin");
  cerr << "ans = " << ans << endl;
  assert(ans == " spin"); 
  assert(answer("Write more programs.") == "");
  cerr << "All test cases passed!\n";
}

// solving the problem for kattis
void solve() {
  string ans="", line="";
  int N;
  cin >> N;
  //FIXME4 : read and discard \n left behind
  //FIXED
  cin.ignore();
  while (N--) {
    // Note: i. string consists of phrase with spaces
    // ii. don't print an empty line if the line doesn't start with "Simon says"
    // FIXME5: read the whole line into line 
    //FIXED
    getline(cin, line);
    // FIXME6: call answer function and store the returned value into ans
    //FIXED
    ans = answer(line);

    if (ans == "") continue;
      // FIXME7: print ans
      //FIXED
      if (ans != "") 
      cout << ans << endl;
  }
}
