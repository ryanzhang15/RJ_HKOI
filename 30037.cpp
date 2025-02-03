
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E3+8;
_ n, a[maxn], s, i;

int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    sort(a+1, a+1+n);
    for(i = n; i >= 4; i -= 2) s += min((a[1]<<1)+a[i]+a[i-1], (a[2]<<1)+a[1]+a[i]);
    if(i == 1) s += a[1];
    ef(i == 2) s += a[2];
    else s += a[1] + a[2] + a[3];
    printf("%lld\n", s);
    for(_ j = n; j >= 4; j -= 2) {
        _ c1 = (a[1]<<1)+a[j]+a[j-1], c2 = (a[2]<<1)+a[1]+a[j];
        if(c1 < c2) printf("%lld %lld\n%lld\n%lld %lld\n%lld\n", a[1], a[j], a[1], a[1], a[j-1], a[1]);
        else printf("%lld %lld\n%lld\n%lld %lld\n%lld\n", a[1], a[2], a[1], a[j-1], a[j], a[2]);
    }
    if(i == 1) printf("%lld\n", a[1]);
    ef(i == 2) printf("%lld %lld\n", a[1], a[2]);
    else printf("%lld %lld\n%lld\n%lld %lld\n", a[1], a[2], a[1], a[1], a[3]);
    
    return 0;
}
