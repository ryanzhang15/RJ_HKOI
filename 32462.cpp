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

constant maxn = 1E5+8;

struct node {
    _ h, w;
};

_ n, a[maxn], ans;
stack<node> s;

int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) scanf(_lin, &a[i]);
    for(_ i = 1; i <= n+1; ++i) { //n+1 for the last zero;
        _ w = 1;
        while(!s.empty() && s.top().h >= a[i]) {
            w += s.top().w - 1;
            ans = max(ans, s.top().h*w);
            w++;
            s.pop();
        }
        s.push({a[i], w});
    }
    
    printf(fs(_l+"\n"), ans);
    
    return 0;
}
