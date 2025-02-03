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

constant maxn = 1E5+4;
_ n;
_D m, a[maxn];

int main(int argc, char * argv[]) {
    
    scanf(fs(_l+_f), &n, &m);
    scanf(fs(_f), &a[1]);
    for(_ i = 2; i <= n; ++i) {
        scanf(fs(_f), &a[i]);
        if(a[i] < a[i-1]) m = m*a[i-1]/a[i];
    }
    
    printf("%.2Lf\n", m);
    
    return 0;
}
