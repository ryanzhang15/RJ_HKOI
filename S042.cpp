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
#define _lin "%lli"
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
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

constant maxn = 1E2+8;

vector<_> g[maxn];
bool vis[maxn];
_ n, m, c, d[maxn];
queue<_> q, a;

int main(int argc, char * argv[]) {
    
    //reverse topological sort (can I call it that?)                        \
        which means indegree instead of outdegree                           \
        topological sort is ~O(v+e)                                         \
        v is n and e is n(n-1)/2 so in total ~O(n^2) (i can do that right?) \
    
    //all edges r gonna be stored in reverse.
    /*
     This means, whoever doesn't tease *anyone* will get candy first.
     */
    
    /*
     If at any point there is no point with no indegree, then something
     must have gone horribly wrong, exit, exit, exit.
     */
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) {
        scanf(_lin, &m);
        for(; m--; ) {
            scanf(_lin, &c);
            g[i].push_back(c);
            d[c]++;
        }
    }
    
    for(_ i = 1; i <= n; i++) if(!d[i]) {
        q.push(i);
        vis[i] = true;
    }
    
    while(!q.empty()) {
        c = q.front();
        q.pop();
        a.push(c);
        for(_ i : g[c]) {
            if(!vis[i]) if(!--d[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
    }
    
    if(a.size() != n) printf("No Solution\n");
    else {
        while(!a.empty()) {
            printf(fs(_l+" "), a.front());
            a.pop();
        }
        printf("\n");
    }
    
    return 0;
}


