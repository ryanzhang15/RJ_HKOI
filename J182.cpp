
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

constant maxn = 3E2+8;
struct rope {
    _ len;
    vector<pair<_, _> > path;
} r[maxn*maxn];
_ cnt = 1, n, m, c, x, y, d = 1, j;
bool p[maxn][maxn];

int main(int argc, char * argv[]) {
    
    scanf(_lll, &n, &m, &c);
    for(; c--; ) {
        scanf(_ll, &x, &y);
        p[x][y] = true;
    }
    j = 1;
    for(_ i = 1; i <= n; ++i, d *= -1) {
        for(; j >= 1 && j <= m; j += d) {
            if(p[i][j]) cnt += !!r[cnt].len;
            else {
                ++r[cnt].len;
                r[cnt].path.push_back({i, j});
            }
        }
        j -= d;
    }
    
    if(!r[cnt].len) --cnt;
    printf(fs(l_+"\n"), cnt);
    for(_ i = 1; i <= cnt; ++i) {
        printf(fs(l_+"\n"), r[i].len);
        for(pair<_, _> j : r[i].path) printf(fs(l_+" "+l_+"\n"), j.first, j.second);
    }
    
    return 0;
}
