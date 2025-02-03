#pragma GCC optimize("O0")
#pragma GCC optimize("O1")
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")

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

constant maxn = 25E3+8;

_ n, pfx[maxn], b;
struct word {
    _ id;
    str s;
    bool operator < (const word &b) const {
        if(pfx[id] != pfx[b.id]) return pfx[id] < pfx[b.id];
        else return s < b.s;
    }
} a[maxn];
vector<char> t;
queue<char> s;

bool cmp(word a, word b);
int main(int argc, char * argv[]) {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    cin >> n;
    for(_ i = 1; i <= n; ++i) {
        cin >> a[i].s;
        a[i].id = i;
    }
    sort(a+1, a+1+n, cmp);
    b = a[n].s.size();
    for(_ i = 1; i <= n-1; ++i) for(_ j = 0; j < b; ++j) {
        if(a[i].s[j] == a[n].s[j]) ++pfx[a[i].id];
        else break;
    }
    sort(a+1, a+n);
    for(_ i = 1; i <= n; ++i) {
        for(_ j = 0; j < t.size(); ++j) if(t[j] != a[i].s[j]) {
            _ ts = t.size();
            for(_ k = j; k < ts; ++k) {
                t.pop_back();
                s.push('-');
            }
            break;
        }
        for(_ j = t.size(); j < a[i].s.size(); ++j) {
            t.push_back(a[i].s[j]);
            s.push(a[i].s[j]);
        }
        s.push('P');
    }
    
    printf(fs(_l+"\n"), s.size());
    for(; !s.empty(); s.pop()) {
        putchar(s.front());
        putchar(10);
    }
    
    return 0;
}

bool cmp(word a, word b) {
    return a.s.length() < b.s.length();
}
