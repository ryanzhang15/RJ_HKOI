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

str t, f;
_ n, m, c;
char lc;

void l(_ s, _ p);
int main(int argc, char * argv[]) {
    
    cin >> t;
    scanf(_lin, &m);
    n = t.length();
    sort(t.begin(), t.end());
    l(0, 0);
    
    return 0;
}

void l(_ s, _ p) {
    if(s == m) {
        cout << f << endl;
        return;
    }
    for(_ i = p; i < n; i++) {
        if(t[i] == lc) continue;
        f.push_back(t[i]);
        l(s+1, i+1);
        f.pop_back();
        lc = t[i];
    }
}
