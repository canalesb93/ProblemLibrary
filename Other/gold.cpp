/*
3
2 2 2
2 1 3
10 1000 24
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <utility>
#include <stdio.h>
#include <ctype.h>

using namespace std;

unsigned long long GCD(unsigned long long a, unsigned long long b)
{
    
    while( 1 )
    {
        a = a % b;
        if( a == 0 )
            return b;
        b = b % a;

        if( b == 0 )
            return a;
    }
}

int main()
{
    unsigned long long n;
    unsigned long long a, b;
    int t;
    cin >> t ;
    while(t--) {
        cin >> n >> a >> b;
        n = pow(2,n);
        long long gcd = GCD(a,b);
        int dias = 0;
        while ( n > gcd) { n /= 2; dias++; }

        cout << dias << endl;


    }






    return 0;
}