#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 2E5+8;
constant maxm = 2E3+8;

_ n, m, s[maxm][3], o, c;
char a[maxn], b[maxm];

int main() {
    
    scanf("%lld %s%lld %s", &n, a, &m, b);
    for(_ i = 0; i <= n-1; ++i) {
        s[i%m][0] += a[i] == 'B';
        s[i%m][1] += a[i] == 'G';
        s[i%m][2] += a[i] == 'W';
    }
    o = 1E18;
    for(_ i = 0; i <= m-1; ++i) {
        c = 0;
        for(_ j = 0; j <= m-1; ++j) c += s[(i+j)%m][0] * (b[j] != 'B') + s[(i+j)%m][1] * (b[j] != 'G') + s[(i+j)%m][2] * (b[j] != 'W');
        o = min(o, c);
    }
    printf("%lld\n", o);
    
    return 0;
}
