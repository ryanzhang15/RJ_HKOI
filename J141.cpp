#include <cstdio>
#include <algorithm>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

_ n, m, k, tm, ts, s, b, l, p;

int main() {
    
    s = 1E12;
    scanf("%lld%lld%lld%lld%lld", &n, &m, &k, &tm, &ts);
    //spam swipe all the way
    if(tm <= ts*m) s = min(s, ts*(k-1));
    b = (k+m-1)/m;
    l = (n+m-1)/m;
    p = k-m*(b-1);
    //wait until right before the very last pages are loaded, swipe left, then spam swipe the rest of the way
    if(b != 1) s = min(s, tm*(b-2)+max(tm, ts)+ts*p);
    //wait until everything is loaded, then swipe left
    s = min(s, tm*(b-1)+ts*((l == b ? n - k : m - p)+1));
    
    printf("%lld\n", s);
    
    return 0;
}
