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

_ n, l;
char s[108];
stack<_> value;
stack<char> op;

map<char, _> p = {{'+', 1}, {'*', 69}, {'^', 420}};

int main(int argc, char * argv[]) {
    
    //gonna get some help from my man dijkstra
    scanf(_lin, &n);
    for(; n--; ) {
        scanf(fs(_s), s);
        l = strlen(s);
        _ cv = 0;
        for(_ i = 0; i < l; i++) {
            if(s[i] >= '0' && s[i] <= '9') cv = cv*10+s[i]-'0';
            else {
                value.push(cv);
                cv = 0;
                while(!op.empty() && p[op.top()] > p[s[i]]) {
                    _ a = value.top(); value.pop();
                    _ b = value.top(); value.pop();
                    char o = op.top(); op.pop();
                    if(o == '+') value.push(a+b);
                    if(o == '*') value.push(a*b);
                    else value.push((_)pow(b, a));
                }
                op.push(s[i]);
            }
            if(i == l-1) value.push(cv);
        }
        while(!op.empty()) {
            _ a = value.top(); value.pop();
            _ b = value.top(); value.pop();
            char o = op.top(); op.pop();
            if(o == '+') value.push(a+b);
            else if(o == '*') value.push(a*b);
            else value.push((_)pow(b, a));
        }
        printf(fs(_l+'\n'), value.top());
        value.pop();
        memset(s, 0, sizeof(s));
    }
    
    return 0;
}
