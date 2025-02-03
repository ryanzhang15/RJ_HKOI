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

_ n, q1, q2;
queue<_> q;

int main(int argc, char * argv[]) {
    
    cin >> n;
    while(n--) {
        _ a; cin >> a;
        if(a > q1) {
            q1 = a;
            q.push(1);
        } else if(a > q2) {
            q2 = a;
            q.push(2);
        } else {
            cout << "NO" << endl;
            exit(0);
        }
    }
    
    cout << "YES" << endl;
    while(!q.empty()) {
        cout << q.front() <<' ';
        q.pop();
    } cout << endl;
    
    return 0;
}

