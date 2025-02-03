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

#define fs(str) (str).c_str()
#define _lin "%lli"
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxm = 3E3+8;

_ n, m, d[3][maxm], lower_bound(_ s), sum = -5, ans[3];

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &m);
    for(_ i = 0; i < 3; i++)
        for(_ j = 0; j < m; j++)
            scanf(_lin, &d[i][j]);
    
    sort(d[2], d[2]+m);
    
    for(_ i = 0; i < m; i++)
        for(_ j = 0; j < m; j++) {
            if(d[0][i]+d[1][j] >= n) continue;
            _ a = lower_bound(n-d[0][i]-d[1][j]);
            if(a != -1 && a+d[0][i]+d[1][j] > sum) {
                sum = a+d[0][i]+d[1][j];
                ans[0] = d[0][i];
                ans[1] = d[1][j];
                ans[2] = a;
            }
        }
    
    printf(fs(_l+" "+_l+" "+_l+"\n"), ans[0], ans[1], ans[2]);
    
    return 0;
}

_ lower_bound(_ s) {
    _ l = 0, r = m-1, mid, ans = -1;
    while(l <= r) {
        mid = (l+r)/2;
        if(d[2][mid] <= s) {
            ans = d[2][mid];
            l = mid+1;
        } else r = mid - 1;
    }
    return ans;
}
