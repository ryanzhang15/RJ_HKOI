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

map <str, _> x = {{"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}};
_ k[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, d, m, y, o;
str mon, t[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

bool isLeap(_ y);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &d);
    cin >> mon;
    scanf(_lin, &y);
    m = x[mon];
    scanf(_lin, &o);

    for(_ i = 1; i <= o; ++i) {
        ++d;
        if((!isLeap(y) && m == 2 && d > 28) || (isLeap(y) && m == 2 && d > 29) || (m != 2 && d > k[m])) {
            d = 1;
            if(++m == 13) {
                m = 1;
                ++y;
            }
        }
    }

    cout << d <<' '<< t[m] <<' '<< y << endl;
    
    return 0;
}

bool isLeap(_ y) {
    return ((!(y % 4) && y % 100) || !(y % 400));
}
