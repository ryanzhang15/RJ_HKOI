
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

str a[200], c;

int main(int argc, char * argv[]) {
    
    a[1] = "0";
    a[2] = "01";
    for(_ i = 3; i <= 27; ++i) a[i] = a[i-1]+a[i-2];
    for(_ i = 1; i <= 5; ++i) {
        cin >> c;
        if(a[27].find(c) == str::npos) puts("NO");
        else puts("YES");
    }
    
    return 0;
}

