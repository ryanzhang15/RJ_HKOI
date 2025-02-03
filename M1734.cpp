
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
#include <numeric>

#define fs(str) (str).c_str()
#define _l "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define ef else if
std::string l_ = _l;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

_ n, m, c[300], s;

_ choose(_ a, _ b);
int main(int argc, char * argv[]) {
    
    scanf(_ll, &n, &m);
    getchar();
    for(; n--; ) ++c[getchar()];
    for(_ i = 1; i <= c['T']; ++i) for(_ j = 1; j <= c['E']; ++j) for(_ k = 1; k <= c['M']; ++k) for(_ l = 1; l <= c['H']; ++l) if(i+j+k+l == m) s += choose(c['T'], i)*choose(c['E'], j)*choose(c['M'], k)*choose(c['H'], l);
    printf(fs(l_+"\n"), s);
    
    return 0;
}

_ choose(_ a, _ b) {
    _ rv = 1;
    for(_ i = a; i >= a-b+1; --i) rv *= i;
    for(_ i = 1; i <= b; ++i) rv /= i;
    return rv;
}
