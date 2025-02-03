#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

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
#define _lin "%lli"
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
#define _llllin "%lli%lli%lli%lli"
std::string _l = "%lli";
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
constant maxm = 2E3+8;

_ n, m, r[maxn], w[maxm], o[maxn], s, c, l;
queue<_> q;

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &m);
    for(_ i = 1; i <= n; ++i) scanf(_lin, &r[i]);
    for(_ i = 1; i <= m; ++i) scanf(_lin, &w[i]);
    l = n;
    for(_ asdf = 1; asdf <= 2*m; ++asdf) {
        scanf(_lin, &c);
        if(c > 0) {
            bool p = false;
            for(_ i = 1; i <= n && !p && l; ++i) if(!o[i]) {
                o[i] = c;
                s += w[c]*r[i];
                --l;
                p = true;
            }
            if(!p) q.push(c);
        } else {
            c = -c;
            for(_ i = 1; i <= n; ++i) if(o[i] == c) {
                o[i] = 0;
                ++l;
                break;
            }
            if(!q.empty() && l) {
                c = q.front();
                for(_ i = 1; i <= n; ++i) if(!o[i]) {
                    o[i] = c;
                    s += w[c]*r[i];
                    --l;
                    break;
                }
                q.pop();
            }
        }
    }
    
    printf(fs(_l+"\n"), s);
    
    return 0;
}
