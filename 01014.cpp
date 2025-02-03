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

#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lli"
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

_ v[] = {1, 2, 5, 10, 20, 50, 100, 200, 500}, n, c[7], ans = 1E11, a[7], cnt = 1, ac;
_D N;

void dfs(_ s, _ p, _ t);
int main(int argc, char * argv[]) {
    
    scanf(fs(_f), &N);
    n = N * 10;
    
    dfs(0, 0, 0);
    
    printf("$%g\n", double(ans/10.0));
    
    sort(a, a+ac, greater<_>()); a[ac] = 69;
    for(_ i = 0; i < ac; i++) {
        if(a[i] == a[i+1]) cnt++;
        else {
            printf("%lli $%g\n", cnt, double(a[i]/10.0));
            cnt = 1;
        }
    }
    
    return 0;
}

void dfs(_ s, _ p, _ t) {
    if((t < ans && t >= n) || (t == ans && s < ac)) {
        ans = t;
        ac = s;
        for(_ i = 0; i < s; i++) a[i] = c[i];
    }
    if(s == 4) return;
    for(_ i = p; i < 9; ++i) {
        c[s] = v[i];
        dfs(s+1, i, t+v[i]);
    }
    return;
}
