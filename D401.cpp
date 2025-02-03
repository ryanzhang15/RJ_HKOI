
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
typedef double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E7+8;

_ n, primes[maxn], isnPrime[maxn], pc;

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    cin >> n;
    //we're actually gonna use euler's sieve
    //its so much faster
    
    isnPrime[0] = isnPrime[1] = true;
    for(_ i = 2; i <= n; i++) {
        if(!isnPrime[i]) {
            primes[pc++] = i;
            cout << i << endl;
        }
        //this part is so broken
        for(_ j = 0; j < pc; j++) {
            if(i * primes[j] > n) break;
            isnPrime[i * primes[j]] = true;
            if(!(i % primes[j])) break;
        }
    }
    
    return 0;
}

