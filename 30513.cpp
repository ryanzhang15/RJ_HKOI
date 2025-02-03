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
typedef const long long constant;

constant maxn = 50+8;

_ n, s = 1, b[maxn];
bool p[maxn], pl[maxn], mn[maxn], a[maxn][maxn];

inline void dfs(_ x);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) {
        char in[maxn];
        scanf(" %s", in+1);
        if(in[1] == '?') for(_ j = 0; j <= n-1; ++j) a[i][j] = true;
        else for(_ j = 1; in[j]; ++j) a[i][in[j]-'A'] = true;
    }
    for(_ i = 1; i <= n; ++i) {
        _ c = 0;
        for(_ j = 0; j <= n-1; ++j) if(a[i][j]) ++c;
        s *= c;
    }
    dfs(1);
    printf("%lld\n", s);
    
    return 0;
}

inline void dfs(_ x) {
    if(x > n) {
        --s;
        return;
    }
    for(_ i = 0; i <= n-1; ++i) if(a[x][i]) {
        if(p[i] || (x >= 2 && abs(i-b[x-1]) == 2) || (x >= 3 && abs(i-b[x-2]) == 1) || pl[x+i] || mn[i-x+n+1]) continue;
        b[x] = i;
        p[i] = pl[x+i] = mn[i-x+n+1] = true;
        dfs(x+1);
        p[i] = pl[x+i] = mn[i-x+n+1] = false;
    }
    return;
}
