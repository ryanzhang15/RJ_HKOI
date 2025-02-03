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

priority_queue<_, vector<_>, greater<_> > q;

_ n, a, ans;

int main(int argc, char * argv[]) {
    
    cin >> n;
    for(;n--;) { //now I only use for loops
        cin >> a;
        q.push(a);
    }
    //i know how to do this one!
    for(;q.size() > 1;) {
        _ a = q.top(); q.pop();
        _ b = q.top(); q.pop();
        q.push(a+b);
        ans += a+b;
    }
    
    cout << ans << endl;
    
    return 0;
}
