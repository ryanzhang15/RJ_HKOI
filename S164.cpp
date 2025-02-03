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

constant maxn = 1E5+88;

_ f[2], g[2], n, k, a[maxn], ans;
_0 t = 1, l;

int main(int argc, char * argv[]) {
    
    //eating one dish per minute is not healthy
    cin >> n >> k;
    for(_ i = 1; i <= n; i++) cin >> a[i];
    for(_ i = 1; i <= k; i++) {
        g[0] += a[i];
        f[0] += a[i] * i;
    }
    ans = f[0];
    for(_ i = 2; i <= n-k+1; t = !t, l = !l, i++) { //some shady stuff
        g[t] = g[l] - a[i-1] + a[i+k-1];
        f[t] = f[l] - g[l] + a[i+k-1]*k;
        ans = max(ans, f[t]);
    }
    
    cout << ans << endl;
    
    return 0;
}
