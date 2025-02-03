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

_ n, tc, thc;

int main(int argc, char * argv[]) {
    
    cin >> n;
    while(n >= 4) {
        tc++; n /= 2;
    }
    if(n == 3) cout << 3;
    else tc++;
    for(_ i = 0; i < tc; i++) cout << 2;
    cout << endl;
    
    return 0;
}
