
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
#include <unordered_map>
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 27+5;

bitset<maxn> st, tg, ed;
set<u_> v;
struct node {
    bitset<maxn> p;
    _ s;
};
queue<node> q;

bitset<maxn> transformBitset(bitset<maxn> s, _ x);
bitset<maxn> getBitset();
int main(int argc, char * argv[]) {
    
    st = getBitset();
    tg = getBitset();
    ed = getBitset();
    q.push((node){st, 0});
    for(; !q.empty(); q.pop()) {
        node t = q.front();
        for(_ i = 1; i <= 4; ++i) {
            bitset<maxn> c = transformBitset(t.p, i);
            if(v.count(c.to_ulong())) continue;
            if(c == ed) {
                printf("%lld\n", t.s+1);
                exit(0);
            }
            v.insert(c.to_ulong());
            q.push((node){c, t.s+1});
        }
    }
    
    return 0;
}

bitset<maxn> getBitset() {
    bitset<maxn> rv;
    for(_ i = 1; i <= 27; ++i) {
        _ x;
        scanf("%lld", &x);
        if(x) rv.set(i);
    }
    return rv;
}

bitset<maxn> transformBitset(bitset<maxn> s, _ x) {
    bitset<maxn> t, m, b;
    if(x == 1) s ^= tg;
    ef(x == 2) {
        for(_ i = 1; i <= 9; ++i) if(s[i]) t.set(i+18);
        for(_ i = 10; i <= 18; ++i) if(s[i]) m.set(i-9);
        for(_ i = 19; i <= 27; ++i) if(s[i]) b.set(i-9);
        s = t | m | b;
    } ef(x == 3) {
        for(_ i = 1; i <= 3; ++i) if(s[i]) t.set(i+6);
        for(_ i = 10; i <= 12; ++i) if(s[i]) t.set(i+6);
        for(_ i = 19; i <= 21; ++i) if(s[i]) t.set(i+6);
        for(_ i = 4; i <= 6; ++i) if(s[i]) m.set(i-3);
        for(_ i = 13; i <= 15; ++i) if(s[i]) m.set(i-3);
        for(_ i = 22; i <= 24; ++i) if(s[i]) m.set(i-3);
        for(_ i = 7; i <= 9; ++i) if(s[i]) b.set(i-3);
        for(_ i = 16; i <= 18; ++i) if(s[i]) b.set(i-3);
        for(_ i = 25; i <= 27; ++i) if(s[i]) b.set(i-3);
        s = t | m | b;
    } ef(x == 4) {
        for(_ i = 1; i <= 7; i += 3) if(s[i]) t.set(i+2);
        for(_ i = 10; i <= 16; i += 3) if(s[i]) t.set(i+2);
        for(_ i = 19; i <= 25; i += 3) if(s[i]) t.set(i+2);
        for(_ i = 2; i <= 8; i += 3) if(s[i]) m.set(i-1);
        for(_ i = 11; i <= 17; i += 3) if(s[i]) m.set(i-1);
        for(_ i = 20; i <= 26; i += 3) if(s[i]) m.set(i-1);
        for(_ i = 3; i <= 9; i += 3) if(s[i]) b.set(i-1);
        for(_ i = 12; i <= 18; i += 3) if(s[i]) b.set(i-1);
        for(_ i = 21; i <= 27; i += 3) if(s[i]) b.set(i-1);
        s = t | m | b;
    }
    return s;
}
