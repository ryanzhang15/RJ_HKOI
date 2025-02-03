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

constant maxn = 1E2+8;

_ n, m, k, ec[maxn], pos, ca;
str a, b, s[maxn];
map<str, str> c;
map<str, _> t;
set<str> en[maxn];

int main(int argc, char * argv[]) {
    
    scanf(_lllin, &n, &m, &k);
    for(_ i = 1; i <= n; ++i) {
        cin >> a;
        b = a;
        for(char &i : b) i = tolower(i);
        c[b] = a;
    }
    for(_ i = 1; i <= m; ++i) {
        cin >> a;
        t[a] = i;
        s[i] = a;
    }
    for(_ i = 1; i <= k; ++i) {
        cin >> a >> b;
        for(char &i : a) i = tolower(i);
        en[t[b]].insert(a);
        if(en[t[b]].size() > ca) {
            ca = en[t[b]].size();
            pos = t[b];
        }
    }
    cout << s[pos] << endl;
    printf(fs(_l+"\n"), ca);
    for(str i : en[pos]) cout << c[i] << endl;
    
    return 0;
}

