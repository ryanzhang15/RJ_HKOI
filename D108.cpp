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

stack<_> s;
stack<char> o;

bool pastm;
int main(int argc, char * argv[]) {
    
    _ num; cin >> num;
    s.push(num);
    for(_ i = 0; i < 2; i++) {
        char op; cin >> op >> num;
        if(op == '*') {
            _ top = s.top(); s.pop();
            s.push(num * top);
        } else {
            if(pastm) {
                _ a = s.top(); s.pop();
                _ b = s.top(); s.pop();
                s.push(b - a);
                o.pop();
                pastm = !pastm;
            }
            else if(op == '-') pastm = true;
            s.push(num);
            o.push(op);
        }
    }
    
    while(s.size() > 1) {
        _ a = s.top(); s.pop();
        _ b = s.top(); s.pop();
        if(o.top() == '+') {
            s.push(a + b);
        } else {
            s.push(b - a);
        }
        o.pop();
    }
    
    cout << s.top() << endl;
    
    return 0;
}
