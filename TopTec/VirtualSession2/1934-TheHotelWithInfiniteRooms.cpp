/*
1 6
3 10
3 14
1 55
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <stdio.h>


using namespace std;

int main()
{
  long s,d,i,n;
  while(scanf("%ld%ld",&s,&d)==2){
    n=0;
    i=s;
    while(true){
      n+=i;
      cout << "start at " << n<< endl;
      if(n>=d){
        printf("%ld\n",i);
        break;
      }
      i++;
    }
  }
  return 0;
}