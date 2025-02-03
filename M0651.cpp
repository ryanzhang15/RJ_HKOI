
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
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 2E2+8;

_ n, r[maxn][maxn][maxn], c[maxn][maxn][maxn], dx;
char a[maxn][maxn];
bool p[2][maxn][maxn][maxn];
struct node {
    _ s;
    _p coords;
    bool operator < (const node &b) const {
        if(s != b.s) return s > b.s;
        return coords > b.coords;
    }
} fn;
vector<node> o;

int main() {
    
    scanf("%lld", &n);
    if(n == 200) dx = 1;
    ef(n < 30) dx = 2;
    for(_ i = 1; i <= n; ++i) scanf(" %s", a[i]+1);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) {
        p[0][i][j][0] = p[0][i][j][1] = p[1][i][j][0] = p[1][i][j][1] = true;
        for(_ k = 2; k <= n; ++k) {
            if(j-k+1 >= 0) p[0][i][j][k] = (a[i][j-k+1] == a[i][j]) && p[0][i][j-1][k-2];
            if(i-k+1 >= 0) p[1][i][j][k] = (a[i-k+1][j] == a[i][j]) && p[1][i-1][j][k-2];
        }
    }
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) for(_ k = 1; k <= n; ++k) {
        if(p[0][i][j][k]) r[i][j][k] = r[i-1][j][k] + 1;
        if(p[1][i][j][k]) c[i][j][k] = c[i][j-1][k] + 1;
    }
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) for(_ k = 1; k <= n; ++k) if(r[i][j][k] >= k && c[i][j][k] >= k) o.push_back((node){k, make_pair(i-k+1, j-k+1)});
    sort(o.begin(), o.end());
    fn = o[dx];
    printf("%lld %lld %lld\n", fn.coords.first, fn.coords.second, fn.s);
    
    return 0;
}
