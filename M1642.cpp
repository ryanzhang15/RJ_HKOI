#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 5E5+8;

_ T[maxn<<2], y[maxn<<2], a[maxn], C[maxn], n, m, x, t[maxn][2], rd[maxn], vl[maxn], sz[maxn], c[maxn], cnt, cmd, rt, s;
_p mn;
bool trp;

inline _ rnk(_ p, _ x);
inline void insert(_ &p, _ x);
inline void rotate(_ &p, _ d);
inline void pushUp(_ p);
inline _ newNode(_ x);
inline _p query(_ L, _ R, _ l, _ r, _ pos);
inline void update(_ p, _ c, _ l, _ r, _ pos);
inline void build(_ l, _ r, _ pos);
inline void pushhUp(_ pos);
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for(_ i = n; i >= 1; --i) {
		insert(rt, a[i]);
		s += C[i] = rnk(rt, a[i])-1;
	}
	printf("%lld\n", s);
	build(1, n, 1);
	for(; m--; ) {
		scanf("%lld", &x);
		for(;;) {
			mn = query(x, n, 1, n, 1);
			if(mn.first > a[x]) break;
			update(mn.second, 1E11, 1, n, 1);
			s -= C[mn.second];
			C[mn.second] = 0;
		}
		printf("%lld\n", s);	
	}
	
	return 0;
}

inline void pushhUp(_ pos) {
	if(T[pos<<1] < T[pos<<1|1]) {
		T[pos] = T[pos<<1];
		y[pos] = y[pos<<1];
	} else {
		T[pos] = T[pos<<1|1];
		y[pos] = y[pos<<1|1];
	}
    return;
}

inline void build(_ l, _ r, _ pos) {
    if(l == r) {
        T[pos] = a[r];
        y[pos] = l;
        return;
    }
    _ m = (l+r)>>1;
    build(l, m, pos<<1);
    build(m+1, r, pos<<1|1);
    pushhUp(pos);
    return;
}

inline void update(_ p, _ c, _ l, _ r, _ pos) {
	if(l == r) {
		T[pos] = c;
		y[pos] = l;
		return;
	}
	_ m = (l+r)>>1;
	if(p <= m) update(p, c, l, m, pos<<1);
    else update(p, c, m+1, r, pos<<1|1);
    pushhUp(pos);
    return;
}

inline _p query(_ L, _ R, _ l, _ r, _ pos) {
    if(L <= l && r <= R) return make_pair(T[pos], y[pos]);
    _ md = (l+r)>>1;
    _p ca = make_pair(-1, -1), cb = make_pair(-1, -1);
    if(L <= md) ca = query(L, R, l, md, pos<<1);
    if(R > md) cb = query(L, R, md+1, r, pos<<1|1);
    if(!~ca.second) return cb;
    if(!~cb.second) return ca;
    return min(ca, cb);
}

inline _ newNode(_ x) {
    vl[++cnt] = x;
    rd[cnt] = rand();
    sz[cnt] = c[cnt] = 1;
    return cnt;
}

inline void pushUp(_ p) {
    sz[p] = sz[t[p][0]] + sz[t[p][1]] + c[p];
    return;
}

inline void rotate(_ &p, _ d) {
    _ k = t[p][d^1];
    t[p][d^1] = t[k][d];
    t[k][d] = p;
    pushUp(p);
    pushUp(k);
    p = k;
    return;
}

inline void insert(_ &p, _ x) {
    if(!p) {
        p = newNode(x);
        return;
    }
    if(vl[p] == x) {
        ++sz[p];
        ++c[p];
        return;
    }
    _ d = x > vl[p];
    insert(t[p][d], x);
    if(rd[p] < rd[t[p][d]]) rotate(p, d^1);
    pushUp(p);
    return;
}

inline _ rnk(_ p, _ x) {
    if(!p) return 0;
    ef(vl[p] == x) {
        trp = false;
        return sz[t[p][0]]+1;
    }
    ef(vl[p] < x) return sz[t[p][0]] + c[p] + rnk(t[p][1], x);
    else return rnk(t[p][0], x);
}