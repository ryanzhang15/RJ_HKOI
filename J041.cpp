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


_ gcd(_ a, _ b), n, a[25], c, d, ans; // you can prototype functions AND declare variables on the same line?
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 0; i < n; i++) {
        scanf(fs(_l+_l), &c, &d);
        a[i] = c+d;
    }
    ans = a[0];
    for(_ i = 1; i < n; i++) ans = (ans*a[i])/gcd(ans, a[i]);
    
    printf(fs(_l+"\n"), ans);
    
    return 0;
}

_ gcd(_ a, _ b) {
    if(!b) return a;
    return gcd(b, a%b);
}
