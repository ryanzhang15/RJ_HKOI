

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
#include <random>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define _lllll "%lld%lld%lld%lld%lld"
#define ef else if
const std::string _l = _lin;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;
typedef pair<_, _> _p;

constant maxk = 3E3+88;

_ w, h, k, a, b, c, d, s;
_p cs[maxk];

_p getPair();
int main() {
    
    scanf(_lll, &w, &h, &k);
    cs[1] = {0, 0};
    cs[2] = {0, h+1};
    cs[3] = {w+1, 0};
    cs[4] = {w+1, h+1};
    for(_ i = 1; i <= k; ++i) cs[i+4] = getPair();
    for(_ i = 5; i <= k+4; ++i) {
        a = b = -1E14;
        c = d = 1E14;
        for(_ j = 1; j <= k+4; ++j) if(i != j) {
            if(cs[j].first < cs[i].first && cs[j].first > a) a = cs[j].first;
            if(cs[j].second < cs[i].second && cs[j].second > b) b = cs[j].second;
            if(cs[j].first > cs[i].first && cs[j].first < c) c = cs[j].first;
            if(cs[j].second > cs[i].second && cs[j].second < d) d = cs[j].second;
        }
        if((c-a-1)*(d-b-1) >= 1LL<<31) continue;
        s = max(s, (c-a-1)*(d-b-1));
    }
    
    printf(fs(_l+"\n"), s);
    
    return 0;
}

_p getPair() {
    _p rv;
    scanf(_ll, &rv.first, &rv.second);
    return rv;
}
