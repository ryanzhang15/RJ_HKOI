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

constant maxm = 1E5+8;
_ n, m, a, c[maxm], x[maxm];

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &m);
    fill(x+1, x+1+n, -1);
    
    //O(m) space, O(m*n) time
    
    for(_ i = 1; i <= n; ++i)
        for(_ j = 1; j <= m; ++j) {
            scanf(_lin, &a);
            if(!c[j]) {
                x[j] = a;
                ++c[j];
            } else {
                if(x[j] == a) ++c[j];
                else --c[j];
            }
        }
    
    for(_ i = 1; i <= m; ++i) printf(fs(_l+" "), x[i]);
    putchar(10);
    
    return 0;
}
