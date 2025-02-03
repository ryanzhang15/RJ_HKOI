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

str n, sub;
_ a;

int main(int argc, char * argv[]) {
    
    cin >> n >> sub;
    if(sub.length() > n.length()) {
        cout << 0 <<'\n'<< 0 << endl;
        exit(0);
    }
    //sort out overlap
    for(_ i = 0; i <= n.length()-sub.length(); i++) a += n.substr(i, sub.length()) == sub;
    cout << a << endl;
    //ThAt WaS eAsY
    a = 0;
    for(_ i = 0; i <= n.length()-sub.length(); i++) {
        if(n.substr(i, sub.length()) == sub) {
            a++;
            i += sub.length()-1;
        }
    }
    cout << a << endl;
    
    return 0;
}
