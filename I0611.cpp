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

_ n, m, s[200], r[200], rc, tc, a;
char c, t;
queue<char> stream;

int main(int argc, char * argv[]) {
    
    memset(s, 0x80, sizeof(s));
    
    scanf(_llin, &n, &m); _ N = n;
    getchar();
    for(; N--; ) {
        c = getchar();
        if(s[c] == s[199]) s[c] = 0;
        if(!s[c]++) ++rc;
    }
    getchar();
    for(; m--; ) {
        //pop character
        if(stream.size() == n) {
            t = stream.front();
            stream.pop();
            if(r[t]-- == s[t]) --tc;
            if(r[t] == s[t]) ++tc;
        }
        c = getchar();
        if(r[c]++ == s[c]) --tc;
        if(r[c] == s[c]) ++tc;
        if(tc == rc) ++a;
        stream.push(c);
    }
    getchar();
    printf(fs(_l+"\n"), a);
    
    return 0;
}
