#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

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

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 3E4+88;

_ n, ans, sf[maxn], ca;
bool vis[maxn];

_ gcd(_ a, _ b);
void walk(_ p, _ f);
int main(int argc, char * argv[]) {
    
    //this problem.. its very nice
    //too bad its easy ;)
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(_ i = 1; i <= n; i++) cin >> sf[i];
    for(_ i = 1; i <= n; i++) {
        ca = 1;
        if(vis[i]) continue;
        vis[i] = true;
        walk(sf[i], i);
        if(!ans) ans = ca;
        else ans = (ans/gcd(ans, ca)) * ca;
    }
    
    cout << ans << endl;
    
    return 0;
}

void walk(_ p, _ f) {
    if(p == f) return;
    ca++;
    vis[p] = true;
    walk(sf[p], f);
    return;
}

_ gcd(_ a, _ b) {
    if(!a) return b;
    return gcd(b%a, a);
}
