
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

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef double _D;
typedef string str;
typedef const long long constant;

typedef pair<_, _> pp;
constant maxn = 1E5+88;
//constant maxn = 5;

_ n, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
char dxdy[] = {'v', '^', '>', '<'};
map<char, pp> key = {{'^', {-1, 0}}, {'>', {0, 1}}, {'v', {1, 0}}, {'<', {0, -1}}};
char grid[2+2][maxn]; //2+2 and 1E5+88 to prevent out of bounds by accident
                      //cus im careless
bool vis[4][maxn], flag;

void dfs(_ x, _ y);
int main(int argc, char  * argv[]) {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    cin >> n;
    
    for(_ i = 0; i < n; i++) cin >> grid[0][i];
    for(_ i = 0; i < n; i++) cin >> grid[1][i];
    
    //This is just your standard DFS problem.
    //Right?
    
    dfs(0, 0);
    if(!flag) cout << "Impossible" << endl;
    
    return 0;
}

void dfs(_ x, _ y) {
    if(x == 1 && y == n-1) {
        //ur done. Just cout and exit;
        flag = true;
        for(_ i = 0; i <= 1; i++) {
            for(_ j = 0; j < n; j++) {
                if(grid[i][j] == '?') cout << '<';
                else cout << grid[i][j];
            }
            cout << endl;
        }
        return;
    }
    if(grid[x][y] == '?') {
        for(_ i = 0; i < 4; i++) {
            _ nx = x + dx[i];
            _ ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= 2 || ny >= n || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            grid[x][y] = dxdy[i];
            dfs(nx, ny);
            vis[nx][ny] = false;
            grid[x][y] = '?';
            if(flag) return;
        }
    } else {
        auto curpp = key[grid[x][y]];
        _ nx = x + curpp.first;
        _ ny = y + curpp.second;
        if(nx < 0 || ny < 0 || nx >= 2 || ny >= n || vis[nx][ny]) return;
        vis[nx][ny] = true;
        dfs(nx, ny);
        if(flag) return;
    }
}

