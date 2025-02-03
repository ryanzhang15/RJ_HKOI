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

struct robo {
    _ p, s;
    bool used = false;
    bool operator < (const robo &b) const {
        _ v1 = used ? s : p+s, v2 = b.used ? b.s : b.p + b.s;
        return v1 < v2;
    }
} c;

_ n, m, s;
priority_queue<robo> q;

int main(int argc, char * argv []) {
    
    scanf(_llin, &n, &m);
    for(_ i = 1; i <= n; ++i) {
        scanf(_llin, &c.p, &c.s);
        q.push(c);
    }
    for(_ i = 1; i <= m; ++i) {
        c = q.top();
        q.pop();
        if(c.used) {
            s += (m-i+1)*c.s;
            break;
        } else {
            s += c.s+c.p;
            c.used = true;
            q.push(c);
        }
    }
    
    printf(fs(_l+"\n"), s);
    
    return 0;
}
