#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef long double _D;
typedef const long long constant;

_ x, y, z;

int main() {
    
    freopen("area.in", "r", stdin);
    freopen("area.out", "w", stdout);
    
    scanf("%lld%lld%lld", &x, &y, &z);
    puts(x*x > y*z ? "Alice" : "Bob");

    return 0;
}
