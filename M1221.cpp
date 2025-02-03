
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
#include <random>
#include <numeric>

#define ef else if

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E3+8;
_ dp[maxn][maxn<<1], n, t[maxn], p[maxn], s;

int main() {

    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld%lld", &t[i], &p[i]);
    for(_ i = n; i >= 1; --i) for(_ j = n<<1; j >= 0; --j) {
        dp[i][j] = max(dp[i][j+1], dp[i+1][j+1]);
        if(t[i] == j) dp[i][j] += p[i];
    }
    printf("%lld\n", dp[1][0]);
    
    return 0;
}


