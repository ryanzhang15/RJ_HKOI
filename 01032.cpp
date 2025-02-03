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

_ n, m, ctr;

int main(int argc, char * argv[]) {
    
    scanf(_lin, &m);
    if(m % 6 != 2 && m % 6 != 3) {
        if(m & 1) {
            for(_ i = 2; i <= m-1; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = 1; i <= m-2; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            printf(fs(_l+" "+_l+"\n"), m, ++ctr);
        } else {
            for(_ i = 2; i <= m; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = 1; i <= m-1; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
        }
    } else {
        n = m >> 1;
        if(m & 1 && n & 1) {
            for(_ i = n; i <= m-2; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = 1; i <= n-2; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = n+3; i <= m-1; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = 2; i <= n+1; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            printf(fs(_l+" "+_l+"\n"), m, ++ctr);
        } else if(m & 1 && !(n & 1)) {
            for(_ i = n; i <= m-1; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = 2; i <= n-2; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = n+3; i <= m-2; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = 1; i <= n+1; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            printf(fs(_l+" "+_l+"\n"), m, ++ctr);
        } else if(!(m & 1) && n & 1) {
            for(_ i = n; i <= m-1; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = 1; i <= n-2; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = n+3; i <= m; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = 2; i <= n+1; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
        } else {
            for(_ i = n; i <= m; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = 2; i <= n-2; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = n+3; i <= m-1; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
            for(_ i = 1; i <= n+1; i += 2) printf(fs(_l+" "+_l+"\n"), i, ++ctr);
        }
    }
    
    return 0;
}

