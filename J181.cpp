
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

_ t, a, b, c, d, s;

int main(int argc, char * argv[]) {
    
    scanf(_llllin, &t, &a, &b, &c);
    if(t == 1) {
        if(b > 2*a) s = ((c+1)>>1)*a;
        else {
            if(c%4 == 3 || c%4 == 0) s = ((c+1)>>2)*b;
            else s = (c>>2)*b+a;
        }
    } else if(t == 2) {
        if(b > 2*a) s = (c/a)<<1;
        else s = ((c/b)<<2) + ((c%b >= a)<<1);
    } else if(t == 3) {
        scanf(_lin, &d);
        s = 1E12;
        for(_ i = 0; i <= (d+3)>>2; ++i) for(_ j = 0; j <= (d+3)>>2; ++j) for(_ k = 0; k <= (d+3)>>2; ++k) if(i*4+j*6+k*9 >= d) s = min(s, a*i+b*j+c*k);
    } else {
        scanf(_lin, &d);
        /* I don't believe exhaustion TLE*/
        for(_ i = 0; i <= (d+a-1)/a; ++i) for(_ j = 0; j <= (d+b-1)/b; ++j) if(i*a+j*b <= d) s = max(s, 4*i+6*j+((d-(i*a+j*b))/c)*9);
    }
    
    printf(fs(_l+"\n"), s);
    
    return 0;
}
