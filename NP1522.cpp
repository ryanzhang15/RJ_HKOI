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
typedef float _D;
typedef string str;
typedef const long long constant;

constant maxm = 2E2+8;
constant mod = 1000000007;

str a, b;
_ n, m, k, dp[2][maxm][maxm][2];

int main(int argc, char * argv[]) {
    
    freopen("substring.in", "r", stdin);
    freopen("substring.out", "w", stdout);
    
    cin >> n >> m >> k >> a >> b;
    a = " " + a; b = " " + b;
    dp[0][0][0][0] = 1;
    for(_ i = 1; i <= n; i++) {
        dp[i%2][0][0][0] = 1;
        for(_ j = 1; j <= m; j++)
            for(_ l = 1; l <= k; l++) {
                dp[i%2][j][l][0] = (dp[(i-1)%2][j][l][0] + dp[(i-1)%2][j][l][1]) % mod;
                if(a[i] == b[j]) dp[i%2][j][l][1] = (dp[(i-1)%2][j-1][l][1] + dp[(i-1)%2][j-1][l-1][0] + dp[(i-1)%2][j-1][l-1][1]) % mod;
                else dp[i%2][j][l][1] = 0;
            }
    }
    
    cout << (dp[n%2][m][k][0] + dp[n%2][m][k][1])%mod << endl;
    
    return 0;
}

