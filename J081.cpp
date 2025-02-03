
#include <cstdio>
#include <iostream>
#include <cstdlib>
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
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
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

constant maxn = 26+8;
_ l[maxn], n;
bool v[maxn];
char c, t, o;
str d, e;

_ getVal(str x);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    getchar();
    for(; n--; d.clear(), e.clear()) {
        c = getchar();
        getchar();
        v[c-'A'] = true;
        for(; !(cin.peek() == '\n' || (cin.peek() == '-' && !d.empty()) || cin.peek() == '+'); d += t) t = getchar();
        o = getchar();
        if(o == '\n') l[c-'A'] = getVal(d);
        else {
            for(; cin.peek() != '\n'; e += t) t = getchar();
            if(o == '-') l[c-'A'] = getVal(d) - getVal(e);
            else l[c-'A'] = getVal(d) + getVal(e);
            getchar();
        }
    }
    
    for(_0 i = 0; i < 26; ++i) if(v[i]) {
        putchar(i+'A');
        putchar('=');
        printf(fs(_l+"\n"), l[i]);
    }
    
    return 0;
}

_ getVal(str x) {
    if(isdigit(x[0]) || x[0] == '-') return stoll(x);
    else return l[x[0]-'A'];
}
