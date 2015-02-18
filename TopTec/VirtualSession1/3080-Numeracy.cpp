/*
2
4
+
3
=
7
6
/
3
=
2
*/

//Accepted
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
  int cases;
  cin >> cases;
  while(cases--){
    double term1, term2, answer;
    char type, equal;
    cin >> term1 >> type >> term2 >> equal >> answer;
    switch(type){
      case '+':
        if(term1+term2 == answer)
          cout << "Yes" << endl;
        else
          cout << "No" << endl;
        break;
      case '-':
        if(term1-term2 == answer)
          cout << "Yes" << endl;
        else
          cout << "No" << endl;
        break;
      case '*':
        if(term1*term2 == answer)
          cout << "Yes" << endl;
        else
          cout << "No" << endl;
        break;
      case '/':
        if(term2 == 0) cout << "No" << endl;
        else if(term1/term2 == answer)
          cout << "Yes" << endl;
        else
          cout << "No" << endl;
        break;
      default:
        cout << "value of type unknown" << endl;

    }
  }
  return 0;
}
