#ifdef __cplusplus
extern "C" {
#endif
void report(int r, int c);
int oracle(int r1, int r2, int c1, int c2);
void treasure(int N);
#ifdef __cplusplus
}
#endif

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
typedef pair<pair<_, _>, pair<_, _> > _p;
typedef const long long constant;

using namespace std;

int n, t;
map<_p, _> mp;
vector<pair<_, _> > o;

_ recRea(_ xa, _ ya, _ xb, _ yb) {
    if(xa <= 0 || ya <= 0 || xb <= 0 || yb <= 0 || xa > n || ya > n || xb > n || yb > n) return 0;
    if(mp.count(make_pair(make_pair(xa, ya), make_pair(xb, yb)))) return mp[make_pair(make_pair(xa, ya), make_pair(xb, yb))];
    return mp[make_pair(make_pair(xa, ya), make_pair(xb, yb))] = oracle(xa, xb, ya, yb);
}

void treasure(int N) {
    
    n = N;
    t = n>>1;
    for(_ i = 1; i <= t; ++i) {
        _ c1 = recRea(i, 1, n, n), c2 = recRea(i+1, 1, n, n);
        for(_ j = 1; j <= t; ++j) {
            _ d1 = recRea(i, j+1, n, n), d2 = recRea(i+1, j+1, n, n);
            if(c1-c2-d1+d2) o.push_back(make_pair(i, j));
            c1 = d1;
            c2 = d2;
        }
        c1 = recRea(i, 1, n, n)-c1;
        c2 = recRea(i+1, 1, n, n)-c2;
        for(_ j = t+1; j <= n; ++j) {
            _ d1 = recRea(i, 1, n, j), d2 = recRea(i+1, 1, n, j);
            if(c1-c2-d1+d2) o.push_back(make_pair(i, j));
            c1 = d1;
            c2 = d2;
        }
    }
    for(_ j = 1; j <= t+1; ++j) mp[make_pair(make_pair(1, j), make_pair(t, n))] = recRea(1, j, n, n) - recRea(t+1, j, n, n);
    for(_ j = t+1; j <= n; ++j) mp[make_pair(make_pair(1, 1), make_pair(t, j))] = recRea(1, 1, n, j) - recRea(t+1, 1, n, j);
    for(_ i = t+1; i <= n; ++i) {
        _ c1 = recRea(1, 1, i-1, n), c2 = recRea(1, 1, i, n);
        for(_ j = 1; j <= t; ++j) {
            _ d1 = recRea(1, j+1, i-1, n), d2 = recRea(1, j+1, i, n);
            if(c1-c2-d1+d2) o.push_back(make_pair(i, j));
            c1 = d1;
            c2 = d2;
        }
        c1 = recRea(1, 1, i-1, n)-c1;
        c2 = recRea(1, 1, i, n)-c2;
        for(_ j = t+1; j <= n; ++j) {
            _ d1 = recRea(1, 1, i-1, j), d2 = recRea(1, 1, i, j);
            if(c1-c2-d1+d2) o.push_back(make_pair(i, j));
            c1 = d1;
            c2 = d2;
        }
    }
    for(pair<_, _> i : o) report(i.first, i.second);
    
    return;
}

#ifndef ONLINE_JUDGE
#include <cstdio>
#include <cstdlib>
#include <cmath>

bool reported;
int N, answer[105][105], output[105][105];
long long energyUsed;

void report(int r, int c) {
    reported = true;
    
    if (r < 1 || r > N || c < 1 || c > N) {
        printf("Wrong Answer: Invalid call: report(%d, %d)", r, c);
        exit(0);
    }
    
    output[r][c]++;
}

int oracle(int r1, int r2, int c1, int c2) {
    if (!(1 <= r1 && r1 <= r2 && r2 <= N)) {
        printf("Wrong Answer: Invalid call: oracle(%d, %d, %d, %d)", r1, r2, c1, c2);
        exit(0);
    }
    if (!(1 <= c1 && c1 <= c2 && c2 <= N)) {
        printf("Wrong Answer: Invalid call: oracle(%d, %d, %d, %d)", r1, r2, c1, c2);
        exit(0);
    }
    if (reported) {
        printf("Wrong Answer: Invalid calling oracle() after calling report()");
        exit(0);
    }
    
    energyUsed += 1 + N * N - (r2 - r1 + 1) * (c2 - c1 + 1);
    
    int count = 0;
    
    for (int i = r1; i <= r2; i++)
        for (int j = c1; j <= c2; j++)
            count += answer[i][j];
    
    return count;
}

int scoring(long long K, int N) {
    if (K * 16 <= 7 * N * N * N * N + 16 * N * N)
        return 10;
    if (K * 16 <= 7 * N * N * N * N + 32 * N * N * N)
        return 8;
    if (K * 4 <= 3 * N * N * N * N)
        return 4;
    if (K <= N * N * N * N)
        return 1;
    return 0;
}

int main() {
    scanf("%d", &N);
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            scanf("%1d", &answer[i][j]);
        
    treasure(N);
    
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (answer[i][j] != output[i][j]) {
                printf("Wrong Answer: reported incorrectly");
                return 0;
            }
    
    printf("Energy used K = %lld\n", energyUsed);
    printf("Final score = %d out of 10", scoring(energyUsed, N));
    return 0;
}
#endif
