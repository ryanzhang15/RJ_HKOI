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

_ n, m;
_D ans;
map<_, _D> data; // i love map

int main(int argc, char * argv[]) {
    
    cin >> n;
    while(n--) {
        _ a; cin >> a;
        _D b; cin >> b;
        data[a] = b;
    }
    cin >> m;
    while(m--) {
        _ a; cin >> a;
        ans += data[a];
    }
    
    cout << setprecision(1) << fixed << ans << endl;
    
    return 0;
}

