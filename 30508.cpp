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

constant maxn = 3E2+8;
str f;
struct node {
    str s;
    _ d;
    void getd() {
        d = 0;
        for(_ i = 0; i < f.length(); ++i) d += f[i] != s[i];
    }
    bool operator < (const node &b) const {
        return d < b.d;
    }
} a[maxn];

_ n, m;

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &m);
    cin >> f;
    for(_ i = 1; i < n; ++i) {
        cin >> a[i].s;
        a[i].getd();
    }
    
    sort(a+1, a+n);
    
    cout << f << endl;
    for(_ i = 1; i < n; ++i) cout << a[i].s << endl;
    
    return 0;
}

