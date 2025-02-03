
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
#include <random>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define _lllll "%lld%lld%lld%lld%lld"
#define ef else if
const std::string _l = _lin;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E6+8;
_ nex[maxn], t, k;
str s;

int main(int argc, char ** argv) {
    
    scanf(_lin, &t);
    getchar();
    for(; t--; ) {
        getline(cin, s);
        k = nex[0] = -1;
        for(_ i = 1; i < s.length(); ++i) {
            for(; ~k && s[i] != s[k+1]; ) k = nex[k];
            if(s[i] == s[k+1]) ++k;
            nex[i] = k;
        }
        if(!(s.length()%(s.length()-1-nex[s.length()-1]))) printf(fs(_l+"\n"), ((s.length())/(s.length()-1-nex[s.length()-1])));
        else puts("1");
    }
    
    return 0;
}
