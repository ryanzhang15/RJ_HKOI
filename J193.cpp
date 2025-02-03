#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E4+8;

_ x, y, z, t, cnt;
struct out {
    _ a, b, c;
} o[maxn];

_ nudge(_ &a, _ &b, _ &c, _ k);
_ shift(_ &x, _ k);
int main() {
    
    scanf("%lld%lld%lld", &x, &y, &z);
    o[++cnt] = (out){x, y, z};
    for(; abs(x) >= 2 || abs(y) >= 2 || abs(z) >= 2; ) {
        if(abs(x) >= abs(y) && abs(x) >= abs(z)) {
            shift(x, 2);
            if(abs(y) >= abs(z)) shift(y, 1);
            else shift(z, 1);
        } ef(abs(y) >= abs(z)) {
            shift(y, 2);
            if(abs(x) >= abs(z)) shift(x, 1);
            else shift(z, 1);
        } else {
            shift(z, 2);
            if(abs(x) >= abs(y)) shift(x, 1);
            else shift(y, 1);
        }
        o[++cnt] = (out){x, y, z};
    }
    
    if(x == 1) nudge(x, y, z, 1);
    ef(!~x) nudge(x, y, z, -1);
    if(y == 1) nudge(y, x, z, 1);
    ef(!~y) nudge(y, x, z, -1);
    if(z == 1) nudge(z, x, y, 1);
    ef(!~z) nudge(z, x, y, -1);
    
    printf("%lld\n", cnt-1);
    for(_ i = 1; i <= cnt; ++i) printf("%lld %lld %lld\n", o[i].a, o[i].b, o[i].c);
    
    return 0;
}

_ shift(_ &x, _ k) {
    if(x & (1LL<<63)) x += k;
    else x -= k;
}

_ nudge(_ &a, _ &b, _ &c, _ k) {
    if(~k) {
        a -= 2;
        b += 1;
        o[++cnt] = (out){x, y, z};
        a += 1;
        c += 2;
        o[++cnt] = (out){x, y, z};
        c -= 2;
        b -= 1;
        o[++cnt] = (out){x, y, z};
    } else {
        a += 2;
        b += 1;
        o[++cnt] = (out){x, y, z};
        a -= 1;
        c += 2;
        o[++cnt] = (out){x, y, z};
        c -= 2;
        b -= 1;
        o[++cnt] = (out){x, y, z};
    }
}

