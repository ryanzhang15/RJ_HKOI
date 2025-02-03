
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <ctime>
#include <map>
#include <numeric>
#include <random>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef long double _D;
typedef const long long constant;

constant maxn = 5E5+8;

_ a[maxn], b[maxn], n, m, dsc, x, y, t, q, op, cr, ln, cx, cy, pt, s;
char in[maxn];

_p ps(_ x);
void fig();
int main() {
    
    scanf("%lld%lld%lld%lld%lld %s%lld", &n, &m, &dsc, &x, &y, in+1, &q);
    fig();
    for(_ i = 1; i <= q; ++i) {
        scanf("%lld%lld", &op, &cr);
        if(op == 1) {
            x = ps(cr).first;
            y = ps(cr).second;
            scanf(" %s", in+1);
            fig();
            t = cr;
        } else {
            scanf("%lld%lld%lld", &cx, &cy, &pt);
            if(ps(cr).first == cx && ps(cr).second == cy) s += pt;
        }
    }
    printf("%lld %lld\n%lld\n", ps(dsc).first, ps(dsc).second, s);
    
    return 0;
}

void fig() {
    ln = strlen(in+1);
    for(_ i = 1; i <= ln; ++i) {
        a[i] = a[i-1];
        b[i] = b[i-1];
        if(in[i] == 'U') --a[i];
        ef(in[i] == 'D') ++a[i];
        ef(in[i] == 'L') --b[i];
        else ++b[i];
        a[i] %= n;
        b[i] %= m;
    }
    return;
}

_p ps(_ tm) {
    _p rv = mp(x, y);
    _ el = tm-t;
    rv.first += ((__int128)a[ln]*(el/ln))%n;
    rv.second += ((__int128)b[ln]*(el/ln))%m;
    rv.first += a[el%ln]%n;
    rv.second += b[el%ln]%m;
    rv.first = (rv.first%n+n)%n;
    rv.second = (rv.second%m+m)%m;
    return rv;
}
