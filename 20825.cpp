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

constant maxn = 2E2+5;
//constant maxn = 8;

struct node {
    _ x, y, s;
};

_ n, m, c, d, f, a = 1E10, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, dp[maxn][maxn], e[maxn][maxn];
bool b[maxn][maxn];
queue<node> q;

int main(int argc, char * argv[]) {
    
    scanf(fs(_l+_l), &n, &m);
    for(_ i = 0; i < n; ++i) {
        scanf(_lin, &c);
        while(cin.peek() != '\n') {
            scanf(_lin, &d);
            b[c][d] = true; 
        }
    }
    
    b[1][1] = true;
    dp[1][1] = 1;
    node temp = {1, 1, 0};
    q.push(temp);
    while(!q.empty()) {
        node cur = q.front();
        for(_ i = 0; i < 4; i++) {
            temp.x = cur.x + dx[i];
            temp.y = cur.y + dy[i];
            if(temp.x <= 0 || temp.y <= 0 || temp.x > n || temp.y > m) continue;
            if(b[temp.x][temp.y]) continue;
            if(dp[temp.x][temp.y] && e[temp.x][temp.y] < cur.s) continue;
            temp.s = cur.s+1;
            if(!dp[temp.x][temp.y]) {
                q.push(temp);
                e[temp.x][temp.y] = temp.s;
            }
            dp[temp.x][temp.y] += dp[cur.x][cur.y];
        }
        q.pop();
    }
    
    printf(fs(_l+"\n"), dp[n][m]);
    
    return 0;
}

