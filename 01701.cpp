
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

list<_> q;
unordered_map<_, list<_>::iterator> m;
unordered_map<_, _> k;
_ n, o, a, b;
char c;

int main(int argc, char * argv[]) {
    
    scanf(_ll, &n, &o);
    for(; o--; ) {
        getchar();
        c = getchar();
        getchar();
        getchar();
        if(c == 'S') {
            scanf(_ll, &a, &b);
            if(!m.count(a) && q.size() == n) {
                m.erase(q.back());
                k.erase(q.back());
                q.pop_back();
            } ef(m.count(a)) {
                q.erase(m[a]);
                k.erase(*m[a]);
            }
            q.push_front(a);
            m[a] = q.begin();
            k[a] = b;
        } else {
            scanf(_lin, &a);
            if(!k.count(a)) puts("-1");
            else {
                printf(fs(_l+"\n"), k[a]);
                q.erase(m[a]);
                q.push_front(a);
                m[a] = q.begin();
            }
        }
    }
    
    return 0;
}


