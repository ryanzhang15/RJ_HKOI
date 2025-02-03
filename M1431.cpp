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
//#include <unordered_map>
#include <queue>
#include <list>
#include <set>
//#include <unordered_set>

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

_ n, m, i, c;
pair<_, _> find(_ l, _ r), t;
bool isLarger(_ a, _ b);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    t = find(1, n);
    printf(fs("A "+_l+" "+_l+"\n"), t.first, t.second);
    fflush(stdout);
    
    return 0;
}

pair<_, _> find(_ l, _ r) {
    pair<_, _> rv;
    if(!(n & 1)) {
        if(isLarger(1, 2)) rv = make_pair(1, 2);
        else rv = make_pair(2, 1);
        i = 3;
    } else {
        rv = make_pair(1, 1);
        i = 2;
    }
    while(i < n) {
        if(isLarger(i, i+1)) {
            if(isLarger(i, rv.first)) rv.first = i;
            if(!isLarger(i+1, rv.second)) rv.second = i+1;
        } else {
            if(isLarger(i+1, rv.first)) rv.first = i+1;
            if(!isLarger(i, rv.second)) rv.second = i;
        }
        i += 2;
    }
    return rv;
}

bool isLarger(_ a, _ b) {
    printf(fs("Q "+_l+" "+_l+"\n"), a, b);
    fflush(stdout);
    getchar();
    m = getchar();
    return m == '1';
}
