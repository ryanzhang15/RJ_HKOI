
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
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define ef else if
std::string _l = _lin;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

unordered_map<str, pair<_, _> > x;
unordered_map<str, pair<str, pair<_, _> > > lm;
str s[2] = {"", "111110111100 110000100000"};
_ d, ehx, ehy, dx[] = {1, 2, 2, 1, -1, -2, -2, -1}, dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
char r;
bool flag;

void moni();
void out2(str cur);
void out(str cur);
void dfs(str n, _ c, _ hx, _ hy, _ w);
int main(int argc, char * argv[]) {
    
    for(_ i = 0; i < 5; ++i) {
        for(_ j = 0; j < 5; ++j) {
            while((r = getchar()) != '0' && r != '1' && r != ' ' );
            s[0].push_back(r);
            if(s[0][5*i+j] == ' ') {
                ehx = i;
                ehy = j;
            }
        }
    }
    if(s[0] == s[1]) {
        puts("0");
        exit(0);
    }
    x[s[0]] = {0, 0};
    x[s[1]] = {1, 0};
    for(d = 1; !flag; ++d) {
        dfs(s[0], 1, ehx, ehy, 0);
        dfs(s[1], 1, 2, 2, 1);
    }
    
    //moni();
    
    return 0;
}

void dfs(str n, _ c, _ hx, _ hy, _ w) {
    if(c > d) return;
    for(_ i = 0; i < 8; ++i) {
        _ nx = hx+dx[i];
        _ ny = hy+dy[i];
        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        str t = n;
        swap(t[nx*5+ny], t[hx*5+hy]);
        if(!x.count(t)) {
            x[t] = {w, c};
            if(!w) lm[t] = {n, {nx, ny}};
            else lm[t] = {n, {hx, hy}};
        } else if(x[t].first == (w^1)) {
            if(!w) {
                out2(n);
                printf(fs(_l+" "+_l+"\n"), nx+1, ny+1);
                out(t);
            } else {
                out2(t);
                printf(fs(_l+" "+_l+"\n"), hx+1, hy+1);
                out(n);
            }
            flag = true;
            return;
        } else if(x[t].second < c) continue;
        dfs(t, c+1, nx, ny, w);
        if(flag) return;
    }
    return;
}

void out(str cur) {
    if(cur == s[1]) return;
    printf(fs(_l+" "+_l+"\n"), lm[cur].second.first+1, lm[cur].second.second+1);
    out(lm[cur].first);
    return;
}

void out2(str cur) {
    if(cur == s[0]) return;
    out2(lm[cur].first);
    printf(fs(_l+" "+_l+"\n"), lm[cur].second.first+1, lm[cur].second.second+1);
    return;
}

