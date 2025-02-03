
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
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 2E4+8;

_ s, n, a[maxn], d[maxn], o;
struct node {
    _ p, s;
    bool operator < (const node &b) const {
        return s > b.s;
    }
};
priority_queue<node> q;
bitset<maxn> v;

int main(int argc, char * argv[]) {
    
    memset(d, 4, sizeof d);
    scanf("%lld%lld", &s, &n);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        if(a[i] > s) {
            --i;
            --n;
        }
    }
    if(!n) {
        printf("%lld\n", ((s+1)*s)>>1);
        exit(0);
    }
    sort(a+1, a+1+n);
    d[0] = 0;
    q.push((node){0, 0});
    for(; !q.empty(); ) {
        node t = q.top();
        q.pop();
        if(v[t.p]) continue;
        v.set(t.p);
        for(_ i = 2; i <= n; ++i) {
            _ x = (t.p+a[i])%a[1];
            if(d[x] > d[t.p]+a[i]) {
                d[x] = d[t.p]+a[i];
                q.push((node){x, d[x]});
            }
        }
    }
    for(_ i = 0; i <= a[1]-1; ++i) {
        _ l = (min(d[i], s+1)-i-1)/a[1]+1;
        o += (l*i+(((l-1)*l)>>1)*a[1]);
    }
    printf("%lld\n", o);
    
    return 0;
}


