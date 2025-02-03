
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
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxk = 1E5+8;
constant maxn = 2E3+8;

_ n, k, f[maxk], d, x, y, a[maxn][maxn], dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1}, l;
struct node {
    _ x, y, d;
};
deque<node> q;

_ find(_ x);
node mn(_ a, _ b, _ c);
int main() {
    
    scanf("%lld%lld", &n, &k);
    l = k;
    for(_ i = 1; i <= k; ++i) {
        f[i] = i;
        scanf("%lld%lld", &x, &y);
        if(a[x][y]) {
            f[find(a[x][y])] = find(i);
            if(--l == 1) {
                puts("0");
                exit(0);
            }
        }
        else {
            a[x][y] = i;
            q.push_back(mn(x, y, 0));
        }
    }
    
    for(; ; ++d) {
        for(deque<node>::iterator i = q.begin(); i != q.end(); ++i) for(_ j = 0; j < 4; ++j) {
            _ nx = i -> x + dx[j];
            _ ny = i -> y + dy[j];
            if(a[nx][ny] && find(a[i -> x][i -> y]) != find(a[nx][ny])) {
                f[find(a[i -> x][i -> y])] = find(a[nx][ny]);
                if(--l == 1) {
                    printf("%lld\n", d);
                    exit(0);
                }
            }
        }
        for(; q.front().d == d; q.pop_front()) {
            node t = q.front();
            for(_ i = 0; i < 4; ++i) {
                _ nx = t.x + dx[i];
                _ ny = t.y + dy[i];
                if(nx <= 0 || ny <= 0 || nx > n || ny > n) continue;
                if(a[nx][ny] && find(a[t.x][t.y]) != find(a[nx][ny])) {
                    f[find(a[nx][ny])] = find(a[t.x][t.y]);
                    if(--l == 1) {
                        printf("%lld\n", d+1);
                        exit(0);
                    }
                }
                if(!a[nx][ny]) {
                    a[nx][ny] = a[t.x][t.y];
                    q.push_back({nx, ny, d+1});
                }
            }
        }
    }

    return 0;
}

node mn(_ a, _ b, _ c) {
    return (node){a, b, c};
}

_ find(_ x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
