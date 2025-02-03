
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
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <random>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define _lllll "%lld%lld%lld%lld%lld"
#define ef else if
const std::string _l = _lin;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E4+8;
_ n, m, p, r, v[maxn];
str o;

int main(int argc, char ** argv) {
    
    scanf("%lld %lld", &n, &m);
    if(!(n%m)) printf("%lld\n", n/m);
    else {
        printf("%lld", n/m);
        putchar('.');
        r = n%m;
        for(_ i = 1, t; ; ++i) {
            t = (r*10)/m+'0';
            if(!r) {
                cout << o << endl;
                exit(0);
            } ef(v[r]) {
                o.insert(v[r]-1, "[");
                o.push_back(']');
                cout << o << endl;
                exit(0);
            }
            o.push_back(t);
            v[r] = i;
            r = (r*10)%m;
        }
    }
    
    return 0;
}

/*
 n == 1979
 m == 5000
 */
