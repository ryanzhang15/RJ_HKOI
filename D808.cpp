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

constant maxn = 1E5+8;
//constant maxn = 6;

_ a[maxn], n, s;

void sort(_ l, _ r);
int main(int argc, char * argv[]) {

    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) scanf(_lin, &a[i]);
    sort(1, n);
    for(_ i = 1; i <= n; ++i) printf(fs(_l+" "), a[i]);
    putchar(10);
    printf(fs(_l+"\n"), s);

    return 0;
}

void sort(_ l, _ r) {
    s += r-l+1;
    if(l >= r) return;
    _ i = l;
    for(_ j = l; j <= r-1; ++j) if(a[j] <= a[r]) swap(a[j], a[i++]);
    swap(a[i], a[r]);
    sort(l, i-1);
    sort(i+1, r);
    return;
}
