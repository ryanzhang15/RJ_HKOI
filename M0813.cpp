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

constant maxn = 1E6+88;

_ n, m, open, cnt, chain[maxn], ans, e;

int main(int argc, char * argv[]) {
    
    cin >> n >> m; e = m-1;
    for(_ i = m-1; i >= 0; i--) cin >> chain[i];
    for(; cnt < m; cnt++) { //some shady stuff
        if(open >= chain[e]) {
            open -= chain[e--];
            m--;
        }
        if(n > chain[cnt]) {
            n -= chain[cnt] + 1;
            open++;
            ans ++;
        } else {
            //should really be the last chain
            open -= chain[cnt] - n;
            n = 0;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
