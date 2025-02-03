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

constant maxn = 5E5+8;
//constant maxn = 7;

_ n, d[maxn], g[maxn], c;
queue<_> q; //using queue cos why not

int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) {
        scanf(_lin, &c);
        g[i] = c;
        ++d[c];
    }

    for(_ i = 1; i <= n; ++i) if(!d[i]) q.push(i);

    for(; !q.empty(); q.pop()) {
        if(!--d[g[q.front()]]) q.push(g[q.front()]);
    }

    c = 0;
    for(_ i = 1; i <= n; ++i)
        if(d[i]) {
            q.push(i);
            ++c;
        }

    printf(fs(_l+"\n"), c);
    for(; !q.empty(); q.pop()) printf(fs(_l+" "), q.front());
    printf("\n");
    
    return 0;
}
