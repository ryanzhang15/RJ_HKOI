
#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 300;

_ n, m, l, y, w[maxn];
vector<_> g[maxn];
struct node {
    char c;
    _ s;
};
queue<node> q;
char c, d;

int main() {
    
    scanf("%lld%lld", &n, &m);
    l = n-3;
    for(_ i = 1; i <= 3; ++i) {
        scanf(" %c", &c);
        q.push((node){c, 0});
        w[c] = 1E10;
    }
    for(; m--; ) {
        scanf(" %c%c", &c, &d);
        g[c].push_back(d);
        g[d].push_back(c);
    }
    for(; !q.empty(); q.pop()) for(_ i = 0; i < g[q.front().c].size(); ++i) if(++w[g[q.front().c][i]] == 3) {
        q.push((node){g[q.front().c][i], q.front().s+1});
        y = max(y, q.front().s+1);
        --l;
    }
    if(l) puts("THIS BRAIN NEVER WAKES UP");
    else printf("WAKE UP IN, %lld, YEARS\n", y);
    
    return 0;
}
