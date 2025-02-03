

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
#define l "%lld"
#define ll "%lld%lld"
#define lll "%lld%lld%lld"
#define llll "%lld%lld%lld%lld"
#define e else if
//std::string _l = l;

//using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef __int128 _0;
typedef unsigned int u_0;
typedef long double _D;
//typedef string str;
typedef const long long constant;

std::bitset<32> a1, a2;
int n, m, s, x, a;
char c, ch;

inline int read();
int main(int argc, char * argv[]) {
    
    n = read();
    m = read();
    a2.flip();
    for(; n; --n) {
        c = getchar_unlocked();
        x = read();
        if(c == 'A') {
            a1 &= x;
            a2 &= x;
        } e(c == 'X') {
            a1 ^= x;
            a2 ^= x;
        } else {
            a1 |= x;
            a2 |= x;
        }
    }
    for(register _ i = 29; ~i; --i) {
        if(a1[i]) s += 1<<i;
        e(a2[i] && (1<<i)<=m) {
            s += 1<<i;
            m -= 1<<i;
        }
    }
    printf("%d\n", s);
    
    
    return 0;
}

inline int read() {
    a=0;ch=getchar_unlocked();
    while (!(ch >= '0' && ch <= '9')){ch=getchar_unlocked();}
    while (ch >= '0' && ch <= '9'){a=a*10+ch-48;ch=getchar_unlocked();}
    return a;
}
