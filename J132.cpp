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

constant maxn = 5E4+8;

struct p {
    str id;
    _ stall;
    bool member = false, gold = false;
    void getInfo() {
        member = id.length() == 8;
        gold = id[0] == '1' && member;
        return;
    }
} a[maxn];

_ n, first, second, m;
str s[maxn];

int main(int argc, char * argv []) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) {
        cin >> a[i].id;
        a[i].getInfo();
    }
    first = 1;
    second = 2;
    for(_ i = 1, l = n; i <= n; ++i, --l)
        if(l == 1) s[i] = a[first].id;
        else {
            if(!a[first].member && a[second].member && a[first].stall < 2) {
                ++a[first].stall;
                s[i] = a[second++].id;
            } else if(a[first].member && !a[first].gold && a[second].gold && !a[first].stall) {
                ++a[first].stall;
                s[i] = a[second++].id;
            } else {
                s[i] = a[first].id;
                first = second;
                ++second;
            }
        }
    
    scanf(_lin, &m);
    for(; m--; ) {
        scanf(_lin, &first);
        cout << s[first] <<' ';
    }
    
    putchar(10);
    
    return 0;
}
