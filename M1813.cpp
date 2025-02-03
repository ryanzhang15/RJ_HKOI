
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
#define ef else if

using namespace std;

typedef int _;
typedef const long long constant;

constant maxn = 3E2+8;
constant mod = 1E9+7;

_ n, m, k, dp[maxn][maxn][maxn][2], s;
char a[maxn], b[maxn];

int main() {
    
    scanf("%d%d%d %s %s", &n, &m, &k, a, b);
    if(a[0] == '?' || a[0] == '1') dp[1][1][b[0]^48][1] = 1;
    if(a[0] == '?' || a[0] == '0') dp[1][1][!(b[0]^48)][0] = 1;
    
    for(_ i = 1; i <= n-1; ++i) {
        // append 1
        if(a[i] == '?' || a[i] == '1') for(_ j = 0; j < k; ++j) for(_ l = 0; l < m; ++l) for(_ o = 0; o <= 1; ++o) dp[i+1][o ? j+1 : 1][l + (b[l]^48)][1] = (dp[i+1][o ? j+1 : 1][l + (b[l]^48)][1] + dp[i][j][l][o]) % mod;
        // append 0
        if(a[i] == '?' || a[i] == '0') for(_ j = 0; j < k; ++j) for(_ l = 0; l < m; ++l) for(_ o = 0; o <= 1; ++o) dp[i+1][o ? 1 : j+1][l + !(b[l]^48)][0] = (dp[i+1][o ? 1 : j+1][l + !(b[l]^48)][0] + dp[i][j][l][o]) % mod;
    }
    for(_ i = 0; i < k; ++i) for(_ j = 0; j < m; ++j) for(_ l = 0; l <= 1; ++l) s = (s + dp[n][i][j][l]) % mod;
    printf("%d\n", s);
    
    return 0;
}
