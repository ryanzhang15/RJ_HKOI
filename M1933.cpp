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
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <algorithm>
#include <numeric>
#include <random>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 20+8;
constant maxp = 1E2+8;
constant mod = 1E9+7;

struct edge {
    _ u, v;
} a[maxn];

bitset<maxn> t;
_ n, d, p[maxp];
__int128 s;
bitset<maxp> c;

void operator ++ (bitset<maxn> &x);
bool operator < (const bitset<maxn> x, const _ y);
int main() {

    p[0] = 1;
    for(_ i = 1; i <= 100; ++i) p[i] = p[i-1]*2%mod;
    
    scanf("%lld%lld", &n, &d);
    for(_ i = 0; i < d; ++i) scanf("%lld%lld", &a[i].u, &a[i].v);
    for(t = 1; t < (1LL<<d); ++t) {
        c.reset();
        for(_ i = 0; i < d; ++i) if(t[i]) {
            c.set(a[i].u);
            c.set(a[i].v);
        }
        if(t.count() & 1) s = (s+t.count()*p[n-c.count()]%mod)%mod;
        else s = ((s-t.count()*p[n-c.count()]%mod)%mod+mod)%mod;
    }
    printf("%lld\n", (_)s);
    
    return 0;
}

void operator ++ (bitset<maxn> &x) {
    x = x.to_ulong()+1;
}

bool operator < (const bitset<maxn> x, const _ y) {
    return x.to_ulong() < y;
}
