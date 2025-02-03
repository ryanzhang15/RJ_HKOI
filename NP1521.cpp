

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
typedef const long long maxn;

maxn mn = 5e4+88;
_ l, n, m, rocks[mn], ans;

bool check(_ n);

int main(int argc, char * argv[]) {
    
    freopen("stone.in", "r", stdin);
    freopen("stone.out", "w", stdout);
    
    cin >> l >> n >> m;
    rocks[n] = l;
    for(_ i = 0; i < n; i++) cin >> rocks[i];
    
    _ l = 0, r = 1e9, md;
    while(l <= r) {
        md = (l+r)/2;
        if(check(md)) {
            ans = md;
            l = md + 1;
        } else {
            r = md - 1;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}

bool check(_ val) {
    _ pr = 0, cnt = 0;
    for(_ i = 0; i <= n; i++) {
        if(rocks[i] - pr < val) cnt++;
        else pr = rocks[i];
        if(cnt > m) return false;
    }
    return true;
}
