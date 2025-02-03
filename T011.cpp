#include <bits/stdc++.h>

using namespace std;

typedef long long _;
typedef const long long constant;
typedef pair<_, _> _p;

set<_p> v;
map<_p, _> x;
vector<_p> g;
_p c;
_ k, n, dx[] = {1, 1, 1, -1, -1, -1, 0, 0}, dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

_ findNeighbours(_p f);
void getNeighbours(_p f);
_p getPair();
int main() {
    
    scanf("%lld", &k);
    for(; k--; ) {
        c = getPair();
        v.insert(c);
    }
    scanf("%lld", &n);
    for(; --n; ) {
        x.clear();
        for(set<_p>::iterator i = v.begin(); i != v.end(); ++i) getNeighbours(*i);
        for(set<_p>::iterator i = v.begin(); i != v.end(); ++i) if(findNeighbours(*i) == 2) g.push_back(*i);
        v.clear();
        for(map<_p, _>::iterator i = x.begin(); i != x.end(); ++i) if(i -> second == 3) v.insert(i -> first);
        for(_ i = 0; i < g.size(); ++i) v.insert(g[i]);
        g.clear();
    }
    
    printf("%lld\n", (_)v.size());
    for(set<_p>::iterator i = v.begin(); i != v.end(); ++i) printf("%lld %lld\n", (*i).first, (*i).second);
    
    return 0;
    
}

_p getPair() {
    _p rv;
    scanf("%lld%lld", &rv.first, &rv.second);
    return rv;
}

void getNeighbours(_p f) {
    for(_ i = 0; i < 8; ++i) {
        _p w = f;
        w.first += dx[i];
        w.second += dy[i];
        if(!x.count(w)) x[w] = 1;
        else ++x[w];
    }
    return;
}

_ findNeighbours(_p f) {
    _ rv = 0;
    for(_ i = 0; i < 8; ++i) {
        _p w = f;
        w.first += dx[i];
        w.second += dy[i];
        rv += !!v.count(w);
    }
    return rv;
}
