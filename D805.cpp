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

constant maxn = 1E2+8;

_ n, m, a[maxn];

void merge(_ l1, _ r1, _ l2, _ r2);
int main(int argc, char * argv[]) {
    
    cin >> n >> m;
    for(_ i = 1; i <= n; i++) cin >> a[i];
    while(m --> 0) { //loooong arrow operator (lol)
        _ x, y, z, f; // i actually have no letters left
        cin >> x >> y >> z >> f;
        merge(x, y, z, f);
        for(_ i = x; i <= f; i++) cout << a[i] << ' ';
        cout << endl;
    }
    
    return 0;
}

void merge(_ l1, _ r1, _ l2, _ r2) {
    _ ta[maxn], tb[maxn];
    for(_ i = l1; i <= r1; i++) ta[i-l1] = a[i];
    for(_ i = l2; i <= r2; i++) tb[i-l2] = a[i];
    _ i = 0, j = 0, k = l1;
    while(i <= r1-l1 && j <= r2-l2) {
        if(ta[i] < tb[j]) a[k++] = ta[i++];
        else a[k++] = tb[j++];
    }
    while(i <= r1-l1) a[k++] = ta[i++];
    while(j <= r2-l2) a[k++] = tb[j++];
    
    //lots of shady stuff
    
    return;
}
