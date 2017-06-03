/*
3 3 1 1
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
    ifstream in("garage.in");
    ofstream out("garage.out");

    //STARTS

    double W, H, w, h;
    in >> W >> H >> w >> h;
    double boxW = round((W/w)/2.0);
    // cout << boxW << endl;
    double boxH = round((H/h)/2.0);
    // cout << boxH << endl;

    out << (int)(boxW * boxH) << endl;

    //END

    return 0;
}