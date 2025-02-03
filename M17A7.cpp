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

_ dot, dash, n;
char dd;

int main(int argc, char * argv[]) {
    
    cin >> n;
    while(cin >> dd) {
        if(dd == '.') dot++;
        if(dd == '-') dash++;
    }
    
    cout << 2*dot-dash << endl;
    
    return 0;
}

