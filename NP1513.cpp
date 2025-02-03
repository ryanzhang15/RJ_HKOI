
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
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 23+8;

_ t, n, x, y, a[maxn], s;

void dfs(_ x);
int main(int argc, char * argv[]) {
    
    freopen("landlords.in", "r", stdin);
    freopen("landlords.out", "w", stdout);
    
    scanf("%lld%lld", &t, &n);
    for(; t--; memset(a, 0, sizeof a)) {
        s = 1E18;
        for(_ i = n; i--; ) {
            scanf("%lld%lld", &x, &y);
            if(!x) ++a[15];
            ef(x == 1) ++a[14];
            else ++a[x];
        }
        dfs(0);
        printf("%lld\n", s);
    }
    
    return 0;
}

void dfs(_ x) {
    if(x >= s) return;
    _ c = 0;
    for(_ i = 3; i <= 14; ++i) if(a[i] < 3) c = 0;
    else {
        ++c;
        if(c >= 2) {
            for(_ j = i-c+1; j <= i; ++j) a[j] -= 3;
            dfs(x+1);
            for(_ j = i-c+1; j <= i; ++j) a[j] += 3;
        }
    }
    c = 0;
    for(_ i = 3; i <= 14; ++i) if(a[i] < 2) c = 0;
    else {
        ++c;
        if(c >= 3) {
            for(_ j = i-c+1; j <= i; ++j) a[j] -= 2;
            dfs(x+1);
            for(_ j = i-c+1; j <= i; ++j) a[j] += 2;
        }
    }
    c = 0;
    for(_ i = 3; i <= 14; ++i) if(!a[i]) c = 0;
    else {
        ++c;
        if(c >= 5) {
            for(_ j = i-c+1; j <= i; ++j) --a[j];
            dfs(x+1);
            for(_ j = i-c+1; j <= i; ++j) ++a[j];
        }
    }
    for(_ i = 2; i <= 14; ++i) if(a[i] >= 4) {
        a[i] -= 3;
        for(_ j = 2; j <= 15; ++j) if(j != i && a[j]) {
            --a[j];
            dfs(x+1);
            ++a[j];
        }
        for(_ j = 2; j <= 15; ++j) if(j != i && a[j] >= 2) {
            a[j] -= 2;
            dfs(x+1);
            a[j] += 2;
        }
        --a[i];
        for(_ j = 2; j <= 15; ++j) if(j != i && a[j]) {
            --a[j];
            for(_ k = 2; k <= 15; ++k) if(k != j && a[k]) {
                --a[k];
                dfs(x+1);
                ++a[k];
            }
            ++a[j];
        }
        for(_ j = 2; j <= 14; ++j) if(j != i && a[j] >= 2) {
            a[j] -= 2;
            for(_ k = 2; k <= 14; ++k) if(k != j && a[k] >= 2) {
                a[k] -= 2;
                dfs(x+1);
                a[k] += 2;
            }
            a[j] += 2;
        }
        a[i] += 4;;
    } else if(a[i] >= 3) {
        a[i] -= 3;
        for(_ j = 2; j <= 15; ++j) if(j != i && a[j]) {
            --a[j];
            dfs(x+1);
            ++a[j];
        }
        for(_ j = 2; j <= 14; ++j) if(j != i && a[j] >= 2) {
            a[j] -= 2;
            dfs(x+1);
            a[j] += 2;
        }
        a[i] += 3;
    }
    for(_ i = 2; i <= 15; ++i) x += !!a[i];
    s = min(s, x);
    return;
}
