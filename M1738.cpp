
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
#define elif else if
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

constant maxn = 10;

bitset<10> v;
_ a[maxn], s[maxn];
char op[maxn];

void dfs(_ pos);
bool eval(_ a, _ b, _ c, char o);
int main(int argc, char * argv[]) {
    
    for(_ i = 1; i <= 9; ++i) scanf(_lin, &a[i]);
    getchar();
    for(_ i = 1; i <= 6; ++i) op[i] = getchar();
    dfs(1);
    puts("No solution");
    
    return 0;
}

bool eval(_ a, _ b, _ c, char o) {
    a = s[a];
    b = s[b];
    c = s[c];
    o = op[o];
    if(o == '+') return a + b == c;
    elif(o == '-') return a - b == c;
    elif(o == '*') return a * b == c;
    else return !(a % b) && a / b == c;
}

void dfs(_ pos) {
    if(pos == 10) {
        if(eval(1, 2, 3, 1) && eval(4, 5, 6, 2) && eval(7, 8, 9, 3) && eval(1, 4, 7, 4) && eval(2, 5, 8, 5) && eval(3, 6, 9, 6)) {
            for(_ i = 1; i <= 9; ++i) {
                printf(fs(_l+" "), s[i]);
                if(!(i % 3)) putchar(10);
            }
            exit(0);
        }
        return;
    }
    for(_ i = 1; i <= 9; ++i) if(!v[i]) {
        v[i].flip();
        s[pos] = a[i];
        dfs(pos + 1);
        v[i].flip();
    }
}
