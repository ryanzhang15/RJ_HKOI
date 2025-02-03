
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <ctime>
#include <map>
#include <numeric>
#include <random>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define ef else if
#define mp make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef long double _D;
typedef const long long constant;

constant maxn = 2E5+8;

_ n, m, t[maxn][26], d[maxn], mk[maxn], cnt = 1, s = -1E11, nd;
str o, sv;
vector<str> g;

void op(_ x);
void dfs(_ x, _ dt);
int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) {
        _ p = 1;
        for(_ j = 1; j <= m; ++j) {
            char ch;
            scanf(" %c", &ch);
            _ dx = ch-'A';
            if(!t[p][dx]) t[p][dx] = ++cnt;
            p = t[p][dx];
        }
        ++d[p];
        ++mk[p];
    }
    dfs(1, 0);
    op(nd);
    printf("%lld\n", (_)g.size());
    for(str i : g) printf("%s%s\n", sv.c_str(), i.c_str());
    
    return 0;
}

void dfs(_ x, _ dt) {
    for(_ i = 0; i < 26; ++i) if(t[x][i]) {
        o += 'A'+i;
        dfs(t[x][i], dt+1);
        d[x] += d[t[x][i]];
        o.pop_back();
    }
    if(d[x]*dt > s) {
        s = d[x]*dt;
        nd = x;
        sv = o;
    }
    return;
}

void op(_ x) {
    for(_ i = 0; i < 26; ++i) if(t[x][i]) {
        o += 'A'+i;
        op(t[x][i]);
        o.pop_back();
    }
    for(; mk[x]--; ) g.push_back(o);
    return;
}
