
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
#define _lllll "%lld%lld%lld%lld%lld"
#define ef else if
const std::string _l = _lin;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;
typedef pair<_, _> _p;

constant maxn = 512;

unordered_set<_> out[2];
unordered_map<_, _> x;
unordered_map<bitset<maxn*maxn>, _p> ans;
_ dx[] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[] = {1, -1, 0, 1, -1, 0, 1, -1}, s = -1, to = 1E13;
bitset<maxn*maxn> n;

_ findNeighbours(_ f, _ pt);
void getNeighbours(_ f);
int main() {
    
    //freopen("/Users/ryan/Desktop/life.in", "r", stdin);
    for(_ i = 0; i < 512; ++i, getchar()) for(_ j = 0; j < 512; ++j) if(getchar() == 'X') out[0].insert(i*512+j);
    for(unordered_set<_>::iterator i = out[0].begin(); i != out[0].end(); ++i) n[*i] = true;
    ans[n] = {1, 1};
    for(_ time = 2; time <= 512; ++time) {
        x.clear();
        out[!(time&1)].clear();
        for(unordered_set<_>::iterator i = out[time&1].begin(); i != out[time&1].end(); ++i) getNeighbours(*i);
        for(unordered_set<_>::iterator i = out[time&1].begin(); i != out[time&1].end(); ++i) if(findNeighbours(*i, time&1) == 2) out[!(time&1)].insert(*i);;
        for(unordered_map<_, _>::iterator i = x.begin(); i != x.end(); ++i) if(i -> second == 3) out[!(time&1)].insert(i -> first);
        n.reset();
        for(unordered_set<_>::iterator i = out[!(time&1)].begin(); i != out[!(time&1)].end(); ++i) n[*i] = true;
        if(!ans.count(n)) {
            s = max(s, (_)1);
            ans[n] = {time, 1};
        } else s = max(s, ++ans[n].second);
    }
    unordered_map<bitset<maxn*maxn>, _p>::iterator outitr;
    for(unordered_map<bitset<maxn*maxn>, _p>::iterator i = ans.begin(); i != ans.end(); ++i) if((i -> second).second == s && (i -> second).first < to) {
        outitr = i;
        to = (i -> second).first;
    }
    for(_ i = 0; i < 512; ++i, putchar(10)) for(_ j = 0; j < 512; ++j) putchar((outitr -> first)[i*512+j] ? 'X' : 'O');
    
    return 0;
}

void getNeighbours(_ f) {
    for(_ i = 0; i < 8; ++i) {
        _p w = {f/512, f%512};
        w.first += dx[i];
        w.second += dy[i];
        if(w.first < 0 || w.second < 0 || w.first >= 512 || w.second >= 512) continue;
        if(!x.count(w.first*512+w.second)) x[w.first*512+w.second] = 1;
        else ++x[w.first*512+w.second];
    }
    return;
}

_ findNeighbours(_ f, _ pt) {
    _ rv = 0;
    for(_ i = 0; i < 8; ++i) {
        _p w = {f/512, f%512};
        w.first += dx[i];
        w.second += dy[i];
        if(w.first < 0 || w.second < 0 || w.first >= 512 || w.second >= 512) continue;
        rv += out[pt].count(w.first*512+w.second);
    }
    return rv;
}
