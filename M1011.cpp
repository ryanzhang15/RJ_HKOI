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
std::string _f = "%llf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

set<_> n;
_ digits[10];
str c;

void digitCount(_ n);
bool isNumber(str s);
int main(int argc, char * argv[]) {
    
    for(; cin >> c; ) if(isNumber(c)) n.insert(stoll(c));
    
    
    for(auto i : n) digitCount(i);
    for(_ i = 0; i < 10; i++) if(digits[i]) printf(fs(_l+" "+_l+"\n"), i, digits[i]);
    
    return 0;
}

bool isNumber(str s) {
    for(char i : s) if(!(i >= '0' and i <= '9')) return false;
    return true;
}

void digitCount(_ n) {
    for(; n>=10; n/=10); //apparently for loops r a bit faster? \
        dk might be sudoscience
    digits[n]++;
    
    return;
}
