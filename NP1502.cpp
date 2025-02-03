
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

constant mn = 1E3;

bool grid[mn][mn];
_ n, m;

int main(int argc, char * argv[]) {
    
    freopen("mine.in", "r", stdin);
    freopen("mine.out", "w", stdout);
    
    cin >> n >> m;
    for(_ i = 3; i < n+3; i++) {
        for(_ j = 3; j < m+3; j++) {
            char a; cin >> a;
            grid[i][j] = (a == '*');
        }
    }
    
    for(_ i = 3; i < n+3; i++) {
        for(_ j = 3; j < m+3; j++)
            if(grid[i][j]) cout << '*';
            else cout << (_)grid[i-1][j] + (_)grid[i-1][j-1] + (_)grid[i-1][j+1] + (_)grid[i][j-1] + (_)grid[i][j+1] + (_)grid[i+1][j-1] + (_)grid[i+1][j] + (_)grid[i+1][j+1];
        cout << endl;
    }
    
    return 0;
}
