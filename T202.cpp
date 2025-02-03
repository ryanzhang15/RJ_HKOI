
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
std::string _l = l;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef __int128 _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 3E5+88;
struct query {
    _ a, b;
} q[maxn];
str a, b;
_ n, x, y, t1, t2, lf[500], f, al, cnt, tc, lt, rt, md, rv;
pair<_, _> s[maxn];

_ binSearch();
int main(int argc, char * argv[]) {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(EXIT_SUCCESS);
    
    cin >> a >> b;
    for(char i : a) ++lf[i];
    y = al = a.length();
    a.clear();
    a = str(b.length(), '_');
    for(_ i = b.length()-1; ~i; --i) if(lf[b[i]]) {
        --lf[b[i]];
        --y;
        a[i] = '~';
        ++f;
    }
    tc = f;
    for(_ i = a.length()-1; ~i; --i) {
        if(a[i] == '~') {
            --f;
            continue;
        }
        x += f;
    }
    s[++cnt] = {x, y};
    for(_ i = 0; i < a.length(); ++i) {
        if(a[i] == '_') continue;
        ++y;
        --tc;
        x -= a.length()-i-1-tc;
        s[++cnt] = {x, y};
    }
    cin >> n;
    for(_ i = 1; i <= n; ++i) {
        cin >> t1 >> t2;
        cout << binSearch() << endl;
    }
    
    return 0;
}

_ binSearch() {
    rv = 0;
    lt = 1;
    rt = cnt-1;
    for(; lt <= rt; ) {
        md = (lt+rt)>>1;
        if(s[md].first*t1+s[md].second*t2 > s[md+1].first*t1+s[md+1].second*t2) {
            rv = md;
            lt = md+1;
        } else rt = md-1;
    }
    return s[rv+1].first*t1+s[rv+1].second*t2;
}
