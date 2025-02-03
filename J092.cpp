#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <bitset>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>

#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lli"
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
#define _llllin "%lli%lli%lli%lli"
std::string _l = "%lli";
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

constant maxn = 32;

bitset<maxn> v, w[maxn], s;
_ n;
str cur[maxn], t;
stack<_> u, ans;
bool f;

void dfs(_ p);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 0; i < 26; ++i) s.flip(i);
    for(_ i = 1; i <= n; ++i) {
        cin >> t;
        cur[i] = t;
        sort(t.begin(), t.end());
        unique(t.begin(), t.end());
        _ c = 0;
        for(_ j = 0; j < 26; ++j)
            if(t[c]-'A' == j) {
                w[i].flip(j);
                ++c;
            }
    }
    
    dfs(1);
    
    if(f) {
        printf(fs(_l+"\n"), ans.size());
        for(; !ans.empty(); ans.pop()) cout << cur[ans.top()] << endl;
    } else puts("Impossible");
    
    return 0;
}

void dfs(_ p) {
    if(p == n+1) {
        if(v == s && (u.size() < ans.size() || !f)) {
            f = true;
            ans = u;
            return;
        }
        return;
    }
    dfs(p+1);
    bitset<maxn> cpy = v;
    v |= w[p];
    u.push(p);
    dfs(p+1);
    u.pop();
    v = cpy;
}
