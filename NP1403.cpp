
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>

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

_0 find(_0 N, _0 i, _0 j);

int main(int argc, char * argv[]) {
    
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    
    _0 N, i, j; cin >> N >> i >> j;
    
    cout << find(N, i , j) << endl;
    
    return 0;
    
}

_0 find(_0 N, _0 i, _0 j) {
    if(i == 1) {
        return j;
    } else if(j == N) {
        return N + i - 1;
    } else if(i == N) {
        return 3*N - j - 1;
    } else if(j == 1) {
        return 4*N - i - 2;
    } else {
        return find(N - 2, i - 1, j - 1) + (4 * (N - 1));
    }
}
