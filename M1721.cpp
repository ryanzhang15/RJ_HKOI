#include <cstdio>
#include <iostream>
#include <stack>
#include <queue>
#include <cmath>
#define ef else if
#define g getchar_unlocked()

using namespace std;

typedef long long _;
typedef long double _D;
typedef const long long constant;

constant maxn = 1E6+8;

_ n, d[maxn], a[maxn], b[maxn], p[maxn];
_D o1, o2;
struct node {
    _ p, a;
};
queue<node> q;
stack<node> s;

inline _ read();
int main() {
    
    n = read();
    for(_ i = 1; i <= n-1; ++i) d[i] = read();
    for(_ i = 1; i <= n-1; ++i) p[i] = p[i-1]+d[i];
    for(_ i = 1; i <= n; ++i) a[i] = read();
    for(_ i = 1; i <= n; ++i) b[i] = read();
    for(_ i = 1; i <= n; ++i) {
        //get people off
        _ sv = b[i];
        if(sv) {
            for(; q.front().a < sv; q.pop()) {
                o1 += sqrt((_D)(p[i-1]-p[q.front().p-1]))*q.front().a;
                sv -= q.front().a;
            }
            if(sv) {
                o1 += sqrt((_D)(p[i-1]-p[q.front().p-1]))*sv;
                q.front().a -= sv;
            }
            sv = b[i];
            for(; s.top().a < sv; s.pop()) {
                o2 += sqrt((_D)(p[i-1]-p[s.top().p-1]))*s.top().a;
                sv -= s.top().a;
            }
            if(sv) {
                o2 += sqrt((_D)(p[i-1]-p[s.top().p-1]))*sv;
                s.top().a -= sv;
            }
        }
        //get people on
        q.push((node){i, a[i]});
        s.push((node){i, a[i]});
    }
    printf("%.8Lf %.8Lf\n", o2, o1);
    
    return 0;
}

inline _ read() {
    _ x = 0; char ch = g;
    for(; !(ch >= '0' && ch <= '9'); ) ch = g;
    for(; ch >= '0' && ch <= '9'; ch = g) x = (x<<3)+(x<<1)+(ch^48);
    return x;
}
