#pragma GCC optimize("O0")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")

#include <stdio.h>
#include <stdlib.h>
#include <bitset>

inline int read();
int main() {
    
    int n, m, cnt = 0, a[2097152], tp, p = 1, s = 0, g;
    std::bitset<2097152> v;
    
    n = read();
    m = read();
    for(register int i = 1; i <= n; ++i) a[i] = read();
    while(!v[p]) {
        v.flip(p);
        p = a[p];
        if(++s == m) {
            printf("%d\n", p);
            return 0;
        }
    }
    
    tp = p;
    do {
        p = a[p];
        if(++s == m) {
            printf("%d\n", p);
            return 0;
        }
        ++cnt;
    } while(p != tp);
    
    g = (m-s)%cnt;
    for(register int s = 1; s <= g; ++s) p = a[p];
    
    printf("%d\n", p);
    
    return 0;
}

inline int read()
{
    int x=0; char ch=getchar_unlocked();
    while (ch >= '0' && ch <= '9'){x=x*10+ch-48;ch=getchar_unlocked();}
    return x;
}

