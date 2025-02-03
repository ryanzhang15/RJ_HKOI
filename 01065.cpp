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

str a, b, c;
_ rl;
bool neg;

str sub(str a, str b);
int main(int argc, char * argv[]) {
    
    /*This problem's just a pain
     in the ass
     */
    
    cin >> a >> b;
    c = sub(a, b);
    rl = max(a.length(), b.length());
    for(_ i = 0; i < rl+1-a.length(); ++i) putchar(32);
    cout << a;
    putchar(10);
    putchar(45);
    for(_ i = 0; i < rl-b.length(); ++i) putchar(32);
    cout << b;
    putchar(10);
    for(_ i = 0; i < rl+1; ++i) putchar(45);
    putchar(10);
    if(c[0] == 45) {
        c.erase(0, 1);
        putchar(45);
        neg = true;
    }
    for(_ i = 0; i < rl+1-neg-c.length(); ++i) putchar(32);
    cout << c;
    putchar(10);
    
    return 0;
}

str sub(str a, str b) {
    if(a == b) {
        return "0";
    }
    bool negative = false;
    if(a.length() < b.length()) {
        negative = true;
        swap(a, b);
    } else if(a.length() == b.length()) {
        if(a < b) {
            negative = true;
            swap(a, b);
        }
    }
    vector<_0> av, bv; _ al = a.length(), bl = b.length();
    for(_ i = 0; i < al; i++) {
        av.push_back(a[al - i - 1] - '0');
    }
    for(_ i = 0; i < bl; i++) {
        bv.push_back(b[bl - i - 1] - '0');
    }
    for(_ i = 0; i < bl; i++) {
        av[i] -= bv[i];
        if(av[i] < 0) {
            av[i] += 10;
            av[i + 1]--;
        }
    }
    for(_ i = bl; i < al; i++) {
        if(av[i] < 0) {
            av[i] += 10;
            av[i+1]--;
        } else {
            break;
        }
    }
    bool flag = false; str res = (negative) ? "-" : "";
    for(_ i = al - 1; i >= 0; i--) {
        if(av[i]) flag = true;
        if(flag) res.push_back((char)(av[i] + '0'));
    }
    return res;
}
