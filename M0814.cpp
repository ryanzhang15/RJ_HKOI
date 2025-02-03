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

constant maxn = 1E4+88;

_ n, m, a[maxn], l1, l2, c, l[maxn];
map<str, _> x;
str s[maxn], t;
bool v[maxn];

int main(int argc, char * argv[]) {
    
    // hashmap question?
    
    /* I JUST REALISED: 5 seconds????*/
    
    scanf(_llin, &n, &m);
    getchar();
    for(_ i = 1; i <= n; ++i) {
        getline(cin, s[i]);
        x[s[i]] = i;
        l1 = max(l1, (_)s[i].length());
    }
    
    for(; m--; ) {
        getline(cin, t);
        c = stoi(t.substr(t.length()-2));
        if(c == 10) t = t.substr(0, t.length()-3);
        else t = t.substr(0, t.length()-2);
        if(v[x[t]]) continue;
        a[x[t]] -= c*10;
        if(!c && !v[x[t]]) {
            a[x[t]] += 100;
            v[x[t]] = true;
        }
    }
    
    for(_ i = 1; i <= n; ++i) {
        l[i] = (to_string(a[i])).length();
        l2 = max(l[i]+1, l2);
    }
    
    for(_ i = 1; i <= n; ++i) {
        cout << s[i];
        for(_ j = s[i].length(); j < l1; ++j) putchar(' ');
        for(_ j = 1; j <= l2-l[i]; ++j) putchar(' ');
        cout << a[i];
        putchar('\n');
    }
    
    return 0;
}
