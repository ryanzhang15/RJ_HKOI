#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;

_ n, m, c;

_ guess(_ l, _ r);
bool ask(_ x);
bool isSmaller(_ x);
int main() {
    
    scanf("%lld%lld", &n, &m);
    printf("C %lld\n", guess(1, n));
    
    return 0;
}

bool ask(_ x) {
    printf("Q %lld\n", x);
    fflush(stdout);
    _ rd;
    scanf("%lld", &rd);
    return !!rd;
}

bool isSmaller(_ x) {
    if(c) {
        --c;
        return ask(x);
    }
    bool a = ask(x), b = ask(x);
    if(a == b) return a;
    bool d = ask(x);
    if(d == a) {
        c = m-1;
        return d;
    } else {
        c = m-2;
        return d;
    }
}

_ guess(_ l, _ r) {
    if(l == r) return l;
    _ md = ((l+r)>>1)+1;
    if(isSmaller(md)) return guess(l, md-1);
    else return guess(md, r);
}
