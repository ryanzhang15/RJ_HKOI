
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

constant maxn = 1E3+8;
//constant maxn = 8;

_ n, m, s, c, a, rs[maxn][maxn], cs[maxn][maxn], x, y, d;

int main(int argc, char * argv[]) {
    
    //some very weird code today
    
    scanf(_llin, &n, &m);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) {
        scanf(_lin, &c);
        s += c;
    }
    for(_ i = 1; i <= m; ++i) for(_ j = 1; j <= m; ++j) {
        scanf(_lin, &c);
        rs[i][j] = rs[i][j-1]+c;
        cs[j][i] = cs[j][i-1]+c;
    }
    
    //first rectangle from 1, 1;
    x = y = 1; c = 0;
    for(_ i = 1; i <= n; ++i) c += cs[i][n];
    a = abs(c-s);
    for(_ i = n; i <= m; ++i) {
        if(i != n) {
            c -= rs[i-n][n];
            c += rs[i][n];
            if(abs(c-s) < a) {
                a = abs(c-s);
                x = i-n+1;
                y = 1;
            }
        }
        d = c;
        for(_ j = n+1; j <= m; ++j) {
            d -= cs[j-n][i] - cs[j-n][i-n];
            d += cs[j][i] - cs[j][i-n];
            if(abs(d-s) < a) {
                a = abs(d-s);
                x = i-n+1;
                y = j-n+1;
            }
        }
    }
    
    printf(fs(_l+" "+_l+"\n"), x, y);
    
    return 0;
}

