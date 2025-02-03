
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

constant mn = 1E5+88;
//constant mn = 10;

_ n, m, beads[mn], colors[mn], curans, ans;
int main(int argc, char * argv[]) {
    
    cin >> n >> m;
    for(_ i = 0; i < n; i++) {
        cin >> beads[i];
        if(!colors[beads[i]]++) curans++;
        if(i >= m) if(!--colors[beads[i-m]]) curans--;
        ans = max(ans, curans);
    }
    
    cout << ans << endl;
    
    return 0;
}
