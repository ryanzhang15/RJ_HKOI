#pragma gcc optim

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

_ n;
multiset<_> s;

int main(int argc, char * argv[]) {
    
    cin >> n;
    while(n--) {
        _ cmd; cin >> cmd;
        if(cmd == 1) {
            _ x; cin >> x;
            s.insert(x);
        }
        else if(cmd == 2) cout << (s.empty() ? -1 : *s.begin()) << endl;
        else if(cmd == 3) cout << (s.empty() ? -1 : *s.rbegin()) << endl;
        else if(cmd == 4) s.erase(s.lower_bound(*s.begin()));
        else if(cmd == 5) s.erase(s.lower_bound(*s.rbegin()));
    }
    
    return 0;
}
