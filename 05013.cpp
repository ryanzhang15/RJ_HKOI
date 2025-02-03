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

constant maxn = 1E2+8;

struct contestant {
    str onamae;
    char g;
    _ s = -1;
    bool operator < (const contestant &b) const {
        return s > b.s;
    }
} a[maxn], f;
_ n, s1, s2;
char c;

bool cmp(contestant &a, contestant &b);
int main(int argc, char * argv []) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) {
        getchar();
        c = '\0';
        for(; c != ','; a[i].onamae += c) c = getchar();
        a[i].onamae.pop_back();
        a[i].g = getchar();
        getchar();
        scanf(_lin, &a[i].s);
        if(a[i].g == 'F' && a[i].s > f.s) f = a[i];
    }
    sort(a+1, a+1+n);
    if(f.s == -1 || a[1].g == 'F' || a[2].g == 'F' || a[3].g == 'F') {
        sort(a+1, a+4, cmp);
        cout << a[1].onamae <<'\n'<< a[2].onamae <<'\n'<< a[3].onamae << endl;
    } else {
        s1 = (a[1].s + a[2].s + a[3].s)*100;
        s2 = (a[1].s + a[2].s + f.s)*110;
        if(s2 > s1) a[3] = f;
        sort(a+1, a+4, cmp);
        cout << a[1].onamae <<'\n'<< a[2].onamae <<'\n'<< a[3].onamae << endl;
    }
    
    return 0;
}

bool cmp(contestant &a, contestant &b) {
    return a.onamae < b.onamae;
}
