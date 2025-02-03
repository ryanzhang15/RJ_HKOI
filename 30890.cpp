#include <bits/stdc++.h>

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 30+8;

_ n, t, s, cb;
pair<_, _> a[maxn];
bool v[maxn];

void dfs(_ tc, _ d, pair<_, _> l);
pair<_, _> getPair();
int main() {
        
    scanf("%lld%lld%lld", &n, &t, &s);
    for(_ i = 1; i <= t; ++i) a[i] = getPair();
    cb = 1E14;
    dfs(0, 1, make_pair(0, 0));
    printf("%lld\n", cb);
    
    return 0;
}

pair<_, _> getPair() {
    pair<_, _> rv;
    scanf("%lld%lld", &rv.first, &rv.second);
    return rv;
}

void dfs(_ tc, _ d, pair<_, _> l) {
    if(d > s) {
        tc += abs(n - 1 - l.first) + abs(n - 1 - l.second);
        cb = min(cb, tc);
        return;
    }
    if(tc > cb) return;
    for(_ i = 1; i <= t; ++i) if(!v[i]) {
        v[i] = true;
        dfs(tc + abs(l.first - a[i].first) + abs(l.second - a[i].second), d+1, a[i]);
        v[i] = false;
    }
    return;
}
