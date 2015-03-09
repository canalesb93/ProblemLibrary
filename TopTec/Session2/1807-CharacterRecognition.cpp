/* INCOMPLETE/ERRONOUS */

/*
3
Pr#nt ex##tly one##ine for#eac# te#t c#se.

NONE.

The i#put consists of
N test ca#es. The number
of th#m (N) is given on
the first #ine
of the#input#file.

*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <sstream>
#include <utility>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int main ()
{
  int cases;
  cin >> cases;
  string none;
  getline(cin, none);
  while(cases--){
    string all, temp;
    int tempsize;
    float total = 0, recognized = 0, unrecognized = 0;
    int totalint = 0;
    int counter = 0;
    do{
      getline(cin, temp);
      tempsize = temp.size();
      counter++;
      if(tempsize > 0){
        all += temp;
        total += tempsize;
      }
    }while(tempsize > 0 || counter <= 1);
    // cout << total << " " << all << endl;
    for(int i = 0; i < all.size(); i++){
      if(all[i] == '#')
        unrecognized++;
    }
    recognized = total - unrecognized;



    totalint = (recognized/total)*100;
    float decimals = ((recognized/total)*100 - totalint) * 10;
    int decimalint = round(decimals);
    // int decimalint = round(0.4);
    // cout << "int: " << totalint << " float: " << decimalint << endl;
    if(cases == 0){
      if(total == 0){
        printf("Efficiency ratio is 100%%.");
      } else if(decimalint == 0) 
        printf("Efficiency ratio is %d%%.", totalint);
      else
        printf("Efficiency ratio is %d.%d%%.", totalint, decimalint );

    } else {

    if(total == 0){
      printf("Efficiency ratio is 100%%.\n");
    } else if(decimalint == 0) 
      printf("Efficiency ratio is %d%%.\n", totalint);
    else
      printf("Efficiency ratio is %d.%d%%.\n", totalint, decimalint );

    }

  }


  return 0;
}
