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
#define _llllin "%lli%lli%lli%lli"
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

constant maxn = 10+8;
 //left, down, right, up
_ n, dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0}, canGo[maxn][maxn];
bool vis[maxn][maxn], path[maxn][maxn];
char c;

void dfs(_ x, _ y, _ s, _ m);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    getchar();
    for(_ i = 1; i <= n; ++i) {
        for(_ j = 1; j <= n; ++j) {
            c = getchar();
            if(c >= '0' && c <= '9') canGo[i][j] = c - '0';
            else canGo[i][j] = c - 'A' + 10;
        }
        getchar();
    }
    
    vis[1][1] = true;
    path[1][1] = true;
    canGo[1][1] |= 9;
    
    for(_ i = 1; i <= n*n+2; ++i) dfs(1, 1, 1, i);
    
    return 0;
}

void dfs(_ x, _ y, _ s, _ m) {
    if(s == m) return;
    if(x <= 0 || y <= 0 || x > n || y > n) {
        for(_ i = 1; i <= n; ++i) {
            for(_ j = 1; j <= n; ++j) putchar(path[i][j] ? '*' : '.');
            putchar('\n');
        }
        exit(0);
    }
    
    for(_ i = 0; i < 4; ++i) {
        if(canGo[x][y] & (1 << i)) continue;
        _ nx = x + dx[i];
        _ ny = y + dy[i];
        if(vis[nx][ny]) continue;
        path[nx][ny] = vis[nx][ny] = true;
        dfs(nx, ny, s+1, m);
        path[nx][ny] = vis[nx][ny] = false;
    }
    
    return;
}
