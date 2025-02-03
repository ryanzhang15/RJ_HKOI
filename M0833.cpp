//#include <bits/stdc++.h>
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
typedef const long long constant;

constant maxn = 1E3+8;
_ n, m, s, t, x, y, z, d[maxn];
struct edge {
    _ to, cost;
};
vector<edge> g[maxn], b[maxn];
queue<_> q;
bitset<maxn> v;

int main() {
    
    memset(d, 4, sizeof d);
    scanf("%lld%lld%lld%lld", &n, &m, &s, &t);
    for(; m--; ) {
        scanf("%lld%lld%lld", &x, &y, &z);
        g[x].push_back((edge){y, z});
        b[y].push_back((edge){x, z});
    }
    
    q.push(t);
    d[t] = 0;
    v.set(t);
    for(; !q.empty(); q.pop()) {
        _ c = q.front();
        v.reset(c);
        for(_ i = 0; i < b[c].size(); ++i) if(d[b[c][i].to] > d[c] + b[c][i].cost) {
            d[b[c][i].to] = d[c] + b[c][i].cost;
            if(!v[b[c][i].to]) {
                v.set(b[c][i].to);
                q.push(b[c][i].to);
            }
        }
    }
    
    if(d[s] > 1E12) {
        puts("No Path");
        exit(0);
    }
    printf("%lld: %lld ", d[s], s);
    _ now = s, c = 0;
    for(; now != t; ) {
        _ dx = 1E18, ds = 0;
        for(_ i = 0; i < g[now].size(); ++i) if(c + g[now][i].cost + d[g[now][i].to] == d[s] && dx > g[now][i].to) {
            dx = g[now][i].to;
            ds = g[now][i].cost;
        }
        c += ds;
        now = dx;
        printf("%lld ", now);
    }
    putchar(10);
    
    return 0;
}


