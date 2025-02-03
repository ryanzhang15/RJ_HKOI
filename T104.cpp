
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

constant maxn = 1E5+8;
constant rtn = 350+8;
//constant rtn = 4;

_ n, a[maxn], b[rtn][rtn], p = 1;

void check(_ x);
void fillRC(_ l, _ x, char rc);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    reverse(a+1, a+1+n);
    for(_ i = 1; ; ++i) {
        fillRC(i, i-1, 'r');
        fillRC(i, i-1, 'c');
        b[i][i] = a[p++];
        if(p > n) check(i);
    }
    
    
    return 0;
}

void fillRC(_ l, _ x, char rc) {
    if(!x) return;
    if(rc == 'r') for(_ i = 1; i <= x && p <= n; ++i, ++p) b[l][i] = a[p];
    else for(_ i = 1; i <= x && p <= n; ++i, ++p) b[i][l] = a[p];
    if(p > n) check(l);
    return;
}

void check(_ x) {
    _ s = 0;
    for(_ i = 1; i <= x; ++i) {
        _ mx = 0;
        for(_ j = 1; j <= x; ++j) mx = max(mx, b[i][j]);
        s += mx;
    }
    for(_ i = 1; i <= x; ++i) {
        _ mx = 0;
        for(_ j = 1; j <= x; ++j) mx = max(mx, b[j][i]);
        s += mx;
    }
    printf("%lld\n", s);
    exit(0);
}
