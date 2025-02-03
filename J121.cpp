
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
std::string _l = l;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

char s[108][108], a[108], b[108];
_ ca, cb, ln;

int main(int argc, char * argv[]) {
    
    for(_ i = 10; i <= 99; ++i) {
        s[i-10][0] = i/10 + '0';
        s[i-10][1] = i%10 + '0';
        for(_ j = 2; j <= 99; ++j) s[i-10][j] = ((s[i-10][j-2]-'0') * (s[i-10][j-1]-'0'))%10+'0';
    }
    scanf("%s %s", a, b);
    ln = strlen(a);
    if(ln == 1) ca = (a[0]-'0')-1;
    else if(ln == 2) ca = (a[0]-'0')*10+a[1]-'0'-1;
    else {
        _ i;
        for(i = 0; i <= 89; ++i) if(strncmp(s[i], a, ln) >= 0) break;
        ca = 90*(ln-2)+i+9;
    }
    ln = strlen(b);
    if(ln == 1) cb = b[0]-'0';
    else if(ln == 2) cb = (b[0]-'0')*10+b[1]-'0';
    else {
        _ i;
        for(i = 0; i <= 89; ++i) if(strncmp(s[i], b, ln) > 0) break;
        cb = 90 * (ln-2)+i+9;
    }
    printf(fs(_l+"\n"), cb-ca);
    
    return 0;
}
