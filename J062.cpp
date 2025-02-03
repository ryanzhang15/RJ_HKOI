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

constant maxm = 1E2+88;

bool f[maxm][maxm];
_ n, m, k;

int main(int argc, char * argv[]) {
    
    cin >> n >> m >> k;
    for(_ i = 1; i <= n; i++) f[1][i] = true;
    while(k--) {
        _ a, b, c; cin >> a >> b >> c;
        while(c--) {
            _ d; cin >> d;
            if(f[a][d]) f[b][d] = true;
        }
    }
    
    for(_ i = 1; i <= m; i++) {
        bool flag = true;
        for(_ j = 1; j <= n; j++) {
            if(!f[i][j]) {
                flag = false;
                break;
            }
        }
        if(flag) cout << i << endl;
    }
    
    return 0;
}
