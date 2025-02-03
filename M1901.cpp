
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

#define pie 3.14159265358979323

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef double _D;
typedef string str;
typedef const long long constant;

_D x, y, ans;

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    
    cin >> x >> y;
    ans += pie*(x/4)*(x/4);
    ans += x * y * 1/2;
    cout << setprecision(999) << ans << endl;
    
    return 0;
}

