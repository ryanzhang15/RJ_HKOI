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

constant maxn = 8;

_ n, a[maxn][maxn], b;
bitset<30> u;

void dfs(_ l, _ p);
int main(int argc, char * argv []) {

    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) b += i;
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= i; ++j) {
        scanf(_lin, &a[i][j]);
        if(a[i][j]) u[a[i][j]] = true;
    }
    
    dfs(n, 1);
    
    return 0;
}

void dfs(_ l, _ p) {
    //printf(fs(_l+" "+_l+"\n"), l, p);
    if(!l) {
        for(_ i = 1; i <= n; ++i) {
            for(_ j = 1; j <= i; ++j) printf(fs(_l+" "), a[i][j]);
            putchar(10);
        }
        exit(0);
    }
    if(l == n) {
        if(a[l][p]) {
            if(p == n) dfs(l-1, 1);
            else dfs(l, p+1);
            return;
        }
        for(_ i = 1; i <= b; ++i) {
            if(u[i]) continue;
            u.flip(i);
            a[l][p] = i;
            if(p == n) dfs(l-1, 1);
            else dfs(l, p+1);
            a[l][p] = 0;
            u.flip(i);
        }
    } else {
        if(a[l][p]) {
            if(a[l][p] != abs(a[l+1][p] - a[l+1][p+1])) return;
            if(p == l) dfs(l-1, 1);
            else dfs(l, p+1);
        } else {
            if(u[abs(a[l+1][p] - a[l+1][p+1])]) return;
            a[l][p] = abs(a[l+1][p] - a[l+1][p+1]);
            u.flip(abs(a[l+1][p] - a[l+1][p+1]));
            if(p == l) dfs(l-1, 1);
            else dfs(l, p+1);
            u.flip(abs(a[l+1][p] - a[l+1][p+1]));
            a[l][p] = 0;
        }
    }
    return;
}

/*
5
0
0 9
0 0 0
0 0 0 0
6 0 15 0 13
 */
