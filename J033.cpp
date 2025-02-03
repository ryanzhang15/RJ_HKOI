#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>

#include <algorithm>
#include <numeric>

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E9+88;
constant maxp = 1E6; //just a guess

_ primes[maxp];
bool isNPrime[maxn];

_ n, pc;

int main(int argc, char * argv[]) {
    
    cin >> n;
    
    isNPrime[0] = isNPrime[1] = true;
    for(_ i = 2; i <= n; i++) {
        if(!isNPrime[i]) primes[pc++] = i;
        for(_ j = 0; j < pc && i*primes[j] <= n; j++) {
            isNPrime[i*primes[j]] = true;
            if(!(i % primes[j])) break;
        }
    }
    
    //goldbach's conjecture has been tested to 400,000,000,000,000 \
        so we will not consider impossible \
        lol
    
    _ ansa = 0, ansb = 0;
    for(_ i = pc-1; i >= 0 && primes[i] >= n/2; i--) {
        if(!isNPrime[n-primes[i]]) {
            ansa = n-primes[i];
            ansb = primes[i];
        }
    }
    
    cout << min(ansa, ansb) <<' '<< max(ansa, ansb) << endl;
    
    return 0;
}
