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
typedef float _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E5+8;

priority_queue<_, vector<_>, greater<_> > g[maxn]; //jeeeezus

_ n, r, a, b;

void traverse(_ p, _ f);
int main(int argc, char * argv[]) {
    
    cin >> n >> r;
    for(; n --> 1; ) { //big arrow operator (lmao)
        cin >> a >> b;
        g[a].push(b);
        g[b].push(a);
    }
    
    traverse(r, -69); //I'm funny, I know.
    cout << endl;
    
    return 0;
}

void traverse(_ p, _ f) {
    for(; !g[p].empty(); ) {
        _ v = g[p].top(); g[p].pop();
        if(v == f) continue;
        traverse(v, p);
    }
    cout << p <<' ';
}
