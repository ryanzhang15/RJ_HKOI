
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
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

_ n, m, c = 1, t;
vector<_> o;

bool bad(_ x, _ y);
int main() {
    
    scanf("%lld %lld", &n, &m);
    for(_ i = 1; i <= n; ++i) if(bad(i, c)) {
        if(--t < 0) {
            c = i;
            t = 0;
        }
    } else ++t;
    o.push_back(c);
    for(_ i = 1; i <= n; ++i) if(i != c && !bad(c, i)) o.push_back(i);
    printf("R ");
    for(_ i = 0; i < o.size(); ++i) printf("%lld ", o[i]);
    putchar(10);
    
    return 0;
}

bool bad(_ x, _ y) {
    printf("T %lld %lld\n", x, y);
    fflush(stdout);
    char ch = getchar();
    for(; ch != 'T' && ch != 'F'; ) ch = getchar();
    return ch == 'F';
}
