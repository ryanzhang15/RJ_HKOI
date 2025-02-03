
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

_ n, c, a = -1E9, b = -1E9;
int main(int argc, char * argv[]) {
    
    cin >> n;
    while(n --> 0) { //cool arrow thing
        cin >> c;
        if(c >= a) {
            b = a;
            a = c;
        } else if(c > b) b = c;
    }
    cout << a << '\x0A' << b << endl; //\x0A just to flex
    
    return 0;
}

