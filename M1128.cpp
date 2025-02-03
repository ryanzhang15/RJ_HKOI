#include <cstdio>
#include <cstdlib>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

_ n, k, u;

void fail();
int main() {
    
    scanf("%lld%lld%lld", &n, &k, &u);
    if(u == 1 || (u == 2 && !(n % 2)) || (k == 1 && !(n % u))) fail();
    if(k == 1 || (k == 2 && u == 2)) {
        printf("%lld\n", n);
        exit(0);
    }
    _ mx = k - !(k % u);
    if(!mx || (k == 1 && !(n % u))) fail();
    _ o = (n-1)/mx+1;
    if(!(n % k % u) && n % k == k-1) ++o;
    if(!(o % u)) ++o;
    printf("%lld\n", o);
    
    return 0;
}

void fail() {
    puts("-1");
    exit(0);
}
