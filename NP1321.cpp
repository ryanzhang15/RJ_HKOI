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

_ n, c, l, a;

int main(int argc, char * argv[]) {
    
    freopen("block.in", "r", stdin);
    freopen("block.out", "w", stdout);
    
    cin >> n;
    for(; n--; ) { // i only use for loops
        cin >> c;
        a += max((_)0, c-l);
        l = c;
    }
    cout << a << endl;
    return 0;
}
