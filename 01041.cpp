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

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E3+8;

struct road {
    _ v, w;
};

_ n, s, e, f[maxn], d[maxn];
vector<road> g[maxn];
bool vis[maxn];

void speak(_ p);
int main(int argc, char * argv[]) {
    
    //SPFAが大好きですね！
    
    memset(d, 50, sizeof(d));
    
    cin >> n >> s >> e;
    _ a, b, c;
    while(cin >> a >> b >> c && a and b and c) { //some shady stuff
        g[a].push_back({b, c});
        g[b].push_back({a, c}); //more shady stuff
    }
    
    queue<_> q;
    d[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty()) {
        _ cur = q.front();
        vis[cur] = false;
        for(road i : g[cur]) {
            if(d[i.v] > d[cur] + i.w) {
                d[i.v] = d[cur] + i.w;
                f[i.v] = cur;
                if(!vis[i.v]) {
                    vis[i.v] = true;
                    q.push(i.v);
                }
            }
        }
        q.pop();
    }
    
    cout << d[e] << endl;
    speak(e);
    cout << endl;
    
    //damn im so good
    
    return 0;
}

void speak(_ p) {
    if(p == s) {
        cout << s <<' ';
        return;
    }
    speak(f[p]);
    cout << p <<' ';
    return;
}
