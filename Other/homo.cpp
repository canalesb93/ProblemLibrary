/*
11
insert 1
insert 2
insert 1
insert 4
delete 1
delete 3
delete 2
delete 1
insert 4
delete 4
delete 4
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <ctime>
#include <iterator>
#include <limits>
#include <fstream>

using namespace std;

#define F(i, b, a) for( int i = (b); i < (a); i++ )
#define Set(a, s) memset(a, s, sizeof (a))
#define INF (int)2e9

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mpii;
typedef set<int> seti;

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w+", stdout);
    ifstream in("homo.in");
    ofstream out("homo.out");

    //STARTS

    int operations;
    in >> operations;
    string type;
    ll num;
    bool homo = false, hetero = false;
    map<ll, ll> bank;
    int pairs = 0;
    int total= 0;
    while(operations--){
      in >> type >> num;
      if(type == "insert"){
        if(bank[num] == 1){
          pairs++;
        }
        bank[num]++;
      } else {
        if(bank[num] > 0){
          total--;
          bank[num]--;
          if(bank[num] == 1)
            pairs--;
        }
        if(bank[num] == 0){
          bank.erase(num);
        }
      }
      
      if(pairs > 0)
        homo = true;
      else 
        homo = false;
      if(bank.size() > 1) 
        hetero = true;
      else
        hetero = false;

      if(homo && hetero){
        out << "both" << endl;
      } else if(homo){
        out << "homo" << endl;
      } else if(hetero){
        out << "hetero" << endl;
      } else {
        out << "neither" << endl;
      }

    }

    //END

    return 0;
}