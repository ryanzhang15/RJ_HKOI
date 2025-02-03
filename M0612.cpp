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
#include <queue>
#include <list>
#include <set>

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

stack<bool> s;
str curtag;
char c;
bool intag;

int main(int argc, char * argv []) {
    
    while((c = getchar()) != EOF) {
        if(c == '[') intag = true;
        if(!intag && ((!s.empty() && s.top()) || s.empty())) putchar(c);
        else if(intag) {
            curtag += c;
            if(c == ']') {
                if(curtag[1] == '/') s.pop();
                else s.push(curtag != "[invisible]");
                curtag.clear();
                intag = false;
            }
        }
    }
    
    return 0;
}

