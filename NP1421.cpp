
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
typedef const long long maxn;

typedef pair<_, _> coords;

map<coords, _> places;
_ d, n, pp, bv;
vector<vector<bool> > aa (129, vector<bool> (129, false));

_ cc(pair<_, _> sp);

int main(int argc, char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("wireless.in", "r", stdin);
    freopen("wireless.out", "w", stdout);
    
    cin >> d >> n;
    for(_ i = 0; i < n; i++) {
        _ a, b, c; cin >> a >> b >> c;
        places[make_pair(a, b)] = c;
        aa[a][b] = true;
    }
    
    for(_ i = 0; i <= 128; i++) {
        for(_ j = 0; j <= 128; j++) {
            _ cur = cc(make_pair(i, j));
            if(cur > bv) {
                bv = cur; pp = 1;
            } else if(cur == bv) {
                pp++;
            }
        }
    }
    
    cout << pp << ' ' << bv << endl;
    
    return 0;
}

_ cc(pair<_, _> sp) {
    _ rv = 0;
    _ ub1 = ((sp.first + d) > 128) ? 128 : sp.first + d, ub2 = ((sp.second + d) > 128) ? 128 : sp.second + d;
    for(_ i = ((sp.first - d) < 0) ? 0 : sp.first - d; i <= ub1; i++) {
        for(_ j = ((sp.second - d) < 0) ? 0 : sp.second - d; j <= ub2; j++) {
            if(aa[i][j]) rv += places[make_pair(i, j)];
        }
    }
    return rv;
}
