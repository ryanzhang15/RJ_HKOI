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

#define fs(str) (str).c_str()
#define _lin "%lli"
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
#define _llllin "%lli%lli%lli%lli"
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 5E5+88;
//constant maxn = 15;

struct target {
    _ x, s;
} a[maxn];

_ n, d, k, l = 0, r = 1E9, m, s = -1, dp[maxn], f;
deque<_> q;

bool check(_ g);
int main(int argc, char * argv[]) {
    
    freopen("jump.in", "r", stdin);
    freopen("jump.out", "w", stdout);
    
    scanf(_lllin, &n, &d, &k);
    for(_ i = 1; i <= n; ++i) scanf(_llin, &a[i].x, &a[i].s);
    
    while(l <= r) {
        m = (l+r)/2;
        if(check(m)) {
            s = m;
            r = m-1;
        } else l = m+1;
    }
    
    printf(fs(_l+"\n"), s);
    
    return 0;
}

bool check(_ g) {
    q.clear();
    f = 0;
    for(_ i = 1; i <= n; ++i) {
        for(; f < i && a[i].x - a[f].x >= d-g; ++f) {
            if(a[i].x - a[f].x > d+g) continue;
            for(; !q.empty() && dp[q.back()] <= dp[f]; q.pop_back()) /*say goodbye*/;
            q.push_back(f);
        }
        for(; !q.empty() && (a[i].x - a[q.front()].x > d+g || a[i].x - a[q.front()].x < d-g); q.pop_front()) /*say hello*/;
        if(q.empty()) {
            dp[i] = -1E10;
            continue;
        }
        dp[i] = a[i].s + dp[q.front()];
        if(dp[i] >= k) return true;
    }
    return false;
}

