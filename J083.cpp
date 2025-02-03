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
#include <queue>
#include <list>
#include <set>

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

bitset<60> b, o;
_ n, s, t, c, l;

int main(int argc, char * argv []) {
    
    scanf(_lin, &n);
    ++n;
    for(_ i = 1; i <= 59; ++i) {
        b.flip(i);
        o.flip(i-1);
        c = n/b.to_ulong();
        s += c*o.to_ulong();
        l = n-c*b.to_ulong();
        s += max((_)0, l-(_)(o.to_ulong()));
        b.reset();
        o.reset();
    }
    printf(fs(_l+"\n"), s);
    
    return 0;
}
