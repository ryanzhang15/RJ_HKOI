
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

constant maxn = 2E5+8;

_ n, parent[maxn], dp[maxn], ans = 1E18;

_ find(_ p);
int main(int argc, char * argv[]) {
    
    freopen("message.in", "r", stdin);
    freopen("message.out", "w", stdout);
    
    cin >> n;
    for(_ i = 1; i <= n; i++) parent[i] = i;
    
    for(_ i = 1; i <= n; i++) {
        _ a; cin >> a;
        _ u = find(a), v = find(i);
        if(u == v) {
            ans = min(ans, dp[a]+1);
        } else {
            parent[v] = u;
            dp[i] = dp[a] + 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}

_ find(_ p) {
    if(parent[p] == p) return p;
    else {
        _ a = parent[p];
        parent[p] = find(parent[p]);
        dp[p] += dp[a];
        return parent[p];
    }
}
