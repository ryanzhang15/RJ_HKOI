
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

constant maxn = 18+8;
_ n, m, a[maxn], t, mn, dx;

int main(int argc, char * argv[]) {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 0; i <= 18; ++i) if(n & (1<<i)) {
        a[i] = 1;
        ++t;
    }
    for(_ i = t; i <= m-1; ++i) {
        mn = 1E18;
        for(_ j = 1; j <= 18; ++j) if(a[j] && a[j-1] < mn) {
            mn = a[j-1];
            dx = j;
        }
        --a[dx];
        ++++a[dx-1];
    }
    for(;;) {
        t = 0;
        for(_ i = 0; i <= 18; ++i) if(a[i]) {
            --a[i];
            t += (1<<i);
        }
        if(!t) break;
        printf("%lld\n", t);
    }
    
    return 0;
}
