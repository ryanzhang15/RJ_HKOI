
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

constant maxa = 2.5E4 + 88;

queue<_> q;
_ N, n, dp[maxa], ans;

int main(int argc, char * argv[]) {
    
    freopen("money.in", "r", stdin);
    freopen("money.out", "a", stdout);
    
    cin >> N;
    while(N --> 0) {
        memset(dp, 0, sizeof(dp));
        ans = 0;
        
        cin >> n;
        for(_ i = 0; i < n; i++) {
            _ a; cin >> a; q.push(a);
            dp[a] += 2;
            for(_ j = a; j < maxa-88; j++) {
                if(dp[j-a]) dp[j] = max(dp[j], dp[j-a]+1);
            }
        }
        while(!q.empty()) {
            if(dp[q.front()] == 2) ans++;
            q.pop();
        }
        
        cout << ans << endl;
    }
    
    
    return 0;
}

