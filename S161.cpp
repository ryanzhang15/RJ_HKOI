
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

constant maxk = 2E3+8;
_ n, k, x, y, sx, sy, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, dir[300], s, freq[maxk<<1][maxk<<1];
char t[maxk];

inline void tin();
inline _ read();
int main(int argc, char ** argv) {
    
    dir['U'] = 1;
    dir['R'] = 2;
    dir['L'] = 3;
    n = read();
    k = read();
    sx = read();
    sy = read();
    tin();
    x = y = 2000;
    for(register _ i = 1; i <= k; ++i) for(register _ j = 1; j <= k; ++j) {
        x += dx[dir[t[j]]];
        y += dy[dir[t[j]]];
        if(x <= 2000-sx || y <= 2000-sy || x > 2000+n-sx || y > 2000+n-sy) goto out;
        if(x >= 0 && y >= 0 && x <= 4000 && y <= 4000 && ++freq[x][y] > s) s = freq[x][y];
    }
    out:
    printf("%lld\n", s);
    
    return 0;
}

inline _ read() {
    _ x = 0; char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; ch >= '0' && ch <= '9'; ch = getchar_unlocked()) x = (x*10)+ch-'0';
    return x;
}

inline void tin() {
    char ch = getchar_unlocked();
    for(; ch != 'U' && ch != 'D' && ch != 'L' && ch != 'R'; ) ch = getchar_unlocked();
    for(_ i = 1; i <= k; ++i, ch = getchar_unlocked()) t[i] = ch;
}
