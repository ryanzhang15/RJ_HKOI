//#include <bits/stdc++.h>
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
typedef pair<pair<_, _>, char> _p;
typedef const long long constant;

constant maxn = 50+8;

_ n, m, s, k, o;
set<_p> t;
struct ship {
    _ x, y, d;
    char l;
} a[maxn];

int main() {

    //idea: total number of placements - bad placements

    scanf("%lld%lld%lld", &n, &m, &s);
    for(_ i = 1; i <= s; ++i) scanf("%lld%lld%lld %c", &a[i].x, &a[i].y, &a[i].d, &a[i].l);
    scanf("%lld", &k);

    for(_ i = 1; i <= s; ++i) if(a[i].l == 'V') {
        for(_ j = a[i].x-1; j <= a[i].x+a[i].d; ++j) for(_ l = a[i].y-k; l <= a[i].y+1; ++l) if(j >= 1 && l >= 1 && j <= n && l+k-1 <= m) t.insert(make_pair(make_pair(j, l), 'h'));
        for(_ j = a[i].x-k; j <= a[i].x+a[i].d; ++j) for(_ l = a[i].y-1; l <= a[i].y+1; ++l) if(j >= 1 && l >= 1 && j+k-1 <= n && l <= m) t.insert(make_pair(make_pair(j, l), k == 1 ? 'h' : 'v'));
    } else {
        for(_ j = a[i].x-1; j <= a[i].x+1; ++j) for(_ l = a[i].y-k; l <= a[i].y+a[i].d; ++l) if(j >= 1 && l >= 1 && j <= n && l+k-1 <= m) t.insert(make_pair(make_pair(j, l), 'h'));
        for(_ j = a[i].x-k; j <= a[i].x+1; ++j) for(_ l = a[i].y-1; l <= a[i].y+a[i].d; ++l) if(j >= 1 && l >= 1 && j+k-1 <= n && l <= m) t.insert(make_pair(make_pair(j, l), k == 1 ? 'h' : 'v'));
    }

    if(k == 1) o = n*m;
    else o = max(0LL, (n-k+1)*m) + max(0LL, (m-k+1)*n);
    printf("%lld\n", max(0LL, (_)(o-t.size())));

    return 0;
}