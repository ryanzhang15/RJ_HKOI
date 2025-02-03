
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

_ n, c, v, d[7], t;

int main(int argc, char * argv[]) {
    
    scanf(_lllin, &n, &c, &v);
    v += 6*c;
    for(_ i = 1; i <= 5*n; ++i) {
        scanf(_lin, &c);
        ++d[c];
    }
    t = c = 1;
    for(; ;) {
        if(6*c+t > v && (t == 1 ? d[t] : d[t]+d[1]) >= c) {
            printf(fs(_l+" "+_l+"\n"), c, t);
            exit(0);
        }
        if(++t == 7) {
            t = 1;
            ++c;
        }
    }
    
    return 0;
}

