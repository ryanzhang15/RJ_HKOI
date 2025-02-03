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

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E5+8;

_ a[maxn], n, m, cur;

int main(int argc, char * argv[]) {
    
    cin >> n >> m;
    while(m--) {
        _ x, y, d;
        cin >> d >> x >> y;
        a[x] += d;
        a[y+1] -= d;
    }
    for(_ i = 1; i <= n; i++) {
        cur += a[i];
        cout << cur << endl;
    }
    
    return 0;
}

