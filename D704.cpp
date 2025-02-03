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

constant maxn = 1E4+8;

_ n, h, x, y, p;
_ d[maxn], ne[maxn];

int main(int argc, char * argv[]) {
    
    cin >> n >> h;
    for(_ i = 1; i <= n; i++) cin >> d[i];
    for(_ i = 1; i <= n; i++) cin >> ne[i];
    cin >> x >> y;
    if(!y) {
        cout << n+1 << endl;
        cout << x <<' '<< h << endl;
        cout << -1 << endl;
    } else {
        p = h;
        for(_ i = 1; i < y; ++i) p = ne[p];
        cout << h << endl;
        cout << x <<' '<< ne[p] << endl;
        cout << p <<' '<< d[p] <<' '<< n+1 << endl;
    }
    
    return 0;
}
