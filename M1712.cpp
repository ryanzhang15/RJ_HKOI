
#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <bitset>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <numeric>

#define ef else if

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 5E2+8;
constant maxm = 1E5+8;
constant mod = 1E9+7;
_ n, m, a[maxn], f[maxm], dp[maxm], cnt;
unordered_map<_, _> p;

void getFactors();
int main() {
        
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    getFactors();
    for(_ i = 1; i <= n; ++i) for(_ j = cnt; j >= 1; --j) {
        if(m % a[i]) break;
        if((m/f[j]) < a[i] || m % (f[j]*a[i])) continue;
        dp[p[f[j]*a[i]]] = (dp[p[f[j]*a[i]]]+dp[j]+(j==1))%mod;
    }
    
    printf("%lld\n", dp[cnt]+(m==1));
    
    return 0;
}

void getFactors() {
    for(_ i = 1; i <= sqrt(m); ++i) if(!(m%i)) {
        f[++cnt] = i;
        if(i != sqrt(m) || ceil(sqrt(m)) != floor(sqrt(m))) f[++cnt] = m/i;
    }
    sort(f+1, f+1+cnt);
    for(_ i = 1; i <= cnt; ++i) p[f[i]] = i;
    return;
}
