#ifdef __cplusplus
extern "C" {
#endif
int getHeaviest(int A, int B, int C);
int getLightest(int A, int B, int C);
int getMedian(int A, int B, int C);
int getNextLightest(int A, int B, int C, int D);
void answer(int W[]);
void init(int T);
void orderCoins();
#ifdef __cplusplus
}
#endif

#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

_ p[728][14], o[728][128], gd[] = {243, 81, 27, 9, 3, 1}, c;
int w[10];
vector<_> v;
map<pair<vector<_>, _>, _> s;

_ scales1(_ dx, _ a, _ b, _ c) {
    _ pa = -1, pb = -1, pc = -1;
    for(_ i = 1; i <= 6; ++i) if(p[dx][i] == a) pa = i;
    ef(p[dx][i] == b) pb = i;
    ef(p[dx][i] == c) pc = i;
    return pa > pb ? (pa > pc ? a : c) : (pb > pc ? b : c);
}

_ scales2(_ dx, _ a, _ b, _ c) {
    _ pa = -1, pb = -1, pc = -1;
    for(_ i = 1; i <= 6; ++i) if(p[dx][i] == a) pa = i;
    ef(p[dx][i] == b) pb = i;
    ef(p[dx][i] == c) pc = i;
    return pa < pb ? (pa < pc ? a : c) : (pb < pc ? b : c);
}

_ scales3(_ dx, _ a, _ b, _ c) {
    _ pa = -1, pb = -1, pc = -1;
    for(_ i = 1; i <= 6; ++i) if(p[dx][i] == a) pa = i;
    ef(p[dx][i] == b) pb = i;
    ef(p[dx][i] == c) pc = i;
    if((pb < pa && pc > pa) || (pb > pa && pc < pa)) return a;
    if((pa < pb && pc > pb) || (pa > pb && pc < pb)) return b;
    return c;
}

_ scales4(_ dx, _ a, _ b, _ c, _ d) {
    _ pa = -1, pb = -1, pc = -1, pd = -1;
    for(_ i = 1; i <= 6; ++i) if(p[dx][i] == a) pa = i;
    ef(p[dx][i] == b) pb = i;
    ef(p[dx][i] == c) pc = i;
    ef(p[dx][i] == d) pd = i;
    if(pd > pa && pd > pb && pd > pc) return scales2(dx, a, b, c);
    if(pa < pd) pa = 1E11;
    if(pb < pd) pb = 1E11;
    if(pc < pd) pc = 1E11;
    return pa < pb ? (pa < pc ? a : c) : (pb < pc ? b : c);
}

bool scales(_ x, vector<_> t) {
    if(x >= 6) return true;
    for(_ i = 1; i <= 120; ++i) {
        _ c[7] = {};
        vector<_> nx[7];
        for(_ j : t) {
            ++c[o[j][i]];
            nx[o[j][i]].push_back(j);
        }
        _ mx = *max_element(c+1, c+7);
        if(mx <= gd[x]) {
            bool rv = true;
            for(_ i = 1; rv && i <= 6; ++i) if(!nx[i].empty()) rv = rv && scales(x+1, nx[i]);
            if(rv) {
                s[make_pair(t, x)] = i;
                return true;
            }
        }
    }
    return false;
}

void init(int T) {
    for(_ i = 1; i <= 6; ++i) p[0][i] = i;
    for(_ i = 1; i < 720; ++i) {
        for(_ j = 1; j <= 6; ++j) p[i][j] = p[i-1][j];
        next_permutation(p[i]+1, p[i]+7);
    }
    for(_ dx = 0; dx < 720; ++dx) {
        _ x = 0;
        for(_ i = 1; i <= 6; ++i) for(_ j = i+1; j <= 6; ++j) for(_ k = j+1; k <= 6; ++k) o[dx][++x] = scales1(dx, i, j, k);
        for(_ i = 1; i <= 6; ++i) for(_ j = i+1; j <= 6; ++j) for(_ k = j+1; k <= 6; ++k) o[dx][++x] = scales2(dx, i, j, k);
        for(_ i = 1; i <= 6; ++i) for(_ j = i+1; j <= 6; ++j) for(_ k = j+1; k <= 6; ++k) o[dx][++x] = scales3(dx, i, j, k);
        for(_ i = 1; i <= 6; ++i) for(_ j = i+1; j <= 6; ++j) for(_ k = j+1; k <= 6; ++k) for(_ l = 1; l <= 6; ++l) if(l != i && l != j && l != k) o[dx][++x] = scales4(dx, i, j, k, l);
    }
    for(_ i = 0; i < 720; ++i) v.push_back(i);
    scales(0, v);
    return;
}

