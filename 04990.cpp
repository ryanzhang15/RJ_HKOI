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
//#include <unordered_map>
#include <queue>
#include <list>
#include <set>
//#include <unordered_set>
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

constant maxn = 1E2;

struct edge {
    _ u, v, w;
    bool operator < (const edge &b) const {
        return w < b.w;
    }
} graph[maxn<<7];

struct building {
    _ x1, x2, y1, y2;
    void getBuilding() {
        scanf(_llllin, &x2, &y2, &x1, &y1);
        return;
    }
} city[maxn];

_ n, cnt, p[maxn], s, tc;

_ find(_ t);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) city[i].getBuilding();
    for(_ i = 1; i <= n; ++i) for(_ j = i+1; j <= n; ++j) {
        //if x overlap
        if((city[i].x1 >= city[j].x1 && city[j].x2 >= city[i].x1) || (city[i].x2 >= city[j].x1 && city[j].x2 >= city[i].x1)) graph[++cnt] = {i, j, min(abs(city[i].y1-city[j].y2), abs(city[i].y2-city[j].y1))};
        //if y overlap
        if((city[i].y1 >= city[j].y1 && city[j].y2 >= city[i].y1) || (city[i].y2 >= city[j].y1 && city[j].y2 >= city[i].y1))graph[++cnt] = {i, j, min(abs(city[i].x1-city[j].x2), abs(city[i].x2-city[j].x1))};
    }
    for(_ i = 1; i <= n; ++i) p[i] = i;
    sort(graph+1, graph+1+cnt);
    tc = n-1;
    
    bool flag = false;
    //kruskal
    for(_ i = 1; i <= cnt && !flag; ++i) {
        _ x = find(graph[i].u);
        _ y = find(graph[i].v);
        if(x != y) {
            s += graph[i].w;
            p[x] = y;
            if(!--tc) flag = true;
        }
    }
    if(!flag) puts("FAIL");
    else printf(fs(_l+"\n"), s);
    
    return 0;
}

_ find(_ t) {
    return p[t] == t ? t : p[t] = find(p[t]);
}
