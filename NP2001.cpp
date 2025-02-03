#include <stdio.h>

typedef long long _;

_ n;

inline void write(_ x);
inline _ read();
int main() {
    
    freopen("power.in", "r", stdin);
    freopen("power.out", "a", stdout);
    
    n = read();
    if(n & 1) {
        putchar_unlocked('-');
        putchar_unlocked('1');
        putchar_unlocked(10);
    } else for(register _ i = 63; i >= 1; --i) if(n & (1LL<<i)) {
        write(1LL<<i);
        putchar_unlocked(32);
    }
    
    
    return 0;
}

inline _ read() {
    register _ x = 0; register char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; ch >= '0' && ch <= '9'; ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x;
}

inline void write(_ x) {
    if(x > 9) write(x/10);
    putchar_unlocked((x%10)^48);
    return;
}
