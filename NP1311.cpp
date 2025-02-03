
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

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
typedef double _D;
typedef string str;
typedef const long long maxn;

_ modres(_ k, _ n);

maxn mn = 10e17;

int main(int argc, char * argv[]) {
    
    freopen("circle.in", "r", stdin);
    freopen("circle.out", "a", stdout);
    _ n, m, k, x; cin >> n >> m >> k >> x;
    cout << (x % n + (m % n) * (modres(k, n) % n)) % n << endl;
    
    return 0;
}

_ modres(_ k, _ n) {
    if(!k) return 1;
    _ f = modres(k / 2, n);
    f = (f*f) % n;
    if(k & 1) f = (f * 10) % n;
    return f % n;
}

