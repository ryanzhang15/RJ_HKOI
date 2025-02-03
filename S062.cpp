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
#define _lin "%lld"
#define _llin "%lld%lld"
#define _lllin "%lld%lld%lld"
#define _llllin "%lld%lld%lld%lld"
std::string _l = "%lld";
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

constant maxn = 16+8;

bitset<maxn> g[maxn];
_ n, ans, x;
char c;
vector<char> s;

void dfs(vector<char> path, _ pos);
void flipCol(_ col);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) {
        getchar();
        for(_ j = 1; j <= n; ++j) {
            c = getchar();
            if(c == '0') g[i].flip(j);
        }
    }
    
    dfs({}, 1);
    printf(fs(_l+"\n"), s.size());
    for(char i : s) {
        if(i < 'A') printf(fs(_l), (_)i);
        else putchar(i);
        putchar(10);
    }
    
    return 0;
}

void flipCol(_ col) {
    for(_ i = 1; i <= n; ++i) g[i].flip(col);
}

void dfs(vector<char> path, _ pos) {
    if(pos > n) {
        x = 0;
        for(char i : path) flipCol(i-'A'+1);
        for(_ i = 1; i <= n; ++i) {
            if(g[i].count() <= n>>1) path.push_back(i);
            x += max((_)g[i].count(), n-(_)g[i].count());
        }
        for(char i : path) if(i >= 'A' && i <= 'Z') flipCol(i-'A'+1);
        if(x > ans) {
            ans = x;
            s = path;
        }
        return;
    }
    dfs(path, pos+1);
    path.push_back(pos+'A'-1);
    dfs(path, pos+1);
    return;
}
