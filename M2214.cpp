
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>

#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

_ n, op, x, c;
multiset<_> st;

int main() {

    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) {
        scanf("%lld", &op);
        if(op != 2) scanf("%lld", &x);
        if(op == 1) st.insert(x-c);
        ef(op == 2) {
            if(st.empty()) puts("-1");
            else {
                printf("%lld\n", *st.rbegin()+c);
                st.erase(st.find(*st.rbegin()));
            }
        } else {
            c += x;
            for(; !st.empty() && *st.begin()+c < 0; ) st.erase(st.begin());
        }
    }
    _ s = 0;
    for(_ i : st) s += i+c;
    printf("%lld\n", s);
    
    return 0;
}

