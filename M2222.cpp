
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <random>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef long double _D;
typedef const long long constant;

_ n, m, k, x, y, vl, ct, op, r;
struct pr {
    _ x, y, vl, ct, id;
    bool operator < (const pr &b) const {
        if(x != b.x) return x < b.x;
        if(y != b.y) return y < b.y;
        return id < b.id;
    }
};
set<pr> sx, sy;
char ch;
map<_, _> mp;

int main() {

    scanf("%lld%lld%lld", &n, &m, &k);
    for(_ i = 1; i <= k; ++i) {
        scanf("%lld", &op);
        if(op == 1) {
            scanf("%lld%lld%lld%lld", &x, &y, &vl, &ct);
            sx.insert((pr){x, y, vl, ct, i});
            sy.insert((pr){y, x, vl, ct, i});
        } else {
            scanf(" %c%lld%lld%lld", &ch, &r, &x, &y);
            mp.clear();
            if(ch == 'R') {
                for(set<pr>::iterator it = sx.lower_bound((pr){r, x, -1, -1, -1}); it != sx.end() && it -> x == r && it -> y <= y; it = sx.lower_bound((pr){r, x, -1, -1, -1})) {
                    mp[it -> ct] += it -> vl;
                    sy.erase((pr){it -> y, it -> x, it -> vl, it -> ct, it -> id});
                    sx.erase(it);
                }
            } else {
                for(set<pr>::iterator it = sy.lower_bound((pr){r, x, -1, -1, -1}); it != sy.end() && it -> x == r && it -> y <= y; it = sy.lower_bound((pr){r, x, -1, -1, -1})) {
                    mp[it -> ct] += it -> vl;
                    sx.erase((pr){it -> y, it -> x, it -> vl, it -> ct, it -> id});
                    sy.erase(it);
                }
            }
            _p s = mp(-1, -1);
            for(_p i : mp) if(i.second > s.second || (i.second == s.second && i.first < s.first)) s = i;
            printf("%lld\n", s.first);
        }
    }
    
    return 0;
}

