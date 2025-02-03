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

_ l = 1E12, r = -1E12;

int main(int argc, char * argv[]) {
    
    freopen("weather.txt", "r", stdin);
    
    str a;
    while(cin >> a) {
        bool flag = false;
        for(char i : a) if(!(i >= '0' and i <= '9')) flag = true;
        if(flag) continue;
        _ f = stoll(a);
        l = min(l, f);
        r = max(r, f);
    }
    
    cout << l <<' '<< r << endl;
    
    return 0;
}
