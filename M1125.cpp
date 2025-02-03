#include <cstdio>
#include <iostream>
#include <cstdlib>
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

constant maxn = 5E5+8;
constant maxk = 10+8;

_ n, k, dp[maxn][maxk], big, s;
bool a[maxn];
char ch;

int main(int argc, char * argv[]) {
    
    memset(dp, 4, sizeof dp);
    big = dp[0][0];
    scanf("%lld%lld", &n, &k);
    ++n;
    for(; ch != '#' && ch != '.'; ) ch = getchar_unlocked();
    for(_ i = 1; i <= n; ++i, ch = getchar_unlocked()) a[i] = ch == '#';
    for(_ i = 1; i <= k; ++i) dp[1][i] = 0;
    for(_ i = 2; i <= n; ++i) if(a[i]) for(_ j = 1; j <= k; ++j) {
    	if(j < i) dp[i][j] = dp[i-j][j];
    	for(_ l = 1; l <= k; ++l) if(j != l && l < i) dp[i][j] = min(dp[i][j], dp[i-l][l]+1);
    }
	s = big;
	for(_ i = 1; i <= k; ++i) s = min(s, dp[n][i]);
	if(s == big) puts("-1");
	else printf("%lld\n", s);
    return 0;
}


