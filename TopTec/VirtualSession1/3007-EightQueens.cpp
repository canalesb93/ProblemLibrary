/*
*.......
......*.
....*...
.......*
.*......
...*....
.....*..
..*.....
*/
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#define BOARDSIZE 8

using namespace std;

int main ()
{ 
  int queens = 0;
  bool row[BOARDSIZE] = { 0 };
  bool col[BOARDSIZE] = { 0 };
  int locations[2][8] = { {0} };
  char marker;
  for(int i = 0; i < BOARDSIZE; i++){
    for(int j = 0; j < BOARDSIZE; j++){
      cin >> marker;
      if(marker == '*'){
        if(row[i] || col[j]){

          // cout << "row/col repetes" << endl;
          cout << "invalid";
          return 0;
        }
        // cout << "RUN NUMBER: " << queens << " QUEEN AT: " << i << " " << j <<endl;
        for(int x = 0; x < queens; x++){
          int comp1 = abs(locations[0][x] - i);
          int comp2 = abs(locations[1][x] - j);
          // cout << "for queen: "<< x <<", position: " << i << "-" << j << ", differences: " << comp1 << " " << comp2 << endl; 
          if(comp1 == comp2){
            cout << "invalid";
            return 0;
          } 
        }
        locations[0][queens] = i;
        locations[1][queens] = j;
        ++queens;
        row[i] = true;
        col[j] = true;
      }
    }
  }
  if(queens < 8){
    cout << "invalid";
  } else {
    cout << "valid";
  }
  return 0;
}
