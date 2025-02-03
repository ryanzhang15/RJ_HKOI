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

str a, b, c;
_ ca, cb;

int main(int argc, char * argv[]) {
    
    cin >> a >> b >> c;
    for(_ i = 0; i < 6; i++) {
        ca += abs(a[i]-b[i]);
        cb += abs(a[i]-c[i]);
    }
    
    if(ca == cb) cout << b <<' '<< c << endl;
    else if(ca < cb) cout << b << endl;
    else cout << c << endl;
    
    return 0;
}
