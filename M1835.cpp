
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

_ hr, mn, sc;
_D h, m, s;

int main(int argc, char * argv[]) {
    
    scanf("%2lld:%2lld:%2lld", &hr, &mn, &sc);
    if(hr >= 12) hr -= 12;
    h = hr*30+(_D)mn*0.5+(_D)sc*0.5/60.0;
    m = mn*6+sc*0.1;
    s = abs(h-m);
    printf("%Lf\n", min(s, 360-s));
    
    return 0;
}
