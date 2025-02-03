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

str in, out, cur;
_ n, m, col = 1E10;
bool fl;

int main(int argc, char * argv[]) {
    
    scanf(_llin, &n, &m);
    getchar();
    for(_ i = 1; i <= n; i++) {
        getline(cin, in);
        in += '\n';
        for(char i : in) {
            if((i == ' ' || i == '\n') and !cur.empty()) {
                if(col + cur.length() + 1 <= m) {
                    col += cur.length() + 1;
                    out += " " + cur;
                    cur.clear();
                } else {
                    col = cur.length();
                    if(fl) out.push_back('\n');
                    fl = true;
                    out += cur;
                    cur.clear();
                }
            } else cur.push_back(i);
        }
    }
    
    if(!cur.empty()) {
        if(col + cur.length() + 1 <= m) {
            col += cur.length() + 1;
            out += " " + cur;
            cur.clear();
        } else {
            col = cur.length();
            out += "\n" + cur;
            cur.clear();
        }
    }
    
    puts(out.c_str());
    
    return 0;
}
