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
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _llin "%lld%lld"
#define _lllin "%lld%lld%lld"
#define _llllin "%lld%lld%lld%lld"
std::string _l = "%lld";
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

_ n, k;

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &k);
    if(k*k < n) puts("Impossible");
    else {
        for(_ i = 1; i <= n/k; ++i) for(_ j = i*k; j >= (i-1)*k+1; --j) printf(fs(_l+" "), j);
        if(n % k) for(_ j = n; j >= (n/k)*k+1; --j) printf(fs(_l+" "), j);
        putchar(10);
    }
    
    return 0;
}

