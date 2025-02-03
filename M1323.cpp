#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

_ a, fa, b, fb, n, l = -2E9+8, r = 2E9+8, md, s = -1;

char check(_ x);
int main() {
    
    scanf("%lld%lld%lld%lld%lld", &a, &fa, &b, &fb, &n);
    //find f_(a-1) with binary search, then you know the whole sequence
    if(a > b) {
        swap(a, b);
        swap(fa, fb);
    }
    for(; l <= r; ) {
        md = (l+r)>>1;
        char ch = check(md);
        if(ch == '=') {
            s = md;
            break;
        } ef(ch == '>') r = md-1;
        else l = md+1;
    }
    if(n == a) printf("%lld\n", fa);
    ef(n > a) {
        _ c = fa, l = s;
        for(_ i = a+1; i <= n; ++i) {
            _ sv = l;
            l = c;
            c += sv;
        }
        printf("%lld\n", c);
    } else {
        _ c = s, l = fa;
        for(_ i = a-2; i >= n; --i) {
            _ sv = l;
            l = c;
            c = sv-c;
        }
        printf("%lld\n", c);
    }
    
    
    return 0;
}

char check(_ x) {
    _ c = fa, l = x;
    for(_ i = a+1; i <= b; ++i) {
        _ sv = l;
        l = c;
        c += sv;
        if(c > 2E9) return '>';
    }
    if(c == fb) return '=';
    ef(c > fb) return '>';
    else return '<';
}
