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

_ n, x, y, r, ans;
_D c, d;

int main(int argc, char * argv[]) {
    
    cin >> n >> c;
    r = 10*c;
    while(n--) {
        cin >> c >> d;
        x = 10*c; y = 10*d;
        for(_ p = 10; p >= 1; p--) {
            if(x*x+y*y <= (400*(11-p)+r)*(400*(11-p)+r)) {
                ans += p;
                break;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
