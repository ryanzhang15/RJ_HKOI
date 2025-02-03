
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

constant maxn = 3E3+8;

_ a[maxn], n, m, x, y;

int main(int argc, char * argv[]) {
    
    scanf("%lld%lld", &n, &m);
    for(; n--; ) {
        scanf("%lld%lld", &x, &y);
        _ mx = 0, i = m-1;
        for(; i >= 0; --i) if(a[i] > mx) {
            if(m-i-1 >= y) break;
            mx = a[i];
        }
        a[i+y] = mx+x;
        printf("%lld %lld\n", mx, i+1);
    }
    
    return 0;
}
