
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

constant mod = 1E4;

stack<_> nums;

char cur;
_ cur2, ans;

int main(int argc, char * argv[]) {
    
    freopen("expr.in", "r", stdin);
    freopen("expr.out", "a", stdout);
    
    cin >> cur2;
    nums.push(cur2%mod);
    while(cin >> cur >> cur2) {
        if(cur == '*') {
            _ a = nums.top(); nums.pop();
            nums.push(a*cur2%mod);
        } else nums.push(cur2%mod);
    }
    while(!nums.empty()) {
        ans = (ans + nums.top())%mod;
        nums.pop();
    }
    
    cout << ans << endl;
    
    return 0;
    
}
