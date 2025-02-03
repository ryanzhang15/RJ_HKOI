/*
 ID: ryanjz2024
 LANG: C++11
 TASK:
 */

#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>

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

_0 gcd (_0 a, _0 b);

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0)
    
    freopen("ratio.in", "r", stdin);
    freopen("ratio.out", "a", stdout);
    
    _0 A = 0, B = 0, L = 0; cin >> A >> B >> L;
    _0 a = 0, b = 0;
    _D mind = 0.0;
    
    for(_0 i = 1; i <= L; i++) {
        for(_0 j = 1; j <= L; j++) {
            if((_D)((_D)i / (_D)j) >= (_D)((_D)A / (_D)B) && gcd(i, j) == 1 && ((_D)((_D)i/(_D)j) < mind || mind == 0.0)) {
                mind = (_D)((_D)i/(_D)j);
                a = i;
                b = j;
            }
        }
    } cout << a << ' ' << b << endl;
    
    return 0;
    
}

_0 gcd (_0 a, _0 b) {
    if(!b) return a;
    return gcd(b, a % b);
}
