
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
typedef const long long maxn;

maxn mn = 1e2+8;

struct node {
    _ x, y, cost, color;
    bool u;
    bool operator < (const node &b) const {
        return cost > b.cost;
    }
};

_ n, m, grid[mn][mn];
_ dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
bool solved, vis[mn][mn];

void bfs();
int main(int argc, char * argv[]) {
    
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    
    cin >> n >> m;
    for(_ i = 0; i < m; i++) {
        _ a, b, c; cin >> a >> b >> c;
        if(!c) grid[a][b] = 1;
        else grid[a][b] = 2;
    }
    
    bfs();
    if(!solved) cout << -1 << endl;
    
    return 0;
    
    ;;;;;;  ;;;;;;  ;;  ;;  ;;;;;   ;;;;;;
    ;;      ;;  ;;  ;; ;;   ;;  ;;  ;;
    ;;      ;;;;;;  ;;;     ;;;;;   ;;;;;
    ;;      ;;  ;;  ;; ;;   ;;  ;;  ;;
    ;;;;;;  ;;;;;;  ;;  ;;  ;;;;;   ;;
}

void bfs() {
    priority_queue<node> q;
    node temp = {1, 1, 0, grid[1][1], true}; q.push(temp);\
    vis[1][1] = true;
    if(temp.x == n && temp.y == n) {
        cout << temp.cost << endl;
        solved = true;
        return;
    }
    while(!q.empty()) {
        node cur = q.top(); q.pop();
        //cout << "x: " << cur.x << ", y: " << cur.y << ", cost: " << cur.cost << ", color: " << cur.color << endl;
        for(_ i = 0; i < 4; i++) {
            temp.x = cur.x + dx[i];
            temp.y = cur.y + dy[i];
            temp.cost = cur.cost;
            temp.u = cur.u;
            if(temp.x <= 0 || temp.y <= 0 || temp.x > n || temp.y > n || vis[temp.x][temp.y]) continue;
            temp.color = grid[temp.x][temp.y];
            if(!temp.color && !temp.u) continue;
            vis[temp.x][temp.y] = true;
            if(!temp.color) {temp.cost += 2; temp.u = false; temp.color = cur.color;}
            else if(temp.color != cur.color) {temp.cost += 1; temp.u = true;}
            else temp.u = true;
            if(temp.x == n && temp.y == n) {
                cout << temp.cost << endl;
                solved = true;
                return;
            }
            q.push(temp);
        }
    }
}

