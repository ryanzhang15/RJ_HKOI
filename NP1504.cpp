
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
typedef double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E5+8;

struct ad {
    _ d, t;
} place[maxn];

_ n, pastS[maxn], maxD[maxn], maxRD[maxn];

bool cmp (ad a, ad b);
int main(int argc, char  * argv[]) {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    freopen("salesman.in", "r", stdin);
    freopen("salesman.out", "w", stdout);
    
    cin >> n;
    for(_ i = 0; i < n; i++) cin >> place[i].d;
    for(_ i = 0; i < n; i++) cin >> place[i].t;
    sort(place, place+n, cmp);
    for(_ i = 0; i < n; i++) {
        if(!i) pastS[i] = place[i].t;
        else pastS[i] = pastS[i-1] + place[i].t;
    }
    for(_ i = n-1; i >= 0; i--) maxRD[i] = max(maxRD[i+1], 2*place[i].d + place[i].t);
    for(_ i = 0; i < n; i++) {
        if(!i) maxD[i] = 2*place[i].d;
        else maxD[i] = max(maxD[i-1], 2*place[i].d);
    }
    for(_ i = 0; i < n; i++) {
        if(!i) cout << max(pastS[i] + maxD[i], maxRD[i]) << endl;
        else cout << max(pastS[i] + maxD[i], pastS[i-1] + maxRD[i]) << endl;
    }
    
    return 0;
}

bool cmp (ad a, ad b) {
    return a.t > b.t;
}
