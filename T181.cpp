#pragma G++ optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma G++ target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

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
#include <unordered_set>
#include <bitset>

#include <algorithm>
#include <numeric>
#include <random>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 3E5+8;
constant mod = 6912477;

_ n, m, b[maxn], p[maxn], x, o[maxn], a[maxn];
struct hashmap {
    vector<_p> data[mod+1];
    inline void insert(_ x) {
        data[x%mod].push_back(make_pair(x, 0));
        return;
    }
    inline void add(_ x, _ k) {
        _ dx = x%mod;
        for(_p &i : data[dx]) if(i.first == x) {
            i.second += k;
            return;
        }
        return;
    }
    inline _ get(_ x) {
        _ dx = x%mod;
        for(_p &i : data[dx]) if(i.first == x) return i.second;
        return -1;
    }
} mp;
deque<_p> q, qp;

inline _ __gcd(_ a, _ b) {
    return !b ? a : __gcd(b, a%b);
}

inline _ read();
inline _ rgSum(_ l, _ r);
int main() {
        
    n = read();
    for(_ i = 1; i <= n; ++i) a[i] = read();
    for(_ i = 1; i <= n; ++i) {
        b[i] = read();
        p[i] = b[i]*i+p[i-1];
        b[i] += b[i-1];
    }
    m = read();
    for(_ i = 1; i <= m; ++i) {
        o[i] = read();
        mp.insert(o[i]);
    }
    for(_ i = n; i >= 1; --i) {
        q.push_front(make_pair(a[i], i));
        for(_ j = 1; j < q.size(); ++j) q[j].first = __gcd(q[j].first, q[j-1].first);
        qp.clear();
        qp.push_back(q[0]);
        for(_ j = 1; j < q.size(); ++j) if(q[j].first != q[j-1].first) qp.push_back(q[j]);
        q = qp;
        for(_ j = 0; j < q.size(); ++j) mp.add(q[j].first, rgSum(i, j == q.size()-1 ? n : q[j+1].second-1)-rgSum(i, q[j].second-1));
    }
    for(_ i = 1; i <= m; ++i) printf("%lld\n", mp.get(o[i]));
    
    return 0;
}

inline _ rgSum(_ l, _ r) {
    return (r+1)*(b[r]-b[l-1])-p[r]+p[l-1];
}

inline _ read() {
    _ x = 0;
    char ch = getchar_unlocked();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar_unlocked();
    for(; ch >= '0' && ch <= '9'; ch = getchar_unlocked()) x = (x<<3)+(x<<1)+(ch^48);
    return x;
}
