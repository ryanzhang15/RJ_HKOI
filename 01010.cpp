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

_ n, a, ans = -1E9;

int main(int argc, char * argv[]) {
    
    //simple stuff
    cin >> n;
    while(n--) {
        _ c; cin >> c;
        a = max(a+c, c);
        ans = max(ans, a);
    }
    
    cout << max(ans, (_)0) << endl;
    
    return 0;
}
