#include <cstdio>
#include <vector>

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, m, l, x, y, z, cn[maxn];
struct event {
    _ t, c;
};
vector<event> a[maxn];
vector<_> g[maxn];
bool on[maxn];

int main() {

    scanf("%lld%lld%lld", &n, &m, &l);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &x);
        for(; x--; ) {
            scanf("%lld", &y);
            g[i].push_back(y);
        }
    }
    for(_ i = 1; i <= m; ++i) {
        scanf("%lld%lld", &x, &cn[i]);
        if(x) {
            a[cn[i]].push_back((event){0, 1});
            on[i] = true;
        }
    }
    for(; l--; ) {
        scanf("%lld%lld%lld", &x, &y, &z);
        if(!z) {
            if(on[y]) {
                a[cn[y]].push_back((event){x, -1});
                on[y] = false;
            } else {
                a[cn[y]].push_back((event){x, 1});
                on[y] = true;
            }
        } else {
            if(!on[y] || cn[y] == z) continue;
            a[cn[y]].push_back((event){x, -1});
            cn[y] = z;
            a[cn[y]].push_back((event){x, 1});
        }
    }
    for(_ i = 1; i <= n; ++i) a[i].push_back((event){(_)1E11, (_)1E11});
    for(_ i = 1; i <= n; ++i) {
        _ lp = 0, tm = g[i][0], cr = 0, d = 0, r = 0, c = 0;
        for(;;) if(a[i][d].t > tm) {
            c += (tm-lp)*r;
            printf("%.6Lf ", 1.L*c/g[i][cr]);
            lp = tm;
            if(++cr == g[i].size()) break;
            tm += g[i][cr];
            c = 0;
        } else {
            c += (a[i][d].t-lp)*r;
            r += a[i][d].c;
            lp = a[i][d].t;
            ++d;
        }
        putchar(10);
    }

    return 0;
}


