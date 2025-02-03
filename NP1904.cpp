
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
typedef double _D;
typedef string str;
typedef const long long constant;

typedef pair<_, _> even_odd;

struct node {
    _ pos, steps;
};

constant maxn = 1E5+88;

vector<_> workers[maxn];
_ vis[maxn][2];
even_odd stdst[maxn];
_ n, m, q;
queue<node> Q;

void bfs();
int main(int argc, char * argv[]) {
    
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
    
    cin >> n >> m >> q;
    for(_ i = 0; i < m; i++) {
        _ a, b; cin >> a >> b;
        workers[a].push_back(b);
        workers[b].push_back(a);
    }
    bfs();
    
    while(q --> 0) {
        _ a, b; cin >> a >> b;
        if(b % 2) {
            if(stdst[a].second <= b and stdst[a].second) cout << "Yes" << endl;
            else cout << "No" << endl;
        } else {
            if(stdst[a].first <= b and stdst[a].first) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    return 0;
}

void bfs() {
    node temp = {1, 0}; Q.push(temp);
    while(!Q.empty()) {
        node cur = Q.front();
        _ curs = workers[cur.pos].size();
        for(_ i = 0; i < curs; i++) {
            temp.pos = workers[cur.pos][i];
            temp.steps = cur.steps + 1;
            if(vis[temp.pos][temp.steps % 2]) continue;
            vis[temp.pos][temp.steps % 2] = true;
            if(temp.steps % 2) stdst[temp.pos].second = temp.steps;
            else stdst[temp.pos].first = temp.steps;
            Q.push(temp);
        }
        Q.pop();
    }
    return;
}