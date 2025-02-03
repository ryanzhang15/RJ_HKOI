
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
//#include <unordered_set>
#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define ef else if
std::string _l = _lin;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 7;
char st[maxn], es[maxn] = "12345 ", lm[750][maxn];
_ dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, c, x, y;
unordered_map<str, _> m;

void out(_ x, bool ts);
void out(_ x);
void dfs(_ d, _ hx, _ hy);
_ h();
void in();
int main(int argc, char * argv[]) {
    
    in();
    memcpy(lm[0], st, sizeof st);
    if(!strcmp(st, es)) {
        out(0, false);
        exit(0);
    }
    for(c = 1; ; ++c, m.clear()) dfs(1, x, y);
    
    return 0;
}

void in() {
    st[0] = getchar();
    getchar();
    getchar();
    st[1] = getchar();
    getchar();
    getchar();
    st[2] = getchar();
    getchar();
    st[3] = getchar();
    getchar();
    getchar();
    st[4] = getchar();
    getchar();
    getchar();
    st[5] = getchar();
    getchar();
    for(_ i = 0; i < 6; ++i) if(st[i] == ' ') {
        x = i/3;
        y = i%3;
    }
    return;
}

_ h() {
    _ rv = 0;
    for(_ i = 0; i < 5; ++i) rv += es[i] != st[i];
    return rv;
}

void dfs(_ d, _ hx, _ hy) {
    if(d + h() > c) return;
    for(_ i = 0; i < 4; ++i) {
        _ nx = hx+dx[i];
        _ ny = hy+dy[i];
        if(nx < 0 || ny < 0 || nx >= 2 || ny >= 3) continue;
        swap(st[nx*3+ny], st[hx*3+hy]);
        if(m[st] == d) {
            swap(st[nx*3+ny], st[hx*3+hy]);
            continue;
        }
        m[st] = d;
        memcpy(lm[d], st, sizeof st);
        if(!strcmp(st, es)) {
            for(_ i = 0; i < d; ++i) out(i, true);
            out(d, false);
            exit(0);
        }
        dfs(d+1, nx, ny);
        swap(st[nx*3+ny], st[hx*3+hy]);
    }
}

void out(_ x, bool ts) {
    putchar(lm[x][0]);
    putchar(32);
    putchar(32);
    putchar(lm[x][1]);
    putchar(32);
    putchar(32);
    putchar(lm[x][2]);
    putchar(10);
    putchar(lm[x][3]);
    putchar(32);
    putchar(32);
    putchar(lm[x][4]);
    putchar(32);
    putchar(32);
    putchar(lm[x][5]);
    putchar(10);
    if(ts) putchar(10);
    return;
}
