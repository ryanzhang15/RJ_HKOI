
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
typedef double _D;
typedef string str;
typedef const long long constant;

constant mn = 1E5+8;
constant hr = 8.64E4;

struct boat {
    _ t;
    vector<_> d;
} boats[mn];

_ n, country[mn], ans, c;

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    
    freopen("port.in", "r", stdin);
    freopen("port.out", "a", stdout);
    
    cin >> n;
    for(_ i = 0; i < n; i++) {
        _ k; cin >> boats[i].t >> k;
        while(k--) {
            _ a; cin >> a; boats[i].d.push_back(a);
            if(++country[a] == 1) ans++;
        }
        for(_ j = c; boats[j].t + hr <= boats[i].t && j < i; j++) {
            for(_ i : boats[j].d) if(!(--country[i])) ans--;
            c++;
        }
        cout << ans << endl;
    }
    
    return 0;
}

