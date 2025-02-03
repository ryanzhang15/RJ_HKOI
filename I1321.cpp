
#ifdef __cplusplus
extern "C" {
#endif
int tryCombination(int S[]);
void answer(int S[], int D[]);
void exploreCave(int N);
#ifdef __cplusplus
}
#endif

#include <bits/stdc++.h>
using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E3+8;

bitset<maxn> v;
_ n;
int s[maxn], d[maxn];

void toggle(_ x, _ y) {
    for(_ i = x; i <= y; ++i) if(!v[i]) s[i] ^= 1;
    return;
}

void bSearch(_ x) {
    _ l = 0, r = n-1, md, c, p, t;
    c = tryCombination(s);
    p = c != x;
    for(; l != r; ) {
        md = (l+r)>>1;
        toggle(l, md);
        c = tryCombination(s);
        t = c != x;
        toggle(l, md);
        if(p != t) r = md;
        else l = md+1;
    }
    s[l] = !p;
    d[l] = x;
    v.set(l);
    return;
}

void exploreCave(int N) {
    n = N;
    for(_ i = 0; i < n; ++i) bSearch(i);
    answer(s, d);
    return;
}
