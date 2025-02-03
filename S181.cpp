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
#define _lin "%lli"
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
#define _llllin "%lli%lli%lli%lli"
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E5+8;
_ n, a, b, c, o[maxn], m;

int main(int argc, char * argv[]) {
    
    scanf(_lllin, &n, &a, &b);
    c = min(a, b);
    for(_ i = 0; i < n; ++i) {
        scanf(_lin, &a);
        if(a & 1) o[m++] = i;
    }
    
    if(m & 1) {
        puts("-1");
        exit(0);
    }
    
    o[m++] = o[0] + n;
    
    a = b = 0;
    for(_ i = 1; i < m-1; i+=2) a += o[i]-o[i-1];
    for(_ i = 2; i < m; i+=2) b += o[i]-o[i-1];
    
    printf(fs(_l+"\n"), min(a, b)*c);
    
    return 0;
}

