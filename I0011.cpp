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

constant maxn = 5E3+8;
//constant maxn = 7;

_ n, dp[2][maxn];
str a, b;
int main(int argc, char * argv[]) {
    
    //isn't this just LCS?
    cin >> n >> a;
    b = a;
    reverse(b.begin(), b.end());
    a = " " + a; b = " " + b;
    for(_ i = 1; i <= n; i++)
        for(_ j = 1; j <= n; j++) {
            if(a[i] == b[j]) dp[i%2][j] = max(dp[i%2][j], dp[(i-1)%2][j-1]+1);
            else dp[i%2][j] = max(dp[(i-1)%2][j], dp[i%2][j-1]);
        }
    
    cout << n-dp[n%2][n] << endl;
    
    return 0;
}

