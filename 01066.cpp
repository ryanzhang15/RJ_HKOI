
#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <iostream>
#include <cstdio>
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
//#include <unordered_map>
#include <queue>
#include <list>
#include <set>
//#include <unordered_set>
#include <algorithm>
//#include <random>
#include <numeric>

#define ef else if

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

char s[5], c[5], col[] = "RGBYOP";
bitset<6> v;
_ n, k[300];
struct req {
    char s[5];
    _ a, b;
    void in() {
        scanf(" %s%lld%lld", s, &a, &b);
        return;
    }
} r[10];

void dfs(_ d);
void cpyAns();
int main() {
    
    k['R'] = 0;
    k['G'] = 1;
    k['B'] = 2;
    k['Y'] = 3;
    k['O'] = 4;
    k['P'] = 5;
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) r[i].in();
    dfs(1);
    if(!s[0]) puts("No solution");
    else printf("%s\n", s);
    
    return 0;
}

void cpyAns() {
    if(s[0]) {
        puts("Not yet defined");
        exit(0);
    }
    for(_ i = 0; i < 4; ++i) s[i] = c[i];
    return;
}

void dfs(_ d) {
    if(d > 4) {
        for(_ i = 1; i <= n; ++i) {
            _ a = 0, b = 0;
            for(_ j = 0; j < 4; ++j) {
                if(c[j] == r[i].s[j]) ++a;
                ef(v[k[r[i].s[j]]]) ++b;
            }
            if(a != r[i].a || b != r[i].b) return;
        }
        cpyAns();
        return;
    }
    for(_ i = 0; i < 6; ++i) if(!v[i]) {
        v.flip(i);
        c[d-1] = col[i];
        dfs(d+1);
        v.flip(i);
    }
}
