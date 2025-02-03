
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

constant maxn = 1E2+8;
constant maxm = 1E4+8;
//constant maxm = 400;

_ t, n, m, cmax;
_ item[maxn][maxn], dp[maxm];

int main(int argc, char * argv[]) {
    
    freopen("souvenir.in", "r", stdin);
    freopen("souvenir.out", "w", stdout);
    
    cin >> t >> n >> m;
    for(_ i = 0; i < t; i++) {
        for(_ j = 0; j < n; j++) {
            cin >> item[i][j];
        }
    }
    
    _ maxp = m;
    for(_ i = 1; i < t; i++) {
        memset(dp, 0, sizeof(dp));
        for(_ j = 0; j < n; j++) {
            for(_ k = item[i-1][j]; k <= maxp; k++) {
                dp[k] = max(dp[k], dp[k-item[i-1][j]] + item[i][j] - item[i-1][j]);
            }
        }
        maxp += dp[maxp];
    }
    
    cout << maxp << endl;
    
    return 0;
}