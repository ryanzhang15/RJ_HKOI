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

_ sum, cur = 1E10, n, ans, cur2, ans2;

int main(int argc, char * argv[]) {
    
    cin >> n;
    while(n--) {
        _ a; cin >> a;
        sum += a;
        cur = min(a, cur+a);
        ans = min(ans, cur);
        cur2 = max(a, cur2+a);
        ans2 = max(ans2, cur2);
    }
    
    cout << max(ans2, sum-ans) << endl;
    
    return 0;
}
