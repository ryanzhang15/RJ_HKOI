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

priority_queue<_, vector<_>, greater<_> > q;
_ n, ans;

int main(int argc, char * argv[]) {
    
    cin >> n; // we dont care abt n
    _ a;
    while(cin >> a) {
        //will end after detecting EOF
        q.push(a);
    }
    
    //we can actually use the greedy algorithm to solve this problem!
    
    while(q.size() > 1) {
        _ a = q.top(); q.pop();
        _ b = q.top(); q.pop();
        ans += a + b;
        q.push(a+b);
    }
    
    cout << ans << endl;
    
    return 0;
}
