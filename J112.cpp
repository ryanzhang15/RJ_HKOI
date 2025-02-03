
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

_ n, m, a, b, s = 1, tw, th;

int main(int argc, char * argv[]) {
    
    scanf(_lllin, &n, &m, &a);
    for(_ i = 1; i <= n-1; ++i) {
        scanf(_llin, &b, &a);
        if(b == a) ++s;
        else s = 1;
        if(!(s % 3)) {
            --tw;
            ++th;
        }
        if(s % 3 == 2) ++tw;
    }
    
    s = 0;
    if(m >= th+tw) s = th*2+tw;
    else if(m <= th) s = m*2;
    else s = th+m;
    if(s + m > n) s = n-m;
    printf(fs(_l+"\n"), s);
    
    return 0;
}
