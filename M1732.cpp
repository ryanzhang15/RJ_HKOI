
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
#define l "%lld"
#define ll "%lld%lld"
#define lll "%lld%lld%lld"
#define llll "%lld%lld%lld%lld"
#define ef else if
std::string _l = l;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E3+88;
_ n, m[maxn][2], x, y, s;
char d;

int main(int argc, char * argv[]) {
    
    scanf(l, &n);
    for(_ i = 2; i <= n+1; ++i) {
        d = getchar();
        if(d == 'N') ++y;
        ef(d == 'E') ++x;
        ef(d == 'S') --y;
        ef(d == 'W') --x;
        m[i][0] = x;
        m[i][1] = y;
    }
    
    for(_ i = 1; i <= n; ++i) s += m[i][0]*m[i+1][1];
    for(_ i = 1; i <= n; ++i) s -= m[i][1]*m[i+1][0];
    puts(s < 0 ? "clockwise" : "anticlockwise");
     
    return 0;
}
