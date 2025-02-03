
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

typedef int _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 5E6+8;

struct edge {
    _ to, cost;
};
_ n, a, b, s, e, z, d[maxn];
queue<_> q;
bitset<maxn> v;

int main() {
    
    memset(d, 4, sizeof d);
    scanf("%d%d%d%d%d", &n, &a, &b, &s, &e);
    q.push(s);
    d[s] = 0;
    v.set(s);
    for(; !q.empty(); ) {
        _ t = q.front();
        q.pop();
        v.reset(t);
        for(_ j = 1; j <= n; ) {
            if(t == j) {
                ++j;
                continue;
            }
            if((a*t+j)%b < 3) {
                if(d[j] > d[t]+(a*t+j)%b+1) {
                    d[j] = d[t]+(a*t+j)%b+1;
                    if(!v[j]) {
                        v.set(j);
                        q.push(j);
                    }
                }
                ++j;
            } else j += b-(a*t+j)%b;
        }
    }
    
    if(d[e] > 6E7) puts("-1");
    else printf("%d\n", d[e]);
    
    return 0;
}

