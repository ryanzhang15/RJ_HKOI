
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
//#include <unordered_set>
#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define _lllll "%lld%lld%lld%lld%lld"
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

str a;
char c;
_ fq[200], cfq[200], b;
bool flag;

char findDigit();
int main(int argc, char * argv[]) {
    
    cin >> a;
    getchar();
    for(; isdigit(c = getchar()); ++b) ++fq[c];
    b = a.size()-b;
    for(; b--; ) putchar(findDigit());
    putchar(10);
    
    return 0;
}

char findDigit() {
    for(char i = '9'; i >= '1'; --i) {
        memset(cfq, 0, sizeof cfq);
        _ j = 0;
        for(; j < a.size(); ++j) if(a[j] == i) break;
        if(j == a.size() || fq[i] == count(a.begin(), a.end(), i)) continue;
        for(_ k = 0; k < j; ++k) ++cfq[a[k]];
        flag = false;
        for(char k = '1'; k <= '9' && !flag; ++k) if(cfq[k] > fq[k]) flag = true;
        if(flag) continue;
        for(char k = '1'; k <= '9'; ++k) fq[k] -= cfq[k];
        char sv = a[j];
        a = a.substr(j+1);
        return sv;
    }
    return 0;
}
