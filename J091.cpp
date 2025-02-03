#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

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

struct t {
    _ s, e;
    bool operator < (const t &b) const {
        return s > b.s;
    }
} cur;

priority_queue<t> q;
deque<t> s;

_ n;

int main(int argc, char * argv[]) {
    
    for(_ i = 1; i <= 2; ++i) {
        scanf(_lin, &n);
        for(; n--; ) {
            scanf(_llin, &cur.s, &cur.e);
            q.push(cur);
        }
    }
    
    s.push_back(q.top());
    q.pop();
    for(; !q.empty(); q.pop()) {
        if(s.back().e+1 >= q.top().s) {
            cur = s.back();
            s.pop_back();
            cur.e = max(cur.e, q.top().e);
            s.push_back(cur);
        }
        else s.push_back(q.top());
    }
    
    printf(fs(_l+"\n"), (_)s.size());
    for(; !s.empty(); s.pop_front()) printf(fs(_l+" "+_l+"\n"), s.front().s, s.front().e);
    
    return 0;
}
