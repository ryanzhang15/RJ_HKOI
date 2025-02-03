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

unordered_set<str> s;
str c, t;

_ n, l, w;
bool flag;
char sv;

int main(int argc, char * argv[]) {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(EXIT_SUCCESS);
    
    cin >> n >> l;
    for(_ i = 1; i <= n; ++i) {
        cin >> c;
        s.insert(c);
    }
    cin >> w;
    for(_ i = 1; i <= w; ++i) {
        flag = false;
        cin >> c;
        for(_ i = 0; i < l; ++i) {
            sv = c[i];
            for(char j = 1; j <= 26; ++j) {
                if(j+'a'-1 == sv) continue;
                c[i] = j+'a'-1;
                if(s.count(c)) {
                    cout << c << endl;
                    flag = true;
                    break;
                }
            }
            c[i] = sv;
            if(flag) break;
        }
    }
    
    return 0;
}

