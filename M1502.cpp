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

constant maxn = 50+8;

str p, t;
vector<str> o[maxn], c;
_ n;

int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    getchar();
    for(_ i = 1; i <= n; ++i) {
        getline(cin, p);
        for(char &i : p) i = toupper(i);
        istringstream s(p);
        for(; s >> t; ) o[i].push_back(t);
    }
    for(_ i = 1; i <= n; ++i) {
        getline(cin, p);
        for(char &i : p) i = toupper(i);
        istringstream s(p);
        for(; s >> t; ) c.push_back(t);
        for(_ j = 1; j <= n; ++j) {
            _ u = 0, flag = 0;
            for(str k : c) {
                if(k == o[j][u]) ++u;
                if(u == o[j].size()) {
                    flag = 1;
                    break;
                }
            }
            if(flag) {
                cout << j << endl;
                break;
            }
        }
        c.clear();
    }
    
    return 0;
}
