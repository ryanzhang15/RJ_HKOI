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

constant maxn = 2E5+8;
//constant maxn = 7;

_ n, m, c, e[maxn], find(_ p);

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &m);
    for(_ i = 1; i <= m; i++) e[i] = i;
    e[m+1] = -1;
    for(; n--; ) {
        scanf(_lin, &c);
        printf(fs(_l+"\n"), find(c));
    }

    return 0;
}

_ find(_ p) {
    if(p == -1 || e[p] == -1) return -1;
    if(e[p] == p) {
        e[p] = p+1;
        return p;
    }
    else return e[p] = find(e[p+1]);
}
