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

constant maxn = 1E2+8;
//constant maxn = 15;
constant maxv = 1E3+8;
//constant maxv = 1E2;
_D in;
_ tv, a[maxn], n, c, f[maxn][maxv];
multiset<_> s;
bool v[maxv];

int main(int argc, char * argv[]) {
    
    scanf("%Lf", &in);
    tv = in*10;
    for(; scanf("%Lf", &in) != EOF; ) a[++n] = in*10;
    sort(a+1, a+1+n);
    v[0] = true;
    for(_ i = 1; i <= n; ++i) for(_ j = a[i] < 10 ? min((_)20, tv) : tv; j >= a[i]; --j) if(v[j-a[i]]) {
        f[i][j] = max(f[i-1][j], f[i-1][j-a[i]]+1);
        v[j] = true;
    }
    printf(fs(_l+"\n"), f[n][tv]);
    if(!v[tv]) exit(0);
    _ i = n, j = tv;
    while(i && j) {
        if(f[i][j] != f[i-1][j]) {
            s.insert(a[i]);
            j -= a[i];
        }
        --i;
    }
    for(_ i : s) printf("%Lg\n", (_D)i/10.0);
    
    return 0;
}
