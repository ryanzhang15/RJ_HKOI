#include <cstdio>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

_ n;

int main() {
    
    scanf("%lld", &n);
    if(n % 4) {
        ++n;
        n >>= 2;
        for(_ i = (n<<2)-4; i >= (n<<1); i -= 2) printf("%lld ", i);
        printf("%lld ", (n<<2)-2);
        for(_ i = (n<<1)-3; i >= 1; i -= 2) printf("%lld ", i);
        printf("%lld ", (n<<2)-1);
        for(_ i = 1; i <= (n<<1)-3; i += 2) printf("%lld ", i);
        for(_ i = n<<1; i <= (n<<2)-4; i += 2) printf("%lld ", i);
        printf("%lld ", (n<<1)-1);
        for(_ i = (n<<2)-3; i >= (n<<1)+1; i -= 2) printf("%lld ", i);
        printf("%lld ", (n<<2)-2);
        for(_ i = (n<<1)-2; i >= 2; i -= 2) printf("%lld ", i);
        printf("%lld %lld ", (n<<1)-1, (n<<2)-1);
        for(_ i = 2; i <= (n<<1)-2; i += 2) printf("%lld ", i);
        for(_ i = (n<<1)+1; i <= (n<<2)-3; i += 2) printf("%lld ", i);
        putchar(10);
    } else {
        n >>= 2;
        for(_ i = (n<<2)-4; i >= n<<1; i -= 2) printf("%lld ", i);
        printf("%lld ", (n<<2)-2);
        for(_ i = (n<<1)-3; i >= 1; i -= 2) printf("%lld ", i);
        printf("%lld ", (n<<2)-1);
        for(_ i = 1; i <= (n<<1)-3; i += 2) printf("%lld ", i);
        for(_ i = n<<1; i <= (n<<2)-4; i += 2) printf("%lld ", i);
        printf("%lld ", (n<<2));
        for(_ i = (n<<2)-3; i >= (n<<1)+1; i -= 2) printf("%lld ", i);
        printf("%lld ", (n<<2)-2);
        for(_ i = (n<<1)-2; i >= 2; i -= 2) printf("%lld ", i);
        printf("%lld %lld ", (n<<1)-1, (n<<2)-1);
        for(_ i = 2; i <= (n<<1)-2; i += 2) printf("%lld ", i);
        for(_ i = (n<<1)+1; i <= (n<<2)-3; i += 2) printf("%lld ", i);
        printf("%lld %lld\n", (n<<1)-1, (n<<2));
    }
    
    
    return 0;
}
