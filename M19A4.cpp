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

_ a;

_ fac(_ a);
int main(int argc, char * argv[]) {
    
    cin >> a;
    if(a >= 3) cout << 0 << endl;
    else {
        str b = to_string(fac(fac(fac(a))));
        cout << b[b.length()-1] << endl;
    }
    
    return 0;
}

_ fac(_ a) {
    _ ans = 1;
    for(_ i = a; i > 1; i--) {
        ans *= a;
    }
    return ans;
}