_ scal(_ x) {
    for(int i = 1; i <= 6; ++i) for(int j = i+1; j <= 6; ++j) for(int k = j+1; k <= 6; ++k) if(x-- == 1) return getHeaviest(i, j, k);
    for(int i = 1; i <= 6; ++i) for(int j = i+1; j <= 6; ++j) for(int k = j+1; k <= 6; ++k) if(x-- == 1) return getLightest(i, j, k);
    for(int i = 1; i <= 6; ++i) for(int j = i+1; j <= 6; ++j) for(int k = j+1; k <= 6; ++k) if(x-- == 1) return getMedian(i, j, k);
    for(int i = 1; i <= 6; ++i) for(int j = i+1; j <= 6; ++j) for(int k = j+1; k <= 6; ++k) for(int l = 1; l <= 6; ++l) if(l != i && l != j && l != k) if(x-- == 1) return getNextLightest(i, j, k, l);
    exit(1);
}

void use(_ x, vector<_> t) {
    if(x == 6) {
        c = t[0];
        return;
    }
    _ r = scal(s[make_pair(t, x)]);
    vector<_> nxt;
    for(_ i : t) if(o[i][s[make_pair(t, x)]] == r) nxt.push_back(i);
    use(x+1, nxt);
    return;
}

void orderCoins() {
    use(0, v);
    for(int i = 1; i <= 6; ++i) w[i-1] = p[c][i];
    answer(w);
    return;
}

#ifndef ONLINE_JUDGE

_ aa[8];

int getHeaviest(int A, int B, int C) {
    printf("asked for heaviest: %d %d %d\n", A, B, C);
    if(aa[A] > aa[B] && aa[A] > aa[C]) return A;
    if(aa[B] > aa[C]) return B;
    return C;
}

int getLightest(int A, int B, int C) {
    printf("asked for lightest: %d %d %d\n", A, B, C);
    if(aa[A] < aa[B] && aa[A] < aa[C]) return A;
    if(aa[B] < aa[C]) return B;
    return C;
}

int getMedian(int A, int B, int C) {
    printf("asked for median: %d %d %d\n", A, B, C);
    if((aa[A] < aa[B] && aa[C] > aa[B]) || (aa[A] > aa[B] && aa[C] < aa[B])) return B;
    if((aa[B] < aa[A] && aa[C] > aa[A]) || (aa[B] > aa[A] && aa[C] < aa[A])) return A;
    return C;
}

int getNextLightest(int A, int B, int C, int D) {
    printf("asked for next lightest: %d %d %d %d\n", A, B, C, D);
    if(aa[D] > aa[A] && aa[D] > aa[B] && aa[D] > aa[C]) return getLightest(A, B, C);
    _ a = aa[A], b = aa[B], c = aa[C], d = aa[D];
    if(a < d) a = 1E11;
    if(b < d) b = 1E11;
    if(c < d) c = 1E11;
    if(a < b && a < c) return A;
    if(b < c) return B;
    return C;
}

void answer(int W[]) {
    puts("answered:");
    for(_ i = 0; i < 6; ++i) printf("%d\n", w[i]);
}

int main() {
    init(1);
    for(_ i = 1; i <= 6; ++i) scanf("%lld", &aa[i]);
    orderCoins();
    return 0;
}

#endif
