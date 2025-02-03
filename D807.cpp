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

constant maxn = 1E5+8;
_ n, a[maxn], p, i = 1, j;

int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) scanf(_lin, &a[i]);
    p = a[n];
    for(_ j = 1; j < n; ++j) {
        if(a[j] <= p) swap(a[i++], a[j]);
    }
    swap(a[n], a[i]);
    for(_ i = 1; i <= n; ++i) printf(fs(_l+" "), a[i]);
    putchar(10);
    
    return 0;
}

