
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
#define l "%lld"
#define ll "%lld%lld"
#define lll "%lld%lld%lld"
#define llll "%lld%lld%lld%lld"
//#define e else if
std::string _l = l;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef __int128 _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E5+8;
//constant maxn = 10;
struct bindArea {
    _ s, e;
    bool operator < (const bindArea &b) const {
        return e > b.e;
    }
} ba[maxn];

_ f[maxn], n, m, t, e[maxn], start = -1, cpfx[maxn], qmpf[maxn], cnt, dp[maxn][2], x[2], past[maxn][2];
priority_queue<bindArea> q;

void out(_ pos, _ bit);
bool cmp(bindArea a, bindArea b);
void fail();
int main(int argc, char * argv[]) {
    
    scanf(lll, &n, &m, &t);
    
    for(_ i = 1; i <= m; ++i) {
        _ a, b, c;
        scanf(lll, &a, &b, &c);
        if(c) {
            if(f[a] == c) a = e[a]+1;
            for(_ i = a; i <= b; i++) {
                if(f[i] && f[i] != c) fail();
                f[i] = c;
                if(!e[i]) e[i] = b;
                else if(e[i] && e[i] < b) e[i] = b;
                else i = e[i];
            }
        } else {
            if(a == b) fail();
            if(t == 2) ba[++cnt] = {a, b};
            else q.push({a, b});
        }
    }
    
    if(t == 1 && !q.empty()) fail();
    else if(t == 1) {
        puts("YES");
        for(_ i = 1; i <= n; ++i) printf("1 ");
        putchar(10);
        exit(0);
    }
    
    if(t != 2) {
        for(_ i = 1; i <= n; i++) {
            if(f[i] && start == -1) {
                start = i-1;
                while(!q.empty() && q.top().s <= start) q.pop();
            }
            if((f[i] != f[i-1] || !f[i]) && start != -1) {
                while(!q.empty() && i > q.top().s && i <= q.top().e) q.pop();
                if(!f[i]) {
                    if(!f[i+1]) f[i] = f[i-1]-1 < 1 ? f[i-1]+1 : f[i-1]-1;
                    else for(_ j = 1; j <= t && !f[i]; ++j) if(j != f[i-1] && j != f[i+1]) f[i] = j;
                    if(!f[i]) f[i] = f[i-1]-1 < 1 ? f[i-1]+1 : f[i-1]-1;
                }
            }
        }
        
        if(start == -1) {
            start = n;
            while(!q.empty()) q.pop();
        }
        for(_ i = start; i >= 1; --i) f[i] = f[i+1]-1 < 1 ? f[i+1]+1 : f[i+1]-1;
        
        if(!q.empty()) fail();
        puts("YES");
        for(_ i = 1; i <= n; i++) printf(fs(_l+" "), f[i]);
        putchar(10);
    } else {
        sort(ba+1, ba+1+cnt, cmp);
        if(f[1]) dp[1][f[1]-1] = 1;
        else dp[1][1] = dp[1][0] = 1;
        for(_ i = 2; i <= n; ++i) if(f[i]) {
            for(_ j = 0; j <= 1; ++j) {
                x[j] = dp[i-1][j];
                if(j != f[i]-1) for(; x[j] <= cnt && i > ba[x[j]].s && i <= ba[x[j]].e; ) ++x[j];
            }
            if(x[0] > x[1]) {
                dp[i][f[i]-1] = x[0];
                past[i][f[i]-1] = 0;
            } else {
                dp[i][f[i]-1] = x[1];
                past[i][f[i]-1] = 1;
            }
        } else {
            for(_ j = 0; j <= 1; ++j) {
                for(_ k = 0; k <= 1; ++k) {
                    x[k] = dp[i-1][k];
                    if(k != j) for(; x[k] <= cnt && i > ba[x[k]].s && i <= ba[x[k]].e; ) ++x[k];
                }
                if(x[0] > x[1]) {
                    dp[i][j] = x[0];
                    past[i][j] = 0;
                } else {
                    dp[i][j] = x[1];
                    past[i][j] = 1;
                }
            }
        }
        if(dp[n][0] <= cnt && dp[n][1] <= cnt) fail();
        puts("YES");
        if(dp[n][0] > cnt) out(n, 0);
        else out(n, 1);
        putchar(10);
    }
    
    return 0;
}

void fail() {
    puts("NO");
    exit(0);
}

bool cmp(bindArea a, bindArea b) {
    return a.e < b.e;
}

void out(_ pos, _ bit) {
    if(!pos) return;
    out(pos-1, past[pos][bit]);
    printf(fs(_l+" "), bit+1);
    return;
}

