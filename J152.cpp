
#include <bits/stdc++.h>
#define ef else if
#define g getchar_unlocked()

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = (1<<16)+8;

struct applicant {
    _ c;
    bool s;
    void get() {
        char ch = g;
        for(; ch != '0' && ch != '1'; ) ch = g;
        for(; ch == '0' || ch == '1'; ch = g) c = (c<<1) | (ch == '1');
        c = c<<1;
        for(; ch != '0' && ch != '1'; ) ch = g;
        s = ch == '1';
        return;
    }
} a[maxn];

_ n, p[maxn], d[maxn], b[maxn], ts, sn;
list<_> v, u;

bool willRemove(_ x);
_ vOf(_ ind, _ s);
int main() {
    
    scanf("%lld", &n);
    sn = n;
    n = 1<<n;
    for(_ i = 1; i <= n; ++i) a[i].get();
    for(_ i = 1; i <= n; ++i) u.push_back(i);
    n = sn;
    for(_ i = 1; i <= n; ++i) v.push_back(i);
    for(ts = 1; ts <= n-1; ++ts) {
        bool ok = false;
        list<_>::iterator i;
        for(i = v.begin(); i != v.end(); ++i) for(_ j = 0; j <= 1; ++j) {
            _ c = -1;
            for(list<_>::iterator k = u.begin(); k != u.end(); ++k) if(vOf(*k, *i) == j) {
                _ th = a[*k].s;
                if(!~c) c = th;
                ef(th != c) {
                    ok = true;
                    break;
                }
            }
            if(ok) ok = false;
            else {
                p[ts] = *i;
                d[ts] = j;
                b[ts] = c;
                ok = true;
                goto nice;
            }
        }
    nice:
        if(!ok) {
            puts("Impossible");
            exit(0);
        }
        v.erase(i);
        u.remove_if(willRemove);
        //printf("LEFT: ");
        //for(list<_>::iterator t = u.begin(); t != u.end(); ++t) printf("%lld ", *t);
        //putchar(10);
    }
    p[n] = v.front();
    if(a[u.front()].s == a[u.back()].s) {
        puts("Impossible");
        exit(0);
    }
    if(a[u.front()].s) d[n] = vOf(u.front(), p[n]);
    else d[n] = vOf(u.back(), p[n]);
    
    for(_ i = 1; i <= n-1; ++i) printf("%lld %lld %lld\n", n-p[i]+1, d[i], b[i]);
    printf("%lld %lld\n", n-p[n]+1, d[n]);
    
    return 0;
}

_ vOf(_ ind, _ s) {
    return !!(a[ind].c & (1<<s));
}

bool willRemove(_ x) {
    return vOf(x, p[ts]) == d[ts];
}
