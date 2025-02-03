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

struct node {
    _ x, y, s;
    queue<char> dir;
};

bool c[maxn][maxn];
_ n, m, a, b;
queue<node> q;
queue<char> e;

int main(int argc, char * argv[]) {
    
    // quote from "https://assets.hkoi.org/training2004/01_sol_j4.pdf", HKOI 2004 Final Event Slide, \
        "We DIDN’T expect Junior contestants to know BFS", \
        "We DIDN’T expect Junior contestants to know DP". \
    \
    Ah, those were the days.

    scanf(_llin, &n, &m);
    for(; m--; ) { //i only use for loops
        scanf(_llin, &a, &b);
        c[a][b] = true;
    }
    
    q.push({1, 1, 0, e}); //shady shady stuff
    for(; !q.empty(); q.pop()) { //I only use for loops.
        node t = q.front();
        t.s++;
        node T = t;
        t.x++;
        T.y++;
        t.dir.push('S');
        T.dir.push('E');
        if(t.x <= n && !c[t.x][t.y]) {
            c[t.x][t.y] = true;
            if(t.x == n && t.y == n) {
                printf(fs(_l+"\n"), t.s);
                for(; !t.dir.empty(); t.dir.pop()) printf("%c\n", t.dir.front());
                exit(0);
            }
            q.push(t);
        }
        if(T.y <= n && !c[T.x][T.y]) {
            c[T.x][T.y] = true;
            if(T.x == n && T.y == n) {
                printf(fs(_l+"\n"), T.s);
                for(; !T.dir.empty(); T.dir.pop()) printf("%c\n", T.dir.front());
                exit(0);
            }
            q.push(T);
        }
    }
    
    return 0;
}
