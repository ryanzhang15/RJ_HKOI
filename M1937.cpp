
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
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define ef else if
std::string _l = _lin;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E7;

bitset<maxn+8> ip;
bitset<maxn+8> is;
_ n, rt[4000], sq[4000], pc, t, s, ap[maxn+8];

void squares();
void sieve();
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    sieve();
    squares();
    for(; n--; ) {
        scanf(_lin, &t);
        if(ip[t]) {
            ++pc;
            ++ap[t];
            if(t*t <= maxn) ++rt[t];
        } ef(is[t]) ++sq[(_)sqrt(t)];
    }
    for(_ i = 1; i <= maxn; ++i) if(ip[i]) s -= (ap[i]*(ap[i]-1))>>1;
    s += ((pc*(pc-1))>>1);
    for(_ i = 1; i*i <= maxn; ++i) if(ip[i]) s += rt[i]*sq[i];
    printf(fs(_l+"\n"), s);
    
    return 0;
}

void sieve() {
    ip.flip();
    ip[0] = ip[1] = false;
    for(_ i = 2; i*i <= maxn; ++i) if(ip[i]) {
        for(_ j = i*i; j <= maxn; j += i) ip[j] = false;
    }
    return;
}

void squares() {
    for(_ i = 1; i*i <= maxn; ++i) is.flip(i*i);
    return;
}
