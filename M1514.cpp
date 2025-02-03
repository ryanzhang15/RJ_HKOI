
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
#define _l "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define ef else if
std::string l_ = _l;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

_ m, k, x, y;
deque<_> t, b;

int main(int argc, char * argv[]) {
    
    scanf(_ll, &m, &k);
    for(; m--; ) {
        scanf(_l, &x);
        if(x == 1) {
            scanf(_l, &y);
            if(t.size() < k) t.push_front(y);
            else {
                t.push_front(y);
                b.push_front(t.back());
                t.pop_back();
            }
        } ef(x == 2) {
            t.push_front(t.back());
            t.pop_back();
        } else {
            scanf(_l, &y);
            if(y <= k) printf(fs(l_+"\n"), t[y-1]);
            else printf(fs(l_+"\n"), b[y-k-1]);
        }
    }
    
    return 0;
}
