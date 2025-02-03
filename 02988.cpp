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

constant maxn = 1E4+8;

_ n, m, p, pc, primes[maxn];
bool isNPrime[maxn];

_ sumOfDigits(_ n);
int main(int argc, char * argv[]) {
    
    cin >> n >> m >> p;
    isNPrime[0] = isNPrime[1] = true;
    for(_ i = 2; i <= m; i++) {
        if(!isNPrime[i]) {
            primes[pc++] = i;
            if(i >= n && sumOfDigits(i) == p) cout << i << endl;
        }
        for(_ j = 0; j < pc; j++) {
            if(i * primes[j] > m) break;
            isNPrime[i * primes[j]] = true;
            if(!(i % primes[j])) break;
        }
    }
    
    cout << "Finish!" << endl;
    
    return 0;
}

inline _ sumOfDigits(_ n) {
    _ sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
