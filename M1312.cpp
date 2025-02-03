
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

constant maxn = 1E3+8;

struct node {
    _ s, e, ht;
    bool operator < (const node &b) const {
        return s+ht < b.s+b.ht;
    }
} a[maxn];
_ n, t;

int main(int argc, char ** argv) {

    for(; scanf("%lld", &n) && n; ) {
        for(_ i = 1; i <= n; ++i) {
            scanf("%lld%lld", &a[i].s, &a[i].e);
            a[i].ht = ((a[i].e-a[i].s)>>1)+1;
        }
        sort(a+1, a+1+n);
        t = 0;
        for(_ i = 1; i <= n; ++i) {
            t = max(t, a[i].s)+a[i].ht;
            if(t > a[i].e) goto no;
        }
        puts("YES");
        continue;
        no:
        puts("NO");
    }

    return 0;
}

