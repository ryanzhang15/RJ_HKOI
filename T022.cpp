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
#include <queue>
#include <list>
#include <set>

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

constant maxn = 20+8;
struct node {
    _ x, y, s, b;
    deque<pair<_, _> > path;
};

bool c[maxn][maxn], v[maxn][maxn][3];
_ b, n, m, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
char d;
queue<node> q;

int main(int argc, char * argv []) {
    
    /* bfs? */
    scanf(_lllin, &b, &n, &m);
    for(_ i = 1; i <= n; ++i) {
        getchar();
        for(_ j = 1; j <= m; ++j) {
            d = getchar();
            c[i][j] = d == '1';
        }
    }
    
    node temp = {1, 1, 0, b, {{1, 1}}};
    q.push(temp);
    v[1][1][b] = true;
    if(temp.x == n && temp.y == m) {
        printf(fs(_l+"\n"), temp.s);
        for(; !temp.path.empty(); temp.path.pop_front()) printf(fs(_l+" "+_l+"\n"), temp.path.front().first, temp.path.front().second);
        exit(0);
    }
    for(; !q.empty(); q.pop()) {
        node cur = q.front();
        for(_ i = 0; i < 4; ++i) {
            temp.x = cur.x+dx[i];
            temp.y = cur.y+dy[i];
            if(temp.x <= 0 || temp.y <= 0 || temp.x > n || temp.y > m) continue;
            temp.s = cur.s+1;
            temp.b = cur.b - c[temp.x][temp.y];
            if(temp.b < 0 || v[temp.x][temp.y][temp.b]) continue;
            v[temp.x][temp.y][temp.b] = true;
            temp.path = cur.path;
            temp.path.push_back({temp.x, temp.y});
            if(temp.x == n && temp.y == m) {
                printf(fs(_l+"\n"), temp.s);
                for(; !temp.path.empty(); temp.path.pop_front()) printf(fs(_l+" "+_l+"\n"), temp.path.front().first, temp.path.front().second);
                exit(0);
            }
            q.push(temp);
        }
    }
    
    return 0;
}
