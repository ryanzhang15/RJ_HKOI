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

constant maxn = 2E5+88;
constant mod = 10007;

_ n, v[maxn], l, tl;
vector<_> g[maxn];

void dfs(_ p, _ s);
int main(int argc, char * argv[]) {
        
    freopen("link.in", "r", stdin);
    freopen("link.out", "w", stdout);
    
    cin >> n;
    for(_ i = 1; i < n; i++) {
        _ a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    for(_ i = 1; i <= n; i++) cin >> v[i];
    
    for(_ i = 1; i <= n; i++) {
        _ suma = 0, sumb = 0, maxa = 0, maxb = 0;
        if(g[i].size() == 1) continue;
        for(_ j : g[i]) {
            suma += v[j];
            sumb += v[j]*v[j];
            if(v[j] >= maxa) {
                maxb = maxa;
                maxa = v[j];
            } else if(j > maxb) {
                maxb = v[j];
            }
            l = max(l, maxa*maxb);
        }
        tl = (tl+suma*suma-sumb)%mod;
    }
    
    cout << l << ' ' << tl << endl;
    
    return 0;
}
