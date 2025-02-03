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

_D c, pct;
_ n;

int main(int argc, char * argv[]) {
    
    cin >> c >> pct >> n;
    while(n--) {
        _D amt = c * pct / 100;
        amt = floor(amt*100)/100;
        c -= amt;
    }
    
    cout << fixed << setprecision(2) << c << endl;
    
    return 0;
}
