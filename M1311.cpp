#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

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
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%llf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E4+8;

_ n, m, c, a, b, ans, d[maxn];
vector<_> g[maxn];
bool vis[maxn];

int main(int argc, char * argv[]) {
    
    memset(d, 50, sizeof(d));

    scanf(fs(_l+_l+_l), &n, &m, &c);
    for(; m--; ) {
        scanf(fs(_l+_l), &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    //spfa
    queue<_> q;
    d[1] = 0;
    q.push(1);
    while(!q.empty()) {
        _ cur = q.front();
        vis[cur] = false;
        for(_ i : g[cur]) {
            if(d[i] > d[cur] + 1) {
                d[i] = d[cur] + 1;
                if(!vis[i]) {
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
        q.pop();
    }
    
    if(d[n] == d[maxn]-1) printf("-1\n");
    //did not consider -1 but still ac;
    else printf(fs(_l+"\n"), max((_)0, d[n]-c));
    
    return 0;
}
