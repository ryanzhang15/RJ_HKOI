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

constant maxn = 1E3+8;

str a, b;
_ dp[maxn][maxn], ans, anspos;

int main(int argc, char * argv[]) {
    
    cin >> a >> b;
    a = " " + a; b = " " + b;
    for(_ i = 1; i < a.length(); i++)
        for(_ j = 1; j < b.length(); j++)
            if(a[i] == b[j]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                if(dp[i][j] > ans) {
                    ans = dp[i][j];
                    anspos = i;
                }
            }
    
    cout << a.substr(anspos-ans+1, ans) << endl;
    
    return 0;
}
