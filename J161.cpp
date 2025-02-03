
#include <bits/stdc++.h>
#define ef else if

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
_ n, p, x, y, z;
char a[maxn], b[maxn], c[maxn], s[maxn];

void out();
int main() {
    
    scanf("%lld%lld", &n, &p);
    scanf(" %s %s %s", a+1, b+1, c+1);
    x = p;
    y = z = p-1;
    //a_i != b_i and a_i != c_i
    for(_ i = 1; i <= n; ++i) {
        if(a[i] != b[i] && a[i] != c[i]) {
            s[i] = a[i];
            --x;
        }
        if(!x) out();
    }
    //a_i == b_i
    for(_ i = 1; i <= n && y; ++i) {
        if(s[i]) continue;
        if(a[i] == b[i] && a[i] != c[i]) {
            s[i] = a[i];
            --x;
            --y;
        }
        if(!x) out();
    }
    //a_i == c_i
    for(_ i = 1; i <= n && z; ++i) {
        if(s[i]) continue;
        if(a[i] == c[i] && a[i] != b[i]) {
            s[i] = a[i];
            --x;
            --z;
        }
        if(!x) out();
    }
    //a_i == c_i and a_i == b_i
    for(_ i = 1; i <= n && y && z; ++i) {
        if(s[i]) continue;
        s[i] = a[i];
        --y;
        --z;
        --x;
        if(!x) out();
    }
    
    out();
    return 0;
}

void out() {
    if(x) {
        puts("Impossible");
        exit(0);
    }
    for(_ i = 1; i <= n; ++i) if(s[i]) putchar(s[i]);
    else for(char j = 'A'; j <= 'C'; ++j) if(j != b[i] && j != c[i]) {
        putchar(j);
        break;
    }
    exit(0);
}
