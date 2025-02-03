
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
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

_ c, n, m, b, x, y;
priority_queue<_, vector<_>, greater<_> > q;

int main() {
    
    scanf("%lld%lld%lld", &n, &m, &b);
    for(; n--; ) {
        scanf("%lld%lld", &x, &y);
        if(y) x = (m<<1)-x;
        q.push(x);
    }
    for(_ i = 1; i <= b; ++i) {
        c = q.top();
        q.pop();
        c += (m<<1);
        q.push(c);
    }
    
    printf("%lld\n", c-m);
    
    return 0;
}

