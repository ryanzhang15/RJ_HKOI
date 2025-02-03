#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <bitset>
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

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _llin "%lld%lld"
#define _lllin "%lld%lld%lld"
#define _llllin "%lld%lld%lld%lld"
std::string _l = "%lld";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef int _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 7E5+88;
_ a[maxn], c = 3, i = 2, n;

_ binSearch(_ f);
int main(int argc, char * argv[]) {
    
    a[1] = 1;
    for(; c <= 2E9+9E6; ++i, c += binSearch(i)) a[i] = c;
    cin >> n;
    cout << binSearch(n) << endl;
    
    return 0;
}

_ binSearch(_ f) {
    _ l = 1, r = i-1, m, s = -1;
    while(l <= r) {
        m = (l+r)/2;
        if(a[m] >= f) {
            s = m;
            r = m-1;
        } else l = m+1;
    }
    return s;
}
