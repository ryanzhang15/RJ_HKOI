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

priority_queue<_, vector<_>, greater<_> > g;
priority_queue<_> l;
_ c;

int main(int argc, char * argv[]) {
    
    while(cin >> c) {
        if(g.empty() || c >= g.top()) g.push(c);
        else l.push(c);
        if(g.size() - l.size() == 2) {
            l.push(g.top());
            g.pop();
        } else if(l.size() - g.size() == 2) {
            g.push(l.top());
            l.pop();
        }
        if(g.size() == l.size()) cout << (g.top() + l.top())/2 << endl;
        else if(g.size() > l.size()) cout << g.top() << endl;
        else cout << l.top() << endl;
    }
    
    return 0;
}
