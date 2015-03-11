/*
17 20
3
1 100 15 20
96 2
10 50 21 49
48 27
1 1 1 100000
15 15
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

int gcd( int a, int b ){
  while ( b ){
    b ^= a;
    a ^= b;
    b  = (b^a) % a;
  }
  return a;
}

int main ()
{ 
  int G, A;
  int rounds;
  int andersAns, garfieldsAns;
  int anders = 0, garfield = 0;
  scanf("%d %d", &G, &A);
  scanf("%d", &rounds);


  // 2 arreglos de cada uno de 100,000
  // en cada uno vas guardando el acumulativo

  int andersArray[100010] = { 0 };
  int garfieldArray[100010] = { 0 };
  int totalAnders = 0, totalGarfield = 0;
  for(int i = 1; i <= 100000; i++){
    if(gcd(G, i) == 1){
      totalAnders++;
    }
    andersArray[i] = totalAnders;
    if(gcd(A, i) == 1){
      totalGarfield++;
    }
    garfieldArray[i] = totalGarfield;
  }
  // printf("%d %d\n", G, A);
  // printf("%d\n", rounds);

  while(rounds--){
    int gi, gj, ai, aj;
    scanf("%d %d %d %d", &gi, &gj, &ai, &aj);
    scanf("%d %d", &andersAns, &garfieldsAns);
    int andersCount = 0, garfieldCount = 0;
    // ANDERS
    andersCount = andersArray[gj] - andersArray[gi-1];
    if(andersCount == andersAns)
      anders += 2;
    else 
      anders -= 1;
    printf("Round %d, Anders count(%d and %d): %d, Anders answer: %d, Anders Score: %d.\n", rounds, gi, gj, andersCount, andersAns, anders);
    // GARFIELD
    garfieldCount = garfieldArray[aj] - garfieldArray[ai-1];
    if(garfieldCount == garfieldsAns)
      garfield += 2;
    else 
      garfield -= 1;

    printf("Round %d, Garfield count(%d and %d): %d, Garfield answer: %d, Garfield Score: %d.\n", rounds, ai, aj, garfieldCount, garfieldsAns, garfield);
  }
  printf("Garfield Score: %d\n", garfield);
  printf("Anders Score: %d\n", anders);
  if(garfield > anders)
    printf("Garfield wins\n");
  else if(garfield < anders)
    printf("Anders wins\n");
  else
    printf("Draw\n");
  return 0;
}
