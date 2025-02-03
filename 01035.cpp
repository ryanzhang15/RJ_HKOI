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

#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lli"
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E3+8;

_ n, m, h, x, y, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, a[maxn][maxn];
bool vis[maxn][maxn];

void dfs(_ x, _ y);
int main(int argc, char * argv[]) {
    
    //pretty standard dfs problem
    scanf(fs(_l+_l+_l+_l+_l), &n, &m, &h, &x, &y);
    for(_ i = 1; i <= m; ++i) for(_ j = 1; j <= n; ++j) scanf(_lin, &a[i][j]);
    vis[y][x] = true;
    dfs(y, x);
    for(_ i = 1; i <= m; ++i) {
        for(_ j = 1; j <= n; ++j) printf(_lin, vis[i][j] ? (_)1 : (_)0);
        printf("\n");
    }
    
    return 0;
}

void dfs(_ x, _ y) {
    for(_ i = 0; i < 4; ++i) {
        _ nx = x + dx[i];
        _ ny = y + dy[i];
        if(nx <= 0 || ny <= 0 || nx > n || ny > m) continue;
        if(vis[nx][ny] || abs(a[x][y] - a[nx][ny]) > h) continue;
        vis[nx][ny] = true;
        dfs(nx, ny);
    }
    return;
}
