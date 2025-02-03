

/*
 template by c8kbf
 */

// macOS doesn't have <bits/stdc++.h> (shame)
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
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <algorithm>
#include <numeric>
#include <random>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef set<_>::iterator _i;
typedef const long long constant;

constant maxn = 1E6+8;

set<_> b, h;
_ n, a[maxn], x, y, z, l, r, md;
str cmd;

int main() {
    
    scanf("%lld", &n);
    for(; n--; ) {
        cin >> cmd;
        if(cmd == "write") {
            scanf("%lld%lld", &x, &y);
            a[y] = x;
            _i t = h.insert(y).first;
            b.insert(y);
            if(t != h.begin()) {
                --t;
                if(a[*t] > a[y]) b.insert(*t);
                else b.erase(*t);
            }
            t = h.upper_bound(y);
            if(t != h.end() && a[*t] >= a[y]) b.erase(y);
        } else {
            scanf("%lld%lld%lld", &x, &y, &z);
            _i t = h.lower_bound(y);
            if(t == h.end()) {
                puts("No");
                continue;
            }
            l = *t;
            t = h.upper_bound(z);
            if(t == h.begin()) {
                puts("No");
                continue;
            }
            r = *(--t);
            if(r < l) {
                puts("No");
                continue;
            }
            if(b.lower_bound(l) != b.lower_bound(r)) {
                puts("No sort, no search");
                continue;
            }
            bool ok = false;
            for(; l <= r; ) {
                md = (l+r)>>1;
                t = h.lower_bound(md);
                _ c, c1 = 1E11, c2 = -1E11;
                c1 = *t;
                if(t != h.begin()) c2 = *(--t);
                c = (c1-md < md-c2) ? c1 : c2;
                if(a[c] == x) {
                    ok = true;
                    break;
                } ef(a[c] < x) {
                    t = h.lower_bound(md+1);
                    if(t == h.end()) break;
                    l = *t;
                } else {
                    t = h.upper_bound(md-1);
                    if(t == h.begin()) break;
                    r = *(--t);
                }
            }
            puts(ok ? "Yes" : "No");
        }
    }
    
    return 0;
}
