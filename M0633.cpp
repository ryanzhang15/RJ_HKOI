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

constant maxn = 50+8;

str f[maxn];
_ n;

bool cmp(str a, str b);
int main(int argc, char * argv[]) {
    
    //Jesus Christ
    //The grammar in this question is indecipherable
    
    cin >> n;
    for(_ i = 0; i < n; i++) cin >> f[i];
    sort(f, f+n, cmp);
    for(_ i = 0; i < n; i++) cout << f[i];
    cout << endl;
    
    return 0;
}

bool cmp(str a, str b) {
    return a+b > b+a;
}
