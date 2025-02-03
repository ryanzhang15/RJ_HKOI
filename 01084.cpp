#include <cstdio>
#include <iostream>
#include <cstdlib>
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
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

_ n, c, t;

bool know(_ x, _ y);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    c = 1;
    for(_ i = 2; i <= n; ++i) if(know(c, i)) c = i;
    printf(fs("A "+_l+"\n"), c);
    
    return 0;
}

bool know(_ x, _ y) {
    _ a;
    printf(fs("Q "+_l+" "+_l+"\n"), x, y);
    fflush(stdout);
    scanf(_lin, &a);
    return !!a;
}
