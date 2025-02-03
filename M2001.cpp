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

map <str, _> x = {{"JAN", 1}, {"FEB", 2}, {"MAR", 3}, {"APR", 4}, {"MAY", 5}, {"JUN", 6}, {"JUL", 7}, {"AUG", 8}, {"SEP", 9}, {"OCT", 10}, {"NOV", 11}, {"DEC", 12}};
_ m[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, d, f;
str mon, t[] = {"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};

int main(int argc, char * argv[]) {
    
    mon+=getchar();
    mon+=getchar();
    mon+=getchar();
    f = x[mon];
    getchar();
    scanf(_lin, &d);
    for(_ i = 1; i <= 14; ++i) {
        ++d;
        if(d > m[f]) {
            ++f;
            if(f == 13) f = 1;
            d = 1;
        }
    }
    
    cout << t[f] << ' ' << d << endl;
    
    return 0;
}
