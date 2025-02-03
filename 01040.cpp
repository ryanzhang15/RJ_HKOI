
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

constant maxn = 1E5+88;
_ n, a[maxn], b[maxn], pos[maxn], p;

void po(_ s, _ e);
int main(int argc, char * argv[]) {
    
    scanf(_l, &n);
    for(_ i = 0; i < n; ++i) scanf(_l, &a[i]);
    for(_ i = 0; i < n; ++i) {
        scanf(_l, &b[i]);
        pos[b[i]] = i;
    }
    po(0, n-1);
    putchar(10);
    
    return 0;
}

void po(_ s, _ e) {
    if(s > e) return;
    _ rt = pos[a[p++]];
    po(s, rt-1);
    po(rt+1, e);
    printf(fs(l_+" "), b[rt]);
    return;
}
