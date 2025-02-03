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
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 20+8;
bool canGo[maxn][maxn];
deque<char> path;

_ n, m;

void dfs(_ x, _ y);
int main(int argc, char * argv[]) {
    
    cin >> n >> m;
    for(_ i = 1; i <= n; i++) for(_ j = 1; j <= m; j++) {
        char a; cin >> a;
        canGo[i][j] = a == '.';
    }
    
    dfs(1, 1);
    
    return EXIT_SUCCESS;
}

void dfs(_ x, _ y) {
    if(x == n && y == m) {
        while(!path.empty()) {
            cout << path.front();
            path.pop_front();
        }
        cout << endl;
        exit(EXIT_SUCCESS);
    }
    if(y+1 <= m && canGo[x][y+1]) {
        path.push_back('E');
        dfs(x, y+1);
        path.pop_back();
    }
    if(x+1 <= n && canGo[x+1][y]) {
        path.push_back('S');
        dfs(x+1, y);
        path.pop_back();
    }
    return;
}
