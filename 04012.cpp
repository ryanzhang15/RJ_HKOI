#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

typedef long long _;
typedef const long long constant;

_ n, cnt, s = 1;

void recur(_ x, _ c, _ ld);
int main() {
    
    scanf("%lld", &n);
    //check if n is valid
    for(_ i = 1; i <= 30; ++i) if(n & (1<<i) && n & (1<<(i-1))) {
        puts("0");
        exit(0);
    }
    //recursively find answer
    recur(0, 0, 0);
    printf("%lld\n", s);
    
    return 0;
}

void recur(_ x, _ c, _ ld) {
    if(x >= 31 || c >= n) return;
    s += ld;
    recur(x+1, c, 0);
    if(!x || !(c & (1<<(x-1)))) recur(x+1, c | (1<<x), 1);
    return;
}
