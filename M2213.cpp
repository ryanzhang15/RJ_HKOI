
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, m, da[maxn], db[maxn], x, y, z, t[maxn<<2], lz[maxn<<2], s = 1E18;
_p a[maxn], b[maxn];
vector<_p> ga[maxn], gb[maxn];
struct node {
    _ p, x;
    bool operator < (const node &b) const {
        return x > b.x;
    }
};
priority_queue<node> q;

int main() {

    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i].first);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &b[i].first);
    for(_ i = 1; i <= m; ++i) {
        scanf("%lld%lld%lld", &x, &y, &z);
        ga[x].push_back(mp(y, z));
        ga[y].push_back(mp(x, z));
    }
    for(_ i = 1; i <= m; ++i) {
        scanf("%lld%lld%lld", &x, &y, &z);
        gb[x].push_back(mp(y, z));
        gb[y].push_back(mp(x, z));
    }
    memset(da, 4, sizeof da);
    da[1] = 0;
    q.push((node){1, 0});
    for(; !q.empty(); ) {
        node t = q.top();
        q.pop();
        if(da[t.p] != t.x) continue;
        for(_p i : ga[t.p]) if(da[i.first] > da[t.p]+i.second) {
            da[i.first] = da[t.p]+i.second;
            q.push((node){i.first, da[i.first]});
        }
    }
    memset(db, 4, sizeof db);
    db[1] = 0;
    q.push((node){1, 0});
    for(; !q.empty(); ) {
        node t = q.top();
        q.pop();
        if(db[t.p] != t.x) continue;
        for(_p i : gb[t.p]) if(db[i.first] > db[t.p]+i.second) {
            db[i.first] = db[t.p]+i.second;
            q.push((node){i.first, db[i.first]});
        }
    }
    for(_ i = 1; i <= n; ++i) {
        a[i].second = da[i];
        b[i].second = db[i];
    }
    sort(a+1, a+1+n, greater<_p>());
    sort(b+1, b+1+n, greater<_p>());
    _ pa = 1;
    _ pb = 1;
    _ mn = 1E17;
    for(; pa <= n || pb <= n; ) {
            if(pa > n || (pa <= n && pb <= n && b[pb].first >= a[pa].first)) {
                mn = min(mn, b[pb].first+b[pb].second);
                ++pb;
            } else {
                s = min(s, mn-a[pa].first+a[pa].second);
                ++pa;
            }
        }
        pa = pb = 1;
        mn = 1E17;
        for(; pa <= n || pb <= n; ) {
            if(pb > n || (pa <= n && pb <= n && a[pa].first >= b[pb].first)) {
                mn = min(mn, a[pa].first+a[pa].second);
                ++pa;
            } else {
                s = min(s, mn-b[pb].first+b[pb].second);
                ++pb;
            }
        }
    printf("%lld\n", s);
    
    return 0;
}


