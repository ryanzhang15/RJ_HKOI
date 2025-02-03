
#include <cstdlib>
#include <iostream>
#include <cstdio>
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
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 5E5+8;

_ n, r, c, a[maxn], s, cr, sm;
bool pt;
priority_queue<_> q;

int main() {
    
    scanf("%lld%lld%lld", &n, &r, &c);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        pt |= a[i] > 0;
    }
    if(!pt) {
        puts("-1");
        exit(0);
    }
    s += r;
    for(_ i = 1; i <= n; ++i) {
        sm += a[i];
        if(a[i] < 0) q.push(-a[i]);
    }
    for(; sm <= 0; ) {
        s += c;
        sm += q.top();
        q.pop();
    }
    q = priority_queue<_>();
    sm = 0;
    bool wt = false;
    for(_ i = 1; i <= n; ++i) {
        sm += a[i];
        if(a[i] < 0) q.push(-a[i]);
        else wt = true;
        for(; !q.empty() && (wt ? sm <= 0 : sm < 0); q.pop()) {
            cr += c;
            sm += q.top();
        }
        if(wt ? sm <= 0 : sm < 0) {
            cr = 1E18;
            break;
        }
    }
    if(!wt) cr = 1E18;
    printf("%lld\n", min(cr, s));

    return 0;
}
