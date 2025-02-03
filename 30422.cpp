
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
#define l "%lld"
#define ll "%lld%lld"
#define lll "%lld%lld%lld"
#define llll "%lld%lld%lld%lld"
std::string _l = l;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

unordered_map<str, pair<_, _> > x;
str s[2] = {"111110111100 110000100000", ""};
_ d, ehx, ehy, dx[] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

void dfs(_ c, _ hx, _ hy, _ w);
int main(int argc, char * argv[]) {
    
    for(_ i = 0; i < 5; ++i) {
        for(_ j = 0; j < 5; ++j) {
            s[1].push_back(getchar());
            if(s[1][5*i+j] == ' ') {
                ehx = i;
                ehy = j;
            }
        }
        getchar();
    }
    if(s[0] == s[1]) {
        puts("0");
        exit(0);
    }
    x[s[0]] = {0, 0};
    x[s[1]] = {1, 0};
    for(d = 1; ; ++d) {
        dfs(1, 2, 2, 0);
        dfs(1, ehx, ehy, 1);
    }
    
    return 0;
}

void dfs(_ c, _ hx, _ hy, _ w) {
    if(c > d) return;
    for(_ i = 0; i < 8; ++i) {
        _ nx = hx+dx[i];
        _ ny = hy+dy[i];
        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        swap(s[w][nx*5+ny], s[w][hx*5+hy]);
        if(!x.count(s[w])) x[s[w]] = {w, c};
        else if(x[s[w]].first == (w^1)) {
            printf(fs(_l+"\n"), x[s[w]].second+c);
            exit(0);
        } else if(x[s[w]].second < c) {
            swap(s[w][nx*5+ny], s[w][hx*5+hy]);
            continue;
        }
        dfs(c+1, nx, ny, w);
        swap(s[w][nx*5+ny], s[w][hx*5+hy]);
    }
    return;
}
