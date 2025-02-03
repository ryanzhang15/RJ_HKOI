#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <bitset>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _llin "%lld%lld"
#define _lllin "%lld%lld%lld"
#define _llllin "%lld%lld%lld%lld"
std::string _l = "%lld";
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

constant maxn = 18+8;
struct node {
    _ x, y, s, l, u;
};
_ grid[maxn][maxn], b, t, n, sx, sy, ex, ey, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
char c;

queue<node> q;
bool v[maxn][maxn][6][6];

int main(int argc, char * argv[]) {
    
    scanf(_lllin, &b, &t, &n);
    for(_ i = 1; i <= n; ++i) {
        getchar();
        getchar();
        /*
         '\r' + '\n' screws getchar over
         */
        for(_ j = 1; j <= n; ++j) {
            c = getchar();
            if(c == 'W') grid[i][j] = 1;
            else if(c == 'M') grid[i][j] = 2;
            else if(c == 'O') {
                sx = i;
                sy = j;
            } else if(c == 'V') {
                ex = i;
                ey = j;
                grid[i][j] = 2;
            }
        }
    }
    node temp = {sx, sy, 0, 0, 0};
    q.push(temp);
    v[sx][sy][0][0] = true;
    for(; !q.empty(); q.pop()) for(_ i = 0; i < 4; ++i) {
        temp.x = q.front().x + dx[i];
        temp.y = q.front().y + dy[i];
        temp.l = q.front().l ? q.front().l-1 : 0;
        temp.u = q.front().u;
        if(temp.x <= 0 || temp.y <= 0 || temp.x > n || temp.y > n || (grid[temp.x][temp.y] == 2 && !temp.l && temp.u == b) || grid[temp.x][temp.y] == 1) continue;
        if(grid[temp.x][temp.y] == 2 && !temp.l) {
            ++temp.u;
            temp.l = t;
        }
        if(v[temp.x][temp.y][temp.l][temp.u]) continue;
        v[temp.x][temp.y][temp.l][temp.u] = true;
        temp.s = q.front().s+1;
        if(temp.x == ex && temp.y == ey) {
            printf(fs(_l+"\n"), temp.s);
            exit(0);
        }
        q.push(temp);
    }
    
    return 0;
}

