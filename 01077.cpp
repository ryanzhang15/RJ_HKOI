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
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E4;
set<_> s[maxn], c[maxn];
_ n, m, k;
str cmd;

int main(int argc, char * argv[]) {
    
    scanf(fs(_l+_l+_l), &n, &m, &k);
    for(; k--; ) {
        cin >> cmd;
        if(cmd == "ADD") {
            _ a, b; scanf(fs(_l+_l), &a, &b);
            s[a].insert(b);
            c[b].insert(a);
        }
        else if(cmd == "DROP") {
            _ a, b; scanf(fs(_l+_l), &a, &b);
            s[a].erase(b);
            c[b].erase(a);
        }
        else if(cmd == "PRINTS") {
            _ a; scanf(_lin, &a);
            if(s[a].empty()) printf("NIL\n");
            else {
                for(_ i : s[a]) printf(fs(_l+" "), i);
                printf("\n");
            }
        }
        else if(cmd == "PRINTC") {
            _ a; scanf(_lin, &a);
            if(c[a].empty()) printf("NIL\n");
            else {
                for(_ i : c[a]) printf(fs(_l+" "), i);
                printf("\n");
            }
        }
    }
    
    return 0;
}
