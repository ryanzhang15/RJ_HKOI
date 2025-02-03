
/*
 ID: ryanjz2024
 LANG: C++11
 TASK: P1909
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
typedef double _d;

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0)
    
    freopen("pencil.in", "r", stdin);
    freopen("pencil.out", "w", stdout);
    
    _d N = 0; cin >> N;
    _0 minPrice = 0;
    for(_0 i = 0; i < 3; i++) {
        _d a = 0.0, b = 0.0; cin >> a >> b;
        minPrice = (minPrice > (_0)ceil(N/a) * b or !minPrice) ? (_0)ceil(N/a) * b : minPrice;
    } cout << minPrice << endl;
    
    return 0;
    
}
