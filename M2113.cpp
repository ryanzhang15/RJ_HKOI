
#pragma G++ optimize("Ofast")

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
#include <random>
#include <unordered_map>

#include <chrono>
#include <thread>

#include <algorithm>
#include <numeric>
#define ef else if
#define mp(x, y) make_pair(x, y)
#define pb emplace_back
#define sz size()

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E5+8;
constant top = 8;
constant big = 11;
_ a[maxn], b[maxn], c[maxn];
vector<int> p;

vector<int> locate_light_poles(int N);
int measure(int x, int y);

int get(int x, int y) {
    if(!x) {
        if(~c[y]) return c[y];
        return c[y] = measure(x, y);
    }
    return measure(x, y);
}

void locate(_ l, _ r);
vector<int> locate_light_poles(int N) {
    
    memset(c, ~0, sizeof c);
    
    srand((unsigned)time(NULL));
//    srand(3);
    
    p = vector<int>(N);
    
    p[0] = 0;
    p[1] = measure(0, 1);
    _ n = N-2;
    for(_ i = 1; i <= n; ++i) a[i] = i+1;
    shuffle(a+1, a+1+n, default_random_engine(rand()));
    a[0] = 1;
    for(_ i = 1; i <= n; ++i) b[i] = measure(a[i-1], a[i]);
    for(_ i = 1; i <= n; i += big) locate(i, min((_)n, i+big-1));
    
    return p;
}

vector<_p> light(_ l, _ r) {
    vector<_p> ca, cb, cc;
    cc.pb(-b[l], 2);
    cc.pb(b[l], 0);
    for(_ i = l+1, k = 2; i <= r; ++i, ++k) {
        ca.clear();
        cb.clear();
        for(_ j = 0; j < cc.sz; ++j) {
            ca.pb(cc[j].first-b[i], cc[j].second | (1<<k));
            cb.pb(cc[j].first+b[i], cc[j].second);
        }
        _ pa = 0, pp = 0;
        cc.clear();
        for(; pa < ca.sz && pp < cb.sz; ) if(ca[pa] < cb[pp]) cc.pb(ca[pa++]);
        else cc.pb(cb[pp++]);
        for(; pa < ca.sz; ) cc.pb(ca[pa++]);
        for(; pp < cb.sz; ) cc.pb(cb[pp++]);
    }
    return cc;
}

void locate(_ l, _ r) {
    if(l == r) {
        _ vl = get(0, a[l]);
        if(p[a[l-1]]+b[l] == vl || p[a[l-1]]+b[l] == -vl) p[a[l]] = p[a[l-1]]+b[l];
        else p[a[l]] = p[a[l-1]]-b[l];
        return;
    }
    _ md = (l+r)>>1, vl = get(0, a[r]);
    vector<_p> ga = light(l, md), gb = light(md+1, r);
    _ ta = -1, tb = -1;
    bool ok = true;
    for(_ j = 0; j < ga.size(); ++j) {
        _p i = ga[j];
        _ na = upper_bound(gb.begin(), gb.end(), mp(vl-p[a[l-1]]-i.first, -1LL))-gb.begin();
        if(na >= gb.size() || gb[na].first != vl-p[a[l-1]]-i.first) continue;
        if(upper_bound(gb.begin(), gb.end(), mp(vl-p[a[l-1]]-i.first, (_)1E17))-gb.begin()-1 != na) {
            ok = false;
            break;
        }
        if(~ta) {
            ok = false;
            break;
        }
        ta = j;
        tb = na;
    }
    for(_ j = 0; ok && j < ga.size(); ++j) {
        _p i = ga[j];
        _ na = upper_bound(gb.begin(), gb.end(), mp(-vl-p[a[l-1]]-i.first, -1LL))-gb.begin();
        if(na >= gb.size() || gb[na].first != -vl-p[a[l-1]]-i.first) continue;
        if(upper_bound(gb.begin(), gb.end(), mp(-vl-p[a[l-1]]-i.first, (_)1E17))-gb.begin()-1 != na) {
            ok = false;
            break;
        }
        if(~ta) {
            ok = false;
            break;
        }
        ta = j;
        tb = na;
    }
    if(ok) {
        _ ds = p[a[l-1]];
        for(_ i = l, j = 1; i <= md; ++i, ++j) {
            if(ga[ta].second & (1<<j)) ds -= b[i];
            else ds += b[i];
            p[a[i]] = ds;
        }
        for(_ i = md+1, j = 1; i <= r; ++i, ++j) {
            if(gb[tb].second & (1<<j)) ds -= b[i];
            else ds += b[i];
            p[a[i]] = ds;
        }
    } else {
        locate(l, md);
        locate(md+1, r);
    }
    return;
}

#ifndef ONLINE_JUDGE

constant maaxn = 1E3;
_ aa[maaxn], mccc;
int measure(int x, int y) {
    ++mccc;
    return abs(aa[x]-aa[y]);
}

int main() {
    
    _ n; scanf("%lld", &n);
    for(_ i = 0; i < n; ++i) scanf("%lld", &aa[i]);
    vector<int> cr = locate_light_poles(n);
    for(_ i = 0; i < n; ++i) if(aa[i] != cr[i]) {
        puts("Bad!!");
        for(_ i : cr) printf("%lld ", i);
        putchar(10);
        exit(0);
    }
    puts("Good.");
    printf("Queried %lld times.\n", mccc);
    
    return 0;
}
#endif
