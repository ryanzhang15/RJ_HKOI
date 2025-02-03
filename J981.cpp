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

_ a, b, c, d, e, f;
_D sa, sb, ia, ib;
_ x, y;

void no(), many(), out();
int main(int argc, char * argv[]) {
    
    scanf(fs(_l+_l+_l+_l+_l+_l), &a, &b, &c, &d, &e, &f);
    
    if((!a && !b && c) || (!d && !e && f)) no();
    if((!a && !b && !c) || (!d && !e && !f)) many();

    if(!a && !e) {
        y = c/b;
        x = f/d;
        out();
    }
    if(!b && !d) {
        x = c/a;
        y = f/e;
        out();
    }
    if(!b && !e) {
        if(c/a == f/d) many();
        else no();
    } else if(!b) {
        x = c/a;
        y = (f-d*x)/e;
        out();
    } else if(!e) {
        x = f/d;
        y = (c-a*x)/b;
        out();
    }
    sa = -((_D)a/(_D)b);
    ia = (_D)c/(_D)b;
    sb = -((_D)d/(_D)e);
    ib = (_D)f/(_D)e;

    if(sa == sb) {
        if(ia == ib) many();
        if(ia != ib) no();
    }

    y = (c*d-f*a)/(b*d-a*e);
    x = (c-(b*y))/a;
    out();
    
    return 0;
}

void no() {
    printf("no solution\n");
    exit(0);
    //5, 7, 10, 11, 13, 14
}

void many() {
    printf("many solutions\n");
    exit(0);
    //6, 9, 15
}

void out() {
    printf(fs(_l+" "+_l+"\n"), x, y);
    exit(0);
}
