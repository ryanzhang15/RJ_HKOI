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

#define fs(str) (str).c_str()
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%llf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E5+8;
_ n, m, s[maxn], a;

bool check(_ n);
int main(int argc, char * argv[]) {
    
    //It looks to me... like this \
       problem is a binary search???
    
    scanf(fs(_l+_l), &n, &m); //shady shady stuff
    for(_ i = 0; i < n; i++) scanf(fs(_l), &s[i]);
    sort(s, s+n);
    
    _ l = 0, r = 1E9, m;
    while(l <= r) {
        m = (l+r)/2;
        if(check(m)) {
            a = m;
            l = m+1;
        } else r = m-1;
    }
    
    printf(fs(_l+"\n"), a);
    
    return 0;
}

bool check(_ p) {
    if(p > s[n-1] - s[0]) return false;
    _ pv = s[0], t = 0;
    for(_ i = 1; i < n; i++) {
        if(s[i]-pv >= p) {
            pv = s[i];
            t++;
        }
    }
    return t >= m-1;
}
