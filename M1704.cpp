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

constant maxn = 100+8;

_ n, a[maxn], b[maxn], f[maxn];
bool v[maxn];

void dfs(_ x);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) {
        scanf(_llin, &a[i], &b[i]);
        if(a[i] > b[i]) swap(a[i], b[i]);
    }
    
    dfs(1);
    
    printf("Impossible\n");
    
    return 0;
}

void dfs(_ x) {
    if(x == n+1) {
        for(_ i = 1; i <= n; ++i) printf(fs(_l+"\n"), f[i]);
        exit(0);
    }
    if(!v[a[x]]) {
        v[a[x]] = true;
        f[x] = a[x];
        dfs(x+1);
        v[a[x]] = false;
    }
    if(!v[b[x]] && b[x] != a[x]) {
        v[b[x]] = true;
        f[x] = b[x];
        dfs(x+1);
        v[b[x]] = false;
    }
    return;
}
