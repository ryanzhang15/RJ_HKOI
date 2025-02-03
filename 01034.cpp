
#include <cstdio>
#include <iostream>
#include <cstdlib>
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

_ n, a, b, p[330];
char t;
stack<char> o;
stack<_> s;

_ eval(char op);
int main(int argc, char * argv[]) {
    
    p['+'] = 1;
    p['*'] = 2;
    p['^'] = 3;
    
    scanf(_lin, &n);
    getchar();
    for(; n--; ) {
        t = getchar();
        for(; t != '\n'; t = getchar()) {
            if(isdigit(t)) s.push(t-'0');
            else {
                if(t == '(') o.push(t);
                else if(t == ')') {
                    for(; o.top() != '('; o.pop()) s.push(eval(o.top()));
                    o.pop();
                } else {
                    for(; !o.empty() && p[o.top()] > p[t]; o.pop()) s.push(eval(o.top()));
                    o.push(t);
                }
            }
        }
        for(; !o.empty(); o.pop())
            s.push(eval(o.top()));
        printf(fs(_l+"\n"), s.top());
        s.pop();
    }
    
    return 0;
}

_ eval(char op) {
    a = s.top();
    s.pop();
    b = s.top();
    s.pop();
    if(op == '+') return a+b;
    else if(op == '*') return a*b;
    else return pow(b, a);
}
