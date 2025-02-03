
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <ctime>
#include <map>
#include <numeric>
#include <random>
#include <fstream>
#include <iomanip>
#include <string>
#include <list>
#include <deque>
#include <stack>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define ef else if
#define mp make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef long double _D;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, m;
str a[maxn], b[maxn], c[maxn];
vector<str> g;

bool mt(str a, str b, str c);
str read();
int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) a[i] = read();
    for(_ i = 1; i <= m; ++i) {
        b[i] = read();
        c[i] = read();
    }
    for(_ i = 1; i <= n; ++i) {
        bool ok = true;
        for(_ j = 1; j <= m; ++j) if(!mt(a[i], b[j], c[j])) ok = false;
        if(ok) g.push_back(a[i]);
    }
    if(g.empty()) puts("No solution");
    else for(str i : g) printf("%s\n", i.c_str());
    
    return 0;
}

str read() {
    str rv;
    for(_ i = 5; i--; ) {
        char ch;
        scanf(" %c", &ch);
        rv += ch;
    }
    return rv;
}

bool mt(str a, str b, str c) {
    for(_ i = 0; i < 5; ++i) if(c[i] == 'B') {
        if(count(a.begin(), a.end(), b[i])) return false;
    } ef(c[i] == 'Y') {
        if(a[i] == b[i]) return false;
        if(count(a.begin(), a.end(), b[i]) == 0) return false;
    } ef(c[i] == 'G') {
        if(a[i] != b[i]) return false;
    }
    return true;
}
