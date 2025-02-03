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
#define _llllin "%lli%lli%lli%lli"
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

constant maxn = 1E4+8;

_D s;
_ n, k, c, a[maxn];

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &k);
    for(_ i = 1; i <= n; ++i) {
        scanf(_lin, &c);
        a[i] = a[i-1]+c*100;
    }
    
    for(_ i = k; i <= n-1; ++i)
        s += abs((_D)(a[i]-a[i-k])/(_D)k - (a[i+1]-a[i]));
        
    s /= n-k;
    printf("%.2Lf\n", s/100.0);
    
    return 0;
}
