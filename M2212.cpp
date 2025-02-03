
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>

#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

void not_swap(int i, int j);
void shift(int i, int j, int k);
void answer(int N, std::vector<int> A);

// TODO: global variables can be declared here
constant maxn = 1E5+8;
_ a[maxn], n, d[maxn];
vector<v_> b, c;
v_ cr, ta, tb;
bitset<maxn> v;

void dfs(_ x);
void answer(int N, std::vector<int> A) {
    if(N == 1) return;
    n = N;
    for(_ i = 1; i <= n; ++i) a[i] = d[i] = A[i-1];
    sort(d+1, d+1+n);
    for(_ i = 1; i <= n; ++i) a[i] = lower_bound(d+1, d+1+n, a[i])-d;
    for(_ i = 1; i <= n; ++i) if(!v[i]) {
        cr.clear();
        dfs(i);
        if((_)cr.size() & 1) b.push_back(cr);
        else c.push_back(cr);
    }
    for(v_ t : b) if(t.size() > 1) for(_ i = 1; i < t.size(); i += 2) shift(t[0], t[i], t[i+1]);
    for(; c.size() >= 2; ) {
        ta = c.back();
        c.pop_back();
        tb = c.back();
        c.pop_back();
        for(_ i = 1; i < (_)ta.size()-1; i += 2) shift(ta[0], ta[i], ta[i+1]);
        for(_ i = 1; i < (_)tb.size()-1; i += 2) shift(tb[0], tb[i], tb[i+1]);
        shift(ta[0], ta.back(), tb[0]);
        shift(tb.back(), tb[0], ta[0]);
        
    }
    if(!c.empty()) {
        ta = c.back();
        for(_ i = 1; i < (_)ta.size()-1; i += 2) shift(ta[0], ta[i], ta[i+1]);
        not_swap(ta[0], ta.back());
    }
}

void dfs(_ x) {
    if(v[x]) return;
    v.set(x);
    cr.push_back(x-1);
    dfs(a[x]);
    return;
}

#ifndef ONLINE_JUDGE

_ nn, ns, tt[maxn], sv[maxn], sw;
vector<int> aa;

int main() {
    
    scanf("%lld", &nn);
    for(_ i = 1; i <= nn; ++i) {
        scanf("%d", &tt[i]);
        aa.push_back(tt[i]);
    }
    answer(nn, aa);
    printf("used %lld shifts, %lld swaps\n", sw, ns);
    puts("final array:");
    for(_ i = 1; i <= nn; ++i) printf("%d ", tt[i]);
    putchar(10);
    for(_ i = 1; i <= nn; ++i) sv[i] = tt[i];
    sort(tt+1, tt+1+nn);
    bool ok = true;
    for(_ i = 1; i <= nn; ++i) if(sv[i] != tt[i]) ok = false;
    puts(ok ? "GOOD!!" : "BAD");
    
    return 0;
}

void not_swap(int i, int j) {
    ++ns;
    swap(tt[i+1], tt[j+1]);
}

void shift(int i, int j, int k) {
    ++sw;
    swap(tt[i+1], tt[j+1]);
    swap(tt[k+1], tt[i+1]);
}

#endif
