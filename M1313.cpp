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

_ k, c;
bool f;
stack<_> s;
deque<_> d;

int main(int argc, char * argv []) {
    
    scanf(_lin, &k);
    for(; scanf(_lin, &c) && c; ) {
        if(c > 0) {
            if(d.size() < k) {
                if(f) d.push_back(c);
                else d.push_front(c);
            } else {
                if(f) {
                    s.push(d.front());
                    d.pop_front();
                    d.push_back(c);
                } else {
                    s.push(d.back());
                    d.pop_back();
                    d.push_front(c);
                }
            }
        } else if(c == -2) f = !f;
        else {
            if(f) {
                printf(fs(_l+"\n"), d.back());
                d.pop_back();
                if(!s.empty()) {
                    d.push_front(s.top());
                    s.pop();
                }
            } else {
                printf(fs(_l+"\n"), d.front());
                d.pop_front();
                if(!s.empty()) {
                    d.push_back(s.top());
                    s.pop();
                }
            }
        }
    }
    
    return 0;
}

/*
2
111
222
333
444
-2
-1
-1
-1
-1
 */
