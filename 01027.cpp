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

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

_ n;
str ans = "1";

str times(str a, str b);
int main(int argc, char * argv[]) {
    
    cin >> n;
    for(_ i = n; i > 1; i--) {
        ans = times(ans, to_string(i));
    }
    
    cout << ans << endl;
    
    return 0;
}

str times(str a, str b) {
    if(a == "0" || b == "0") return "0";
    if(a.length() < b.length()) swap(a, b);
    _ al = a.length(), bl = b.length();
    vector<_0> av, bv, c (al + bl, 0);
    for(_ i = al - 1; i >= 0; i--) {
        av.push_back(a[i] - '0');
    }
    for(_ i = bl - 1; i >= 0; i--) {
        bv.push_back(b[i] - '0');
    }
    for(_ i = 0; i < al; i++) {
        for(_ j = 0; j < bl; j++) {
            c[i+j] += av[i] * bv[j];
        }
    }
    for(_ i = 0; i < al + bl; i++) {
        if(c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    bool flag = false; str res = "";
    for(_ i = al + bl - 1; i >= 0; i--) {
        if(c[i]) flag = true;
        if(flag) res.push_back((char)(c[i] + '0'));
    }
    return res;
}
