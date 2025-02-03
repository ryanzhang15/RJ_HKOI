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
typedef const long long constant;

constant maxn = 5E5+8;

_ n;
struct party {
    _ l, r;
    bool operator < (const party &b) const {
        if(l+r != b.l+b.r) return l+r < b.l+b.r;
        return l < b.l;
    }
} a[maxn];

void no();
int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld%lld", &a[i].l, &a[i].r);
        a[i].l <<= 1;
        a[i].r <<= 1;
    }
    sort(a+1, a+1+n);
    _ t = 0;
    for(_ i = 1; i <= n; ++i) if(i != n && a[i].l+a[i].r == a[i+1].l+a[i+1].r) {
        if(a[i].l >= t) t = a[i+1].r;
        ef(a[i+1].l >= t) t = a[i].r;
        else no();
        ++i;
    } else {
        t = max(t, a[i].l);
        if(t + ((a[i].r-a[i].l)>>1) > a[i].r) no();
        t += (a[i].r-a[i].l)>>1;
    }
    puts("YES");
    
    return 0;
}

void no() {
    puts("NO");
    exit(0);
}

