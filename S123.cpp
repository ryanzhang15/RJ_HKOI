
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
#define _l "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define ef else if
std::string l_ = _l;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 3E3+8;
_ a[maxn], b[maxn], n, s1, s2, o, s = -1, d;

void fail();
int main(int argc, char * argv[]) {
    
    scanf(_lll, &s1, &s2, &d);
    if(s1 > s2) fail();
    for(_ i = 1; i <= s1; ++i) scanf(_l, &a[i]);
    for(_ i = 1; i <= s2; ++i) scanf(_l, &b[i]);
    for(_ i = 1; i <= s2-s1+1 && !~s; ++i) {
        if(b[i] < a[1]) continue;
        o = b[i]-a[1];
        d = 1;
        for(_ j = i; j <= s2; ++j) if(b[j]-a[d] == o) ++d;
        if(d == s1+1) s = o;
    }
    if(!~s) fail();
    printf(fs(l_+"\n"), s);
    
    return 0;
}

void fail() {
    puts("Impossible");
    exit(0);
}
