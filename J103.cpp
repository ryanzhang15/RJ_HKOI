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

_ a, b, c, d, y, v, r[4];

int main(int argc, char * argv[]) {
    
    scanf(_llllin, &a, &b, &c, &d);
    if(!a && !b && !c && !d) {
        y = 2010;
        v = 0;
    } else if(a && !b && !c && !d) {
        y = 2011;
        v = a;
    } else if(!a && b && !c && !d) {
        y = 2011;
        v = b;
    } else if(!a && !b && c && !d) {
        y = 2010;
        v = c;
    } else if(!a && !b && !c && d) {
        y = 2010;
        v = d;
    } else if(a && b && !c && !d) {
        y = 2011;
        v = a+b;
    } else if(!a && b && c && !d) {
        y = 2014;
        v = b+c;
    } else if(!a && !b && c && d) {
        y = 2010;
        v = c+d;
    } else if(a && !b && c && !d) {
        y = 2013;
        v = a+c;
    } else if(!a && b && !c && d) {
        if(b > d) {
            v = b;
            y = 2011;
        } else {
            v = d;
            y = 2010;
        }
    } else if(a && !b && !c && d) {
        y = 2015;
        v = a+d;
    } else if(!a && b && c && d) {
        if(b > d) {
            v = b+c;
            y = 2014;
        } else {
            v = c+d;
            y = 2010;
        }
    } else if(a && !b && c && d) {
        y = 2021;
        v = a+c+d;
    } else if(a && b && !c && d) {
        if(b > d) {
            v = a+b;
            y = 2011;
        } else {
            v = a+d;
            y = 2015;
        }
    } else if(a && b && c && !d) {
        y = 2017;
        v = a+b+c;
    } else if(a && b && c && d) {
        if(b > d) {
            v = a+b+c;
            y = 2017;
        } else {
            v = a+c+d;
            y = 2021;
        }
    }
    
    printf(fs(_l+" "+_l+"\n"), y, v);
    
    return 0;
}

