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
#include <bitset>

#include <algorithm>
#include <numeric>

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxab = 1E6+8;

_ n, a, b, dp[maxab];

inline _ read();
int main() {
    
    n = read();
    a = read();
    b = read();
    if(n == 1) {
        puts("0");
        exit(0);
    }
    for(_ i = 0; i < max(a, b); ++i) dp[i] = 1;
    for(_ i = max(a, b); ; ++i) {
        dp[i] = dp[i-a] + dp[i-b];
        if(dp[i] >= n) {
            printf("%lld\n", i);
            break;
        }
    }
    
    
    return 0;
}

inline _ read() {
    _ x = 0;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; (ch >= '0' && ch <= '9'); ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x;
}
