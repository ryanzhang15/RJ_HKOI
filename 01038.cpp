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

constant maxn = 1E2+8;\

_ n, r;
priority_queue<_, vector<_>, greater<_> > g[maxn]; // some shady stuff

void traverse(_ p, _ f);
int main(int argc, char * argv[]) {
    
    cin >> n >> r;
    for(_ i = 0; i < n-1; i++) {
        _ a, b; cin >> a >> b;
        g[a].push(b);
        g[b].push(a);
    }
    
    traverse(r, 69420);
    cout << endl;
    
    return 0;
}

void traverse(_ p, _ f) {
    //root left right
    cout << p <<' ';
    while(!g[p].empty()) {
        if(g[p].top() != f) traverse(g[p].top(), p);
        g[p].pop();
    }
}
