
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
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E3+8;
constant mod = 1E9+7;

_ n, a[maxn], s;

_ fastPow(_ x);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    sort(a+1, a+1+n);
    for(_ i = 1; i <= n; ++i) s = (s + (a[i] * fastPow(n-i))%mod)%mod;
    printf("%lld\n", s);
    
    return 0;
}

_ fastPow(_ x) {
    if(!x) return 1;
    _ rv = (fastPow(x>>1)*fastPow(x>>1))%mod;
    if(x & 1) rv = (rv<<1)%mod;
    return rv;
}
