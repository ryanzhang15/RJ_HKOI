
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
//#include <unordered_map>
#include <queue>
#include <list>
#include <set>
//#include <unordered_set>
#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define ef else if
std::string _l = _lin;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E2+8;
_ n;
str dp[maxn][maxn];

str times(str a, str b);
str add(str a, str b);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) cin >> dp[i][j];
    for(_ k = 1; k <= n; ++k) for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) if(i != j) dp[i][j] = add(dp[i][j], times(dp[i][k], dp[k][j]));
    for(_ i = 1; i <= n; ++i) {
        for(_ j = 1; j <= n; ++j) cout << dp[i][j] << ' ';
        putchar(10);
    }
    
    return 0;
}

str add(str a, str b) {
    if(a.length() > b.length()) swap(a, b);
    _ al = a.length(), bl = b.length();
    for(_ i = 0; i < ceil(al / 2); i++) swap(a[i], a[al - i - 1]);
    for(_ i = 0; i < ceil(bl / 2); i++) swap(b[i], b[bl - i - 1]);
    str res = ""; _0 cr = 0;
    for(_ i = 0; i < al; i++) {
        _0 cur = a[i]-'0' + b[i]-'0' + cr;
        res.push_back(cur % 10 + '0');
        cr = cur / 10;
    }
    for(_ i = al; i < bl; i++) {
        _0 cur = b[i]-'0' + cr;
        res.push_back(cur % 10 + '0');
        cr = cur / 10;
    }
    if(cr) res.push_back(cr + '0');
    _ rl = res.length();
    for(_ i = 0; i < ceil(rl / 2); i++) swap(res[i], res[rl - i - 1]);
    return res;
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
