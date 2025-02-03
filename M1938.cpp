
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
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 3E5+8;

_ n, m, q, a[maxn], x;

_ bSearch();
int main() {
    
    scanf("%lld%lld%lld", &n, &m, &q);
    for(_ i = 1; i <= m; ++i) scanf("%lld", &a[i]);
    sort(a+1, a+1+m);
    for(; q--; ) {
        scanf("%lld", &x);
        printf("%lld ", bSearch()+x);
    }
    putchar(10);
    
    return 0;
}

_ bSearch() {
    _ l = 1, r = m, md, s = 0;
    for(; l <= r; ) {
        md = (l+r)>>1;
        if(a[md] < x+md) {
            s = md;
            l = md+1;
        } else r = md-1;
    }
    return s;
}
