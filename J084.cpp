#include <cstdio>
#include <iostream>
#include <cstdlib>
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
 
using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

#define maxn 3008
#define maxo 3000008

struct out {
    char c;
    _ p;
} o[maxo];
_ n, r[maxn], c[maxn], cnt, t, a[maxn][maxn];

int main(int argc, char * argv[]) {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) {
        scanf("%lld", &a[i][j]);
    }
    for(_ i = 1; i <= n; ++i) r[i] = c[i] = i;
    for(_ i = n-1; i >= 1; --i) for(_ j = 1; j <= i; ++j) {
        if(a[1][c[j]] > a[1][c[j+1]]) {
            o[++cnt] = (out){'C', j};
            swap(c[j], c[j+1]);
        }
        if(a[r[j]][1] > a[r[j+1]][1]) {
            o[++cnt] = (out){'R', j};
            swap(r[j], r[j+1]);
        }
    }
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) {
        if(a[r[i]][c[j]] < t) {
            puts("No solution");
            exit(0);
        }
        t = a[r[i]][c[j]];
    }

    for(_ i = 1; i <= cnt; ++i) printf("%c %lld\n", o[i].c, o[i].p);
    puts("Z");    

    return 0;
}


