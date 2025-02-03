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

_ a, b, c, d;

int main(int argc, char * argv[]) {
    
    cin >> a >> b >> c >> d;
    cout << b + c + 2*d + ((a-2*d) < 0 ? 0 : (_)ceil((_D)(a-2*d)/2.0)) << endl;
    
    return EXIT_SUCCESS;
}
