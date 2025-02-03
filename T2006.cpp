
#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E2+8;

_ n, r[maxn], a, b, c, d, t[maxn], f[maxn];
bool trip;

void fillr(_ w, _ h);
bool check();
void case2();
void case1();
void out();
int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld%lld", &r[i], &t[i]);
    r[n+1] = -1;
    
    case1();
    case2();
    puts("Impossible");
    
    return 0;
}

void out() {
    printf("%lld %lld\n%lld %lld\n", a, b, c, d);
    exit(0);
}

void case1() {
    if(n == 1) return;
    a = r[n];
    b = r[n] * t[n];
    if(n == 2) {
        c = r[n-1];
        d = r[n-1]*t[n-1];
        out();
    }
    memset(f, 0, sizeof f);
    f[n] = t[n];
    trip = false;
    fillr(r[n-1]*t[n-1]+r[n-2], r[n-1]);
    if(!trip && check()) {
        c = r[n-1]*t[n-1]+r[n-2];
        d = r[n-1];
        out();
    }
    for(_ i = n-1; i >= 1; --i) {
        memset(f, 0, sizeof f);
        f[n] = t[n];
        trip = false;
        fillr(r[n], r[i]);
        if(trip || check()) continue;
        _ slst = -1, snst = -1;
        bool flag = false;
        for(_ j = n-1; j >= 1 && !flag; --j) {
            if(f[j] > t[j]) flag = true;
            if(!~snst && ~slst && f[j] < t[j]) snst = j;
            if(!~slst && f[j] < t[j]) slst = j;
        }
        if(flag) continue;
        if(!~snst) {
            b += r[i];
            c = r[slst];
            d = r[slst]*(t[slst]-f[slst]);
            out();
        }
        trip = false;
        _ sv = r[slst]*(t[slst]-f[slst])+r[snst];
        fillr(r[slst], r[slst]*(t[slst]-f[slst])+r[snst]);
        if(trip) continue;
        if(check()) {
            b += r[i];
            c = r[slst];
            d = sv;
            out();
        }
    }
    return;
}

void case2() {
    if(t[n] == 1) return;
    a = c = d = r[n];
    b = r[n]*(t[n]-1);
    if(n == 1) out();
    for(_ i = n-1; i >= 1; --i) {
        memset(f, 0, sizeof f);
        f[n] = t[n];
        trip = false;
        fillr(r[n], r[i]);
        if(trip) continue;
        if(check()) {
            b += r[i];
            out();
        }
        _ slst = -1;
        bool flag = false;
        for(_ j = n-1; j >= 1; --j) {
            if(f[j] > t[j]) flag = true;
            if(!~slst && f[j] < t[j]) slst = j;
        }
        if(flag) continue;
        trip = false;
        fillr(r[n], r[slst]);
        if(trip) continue;
        if(check()) {
            b += r[i];
            d += r[slst];
            out();
        }
    }
    return;
}

bool check() {
    for(_ i = 1; i <= n; ++i) if(t[i] != f[i]) return false;
    return true;
}

void fillr(_ w, _ h) {
    if(!w || !h) return;
    if(w < h) swap(w, h);
    _ nd = lower_bound(r+1, r+1+n, h)-r;
    if(r[nd] != h) {
        trip = true;
        return;
    }
    f[nd] += w/h;
    fillr(w%h, h);
    return;
}

