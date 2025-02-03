
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
#include <numeric>

#define fs(str) (str).c_str()
#define _l "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define ef else if
std::string l_ = _l;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E2+8;

struct branch {
    _ v, w;
};

_ n, q, dp[maxn][maxn];
vector<branch> g[maxn];

void dfs(_ p, _ f);
int main(int argc, char * argv[]) {
    
    cin >> n >> q;
    for(_ i = 1; i < n; i++) {
        _ a, b, c; cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    
    dfs(1, -99);
    
    cout << dp[1][q] << endl;
    
    return 0;
}

void dfs(_ p, _ f) {
    for(branch i : g[p]) {
        if(i.v == f) continue;
        dfs(i.v, p);
        for(_ j = q; j > 0; j--)
            for(_ k = 0; k < j; k++)
                dp[p][j] = max(dp[p][j], dp[i.v][k] + dp[p][j-k-1] + i.w);
    }
    return;
}

