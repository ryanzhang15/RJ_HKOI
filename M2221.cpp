
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>
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
#define mp make_pair

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef long double _D;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, a[maxn], sz[maxn], dp[maxn], x, y, z, s = 1E18, c;
struct edge {
    _ to, cost;
};
vector<edge> g[maxn];
v_ o;

void fds(_ x, _ fa, _ ad, _ tsz);
void dfs(_ x, _ fa);
int main() {

    scanf("%lld", &n);
    for(_ i = n; --i; ) {
        scanf("%lld%lld%lld", &x, &y, &z);
        g[x].push_back((edge){y, z});
        g[y].push_back((edge){x, z});
    }
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
    dfs(1, -1);
    fds(1, -1, 0, 0);
    printf("%lld\n", s);
    sort(o.begin(), o.end());
    for(_ i : o) printf("%lld ", i);
    putchar(10);
    
    return 0;
}

void dfs(_ x, _ fa) {
    sz[x] = a[x];
    for(edge i : g[x]) if(i.to != fa) {
        dfs(i.to, x);
        sz[x] += sz[i.to];
        dp[x] += dp[i.to]+sz[i.to]*i.cost;
    }
    return;
}

void fds(_ x, _ fa, _ ad, _ tsz) {
    if(dp[x]+ad < s) {
        s = dp[x]+ad;
        o.clear();
        o.push_back(x);
    } ef(dp[x]+ad == s) o.push_back(x);
//    printf("at %lld, ds = %lld\n", x, dp[x]+ad);
    for(edge i : g[x]) if(i.to != fa) fds(i.to, x, ad+(tsz+sz[x]-sz[i.to])*i.cost+dp[x]-dp[i.to]-i.cost*sz[i.to], tsz+sz[x]-sz[i.to]);
    return;
}
