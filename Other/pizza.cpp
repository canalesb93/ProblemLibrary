/*
5 4
500 Margherita
600 Salami
700 Hawai
800 Speciale
900 Doener
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

int main(){
  int pizza_count, favorite;
  int trash;
  string whatever;

  cin >> pizza_count >> favorite;

  int votes = (pizza_count-1) / 3;
  int min_range = votes;
  int max_range = pizza_count - votes;

  switch(pizza_count % 3){
    case 0: {
      max_range--;
      min_range++;
      break;
    }
    case 1: {
      break;
    }
    case 2: {
      max_range--;
      break;
    }
  }

  for (int i = 0; i < pizza_count; ++i)
    cin >> trash >> whatever;

  if (min_range < favorite && favorite <= max_range){
    cout << "YES" << "\n";
  } 
  else {
    cout << "NO" << "\n";
  }

  return 0;
}