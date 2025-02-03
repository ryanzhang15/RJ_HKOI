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

_ w1, w2, w3, d1, d2, a, b, m;

int main(int argc, char * argv[]) {
    
    cin >> w1 >> w2 >> w3;
    d1 = w2-w1; d2 = w3-w2;
    if(d1 == d2) m = max(w1, max(w2, w3))+1;
    else {
        m = (_)abs(d1-d2);
        if(m <= w1 || m <= w2 || m <= w3 || (d1 > 0 && d2 > 0 && d1 != d2) || (d1 < 0 && d2 < 0 && d1 != d2)) {
            cout << "No solution" << endl;
            exit(0);
        }
    }
    
    a = (d1+m)%m;
    b = (w1-a+m)%m;
    cout << a <<' '<< b <<' '<< m << endl;
    
    return 0;
}
