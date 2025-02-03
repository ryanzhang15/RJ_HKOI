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

constant maxn = 1E6+88;
//constant maxn = 100;
constant mod = 1E9+7;

_ n, d[maxn], num[maxn], r = 1, j;
str c;

int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(; n--; memset(d, 0, sizeof(d))) {
        r = 1;
        cin >> c;
        c = " " + c;
        j = 0;
        num[1] = 1;
        for(_ i = 2; i < c.length(); ++i) {
            while(j && c[j+1] != c[i]) j = d[j];
            if(c[i] == c[j+1]) j++;
            d[i] = j;
            num[i] = num[j] + 1;
        }
        j = 0;
        for(_ i = 2; i < c.length(); ++i) {
            while(j && c[j+1] != c[i]) j = d[j];
            if(c[j+1] == c[i]) j++;
            while(j > i/2) j = d[j];
            r = (r*(num[j]+1))%mod;
        }
        printf(fs(_l+"\n"), r);
    }
    
    return 0;
}


