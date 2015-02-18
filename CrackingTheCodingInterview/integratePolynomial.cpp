/*
*/
#include <iostream>

using namespace std;
struct term{
  int coef;
  int exp;
};

int main ()
{
  int size =3;
  term poly[] = { {3,0} , {4,1} , {6,2} };
  term integral[size];
  for(int i = 0; i < size; i++){
    int exponent = poly[i].exp + 1;
    if (!(exponent < 0)){
      int divided = poly[i].coef / exponent;
      integral[i].exp = exponent;
      integral[i].coef = divided;
    }
  }
  for(int i =0; i < size; i++){
    cout << poly[i].coef << "x^" << poly[i].exp;
    if(i != size-1)
      cout << " + ";
  }
  cout << endl;
  for(int i =0; i < size; i++){
    cout << integral[i].coef << "x^" << integral[i].exp << " + ";
  }
  cout << "C" << endl;

  return 0;
}
