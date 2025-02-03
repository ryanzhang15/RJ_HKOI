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
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%llf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E2+8;
_ n, t[maxn], a[maxn][maxn], s = -1E4;

_ kd();
int main(int argc, char * argv[]) {
    
    //~0(n^3);
    scanf(_lin, &n);
    for(_ i = 1; i <= n; i++) for(_ j = 1; j <= n; j++) scanf(_lin, &a[i][j]);
    for(_ i = 1; i <= n; i++) {
        memset(t, 0, sizeof(t));
        for(_ j = i; j <= n; j++) {
            for(_ k = 1; k <= n; k++) t[k] += a[k][j];
            s = max(s, kd());
        }
    }
    
    printf(fs(_l+"\n"), s);
    
    return 0;
}

_ kd() { //kadane's algorithm
    _ ans = -1, cnt = -999999;
    for(_ i = 1; i <= n; i++) {
        if(t[i] > cnt+t[i]) cnt = t[i];
        else cnt += t[i];
        ans = max(ans, cnt);
    }
    return ans;
}
