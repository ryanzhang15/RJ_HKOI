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

constant maxn = 11520+88;

map<str, _> mp = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}, {"Saturday", 6}, {"Sunday", 7}};
char days[10][20] = {"", "Monday\0", "Tuesday\0", "Wednesday\0", "Thursday\0", "Friday\0", "Saturday\0", "Sunday\0"};
str in;
_ hr, mn, f[10][maxn], cnt[10], n, d, ub;

void printDate(_ wd, _ t);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(; n--; ) {
        scanf(_llin, &hr, &mn);
        cin >> in;
        d = mp[in];
        if(in == "Weekdays") for(_ i = 1; i <= 5; ++i) f[i][++cnt[i]] = 60*hr+mn;
        else f[d][++cnt[d]] = 60*hr+mn;
    }
    for(_ i = 1; i <= 7; ++i) sort(f[i]+1, f[i]+1+cnt[i]);
    scanf(_lin, &n);
    for(; n--; ) {
        scanf(_llin, &hr, &mn);
        hr = (60*hr)+mn;
        cin >> in;
        d = mp[in];
        ub = upper_bound(f[d]+1, f[d]+1+cnt[d], hr)-f[d];
        if(ub > cnt[d]) {
            for(_ i = d+1; i <= d+8; ++i) if(cnt[(i-1)%7+1]) {
                printDate(f[(i-1)%7+1][1], (i-1)%7+1);
                break;
            }
        } else printDate(f[d][ub], d);
    }
    
    return 0;
}

void printDate(_ wd, _ t) {
    _ hr = wd/60;
    _ mn = wd-60*hr;
    if(hr < 10) putchar('0');
    printf(fs(_l+" "), hr);
    if(mn < 10) putchar('0');
    printf(fs(_l+" "), mn);
    for(_ i = 0; days[t][i]; ++i) putchar(days[t][i]);
    putchar(10);
    return;
}
