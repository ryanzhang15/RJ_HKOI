#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 3E3+8;

_ n, m, a[maxn], c[5], r, p, x, y, dsc, l[maxn];
vector<_> g[maxn];
char ch;

void bi(_ x, _ c);
void read7();
int main() {
    
    ch = getchar();
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= m; ++i) {
        scanf("%lld%lld", &x, &y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    if(ch == 'A') {
        for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
        for(_ i = 1; i <= n; ++i) if(g[i].size() >= 10) {
            c[++r] = (a[i]-1)>>1;
            if(r == 3) {
                bitset<7> o = c[1]+c[2]*5+c[3]*25;
                r = c[1] = c[2] = c[3] = 0;
                cout << o;
            }
        }
        bitset<7> o = c[1]+c[2]*5+c[3]*25;
        cout << o << endl;
    } else {
        scanf("%lld", &dsc);
        for(_ i = 1; i <= n; ++i) if(g[i].size() >= 10) {
            if(!r) {
                read7();
                r = 2;
            } else {
                --r;
                p /= 5;
            }
            x = p%5+1;
            l[i] = x;
        }
        for(_ i = 1; i <= n; ++i) if(l[i] && !a[i]) bi(i, l[i]<<1);
        for(_ i = 1; i <= n; ++i) if(!a[i]) for(_ j = 1; j <= 10; ++j) {
            bool ok = true;
            for(_ k : g[i]) if(a[k] == j) ok = false;
            if(ok) {
                a[i] = j;
                break;
            }
        }
        for(_ i = 1; i <= n; ++i) printf("%lld ", a[i]);
        putchar(10);
    }


    return 0;
}

void read7() {
    bitset<7> bt;
    for(_ i = 6; i >= 0; --i) {
        char ch = getchar();
        for(; ch != '1' && ch != '0'; ) ch = getchar();
        if(ch == '1') bt.set(i);
    }
    p = bt.to_ulong();
    return;
}

void bi(_ x, _ c) {
    a[x] = c;
    for(_ i : g[x]) if(l[i] == l[x] && !a[i]) bi(i, c & 1 ? c+1 : c-1);
    return;
}
