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
//#include <unordered_map>
#include <queue>
#include <list>
#include <set>
//#include <unordered_set>
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

char rc[4][12] = {{}, {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '\0'}, {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', '\0'}, {'z', 'x', 'c', 'v', 'b', 'n', 'm', '\0', '\0', '\0'}};
bool v[4][12];
str a, b;
_ s, d[300][300], dx[] = {0, 0, 1, 1, -1, -1}, dy[] = {1, -1, 0, -1, 0, 1};
struct node {
    _ x, y, s;
};

void bfs(_ sx, _ sy, char t);
int main(int argc, char * argv[]) {
    
    for(_ i = 1; i <= 3; ++i) for(_ j = 0; rc[i][j]; ++j) bfs(i, j, rc[i][j]);
    cin >> a >> b;
    for(_ i = 0; i < a.length(); ++i) s += d[a[i]][b[i]];
    printf(fs(_l+"\n"), s);
    
    return 0;
}

void bfs(_ sx, _ sy, char t) {
    memset(v, 0, sizeof v);
    queue<node> q;
    q.push({sx, sy, 0});
    v[sx][sy] = true;
    for(; !q.empty(); q.pop()) for(_ i = 0; i < 6; ++i) {
            _ nx = q.front().x + dx[i];
            _ ny = q.front().y + dy[i];
            if(nx < 0 || ny < 0 || nx >= 4 || !rc[nx][ny] || v[nx][ny]) continue;
            v[nx][ny] = true;
            d[t][rc[nx][ny]] = q.front().s+1;
            q.push({nx, ny, q.front().s+1});
    }
    return;
}
