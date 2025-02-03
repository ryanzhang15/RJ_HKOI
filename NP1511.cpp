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

constant maxn = 50;
_ f[maxn][maxn], n, x, y;

int main(int argc, char * argv[]) {
    
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    
    cin >> n;
    x = 1; y = (n+1)/2;
    for(_ i = 1; i <= n*n; i++) {
        f[x][y] = i;
        if(!f[(x-2+n)%n+1][y%n+1]) {
            x = (x-2+n)%n+1;
            y = y%n+1;
        } else x = (x+1)%n ? (x+1)%n : n;
    }
    
    for(_ i = 1; i <= n; i++) {
        for(_ j = 1; j <= n; j++)
            cout << f[i][j] <<' ';
        cout << endl;
    }
    
    return 0;
}

