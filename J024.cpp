
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
typedef const long long constant;

_ mode, mc, m[30008], n, a[30008];
_D avg;

int main(int argc, char * argv[]) {
    
    cin >> n;
    for(_ i = 0; i < n; i++) {
        cin >> a[i];
        if(++m[a[i]] > mc) {
            mc = m[a[i]];
            mode = a[i];
        }
        avg += a[i];
    }
    
    sort(a, a+n);
    _D med = (n%2) ? a[n/2] : ((_D)a[(n-1)/2] + (_D)a[n/2])/2.0;
    
    if(floor(med) == med) printf("%.3f\n%lli\n%lli\n", avg/(_D)n, (_)floor(med), mode);
    else printf("%.3f\n%.1f\n%lli\n", avg/(_D)n, ((_D)a[(n-1)/2] + (_D)a[n/2])/2.0, mode);
    
    return 0;
}

