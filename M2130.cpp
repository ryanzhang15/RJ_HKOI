#include <bits/stdc++.h>
#define ef else if
#define i(x) x::iterator
#define mp(x, y) make_pair(x, y)
#define v(x) vector<x > 

using namespace std;

typedef long long _;
typedef string str;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

typedef long long ll;

constant maxn = 20+8;

_ p[maxn] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53}, n;
v_ a;

int main() {

//#define file_IO
#ifdef file_IO
    freopen("data.in", "r", stdin);
#endif

    scanf("%lld", &n);
    a.push_back(1);
    for(_ i = 2; i <= n; ++i) {
        v_ b = a;
        a.push_back(i);
        for(_ i : b) a.push_back(i);
    }
    printf("%lld\n", a.size());
    for(_ i : a) printf("%lld ", p[i]);
    putchar(10);
    
    
    return 0;
}
