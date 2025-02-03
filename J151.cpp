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

_ n, m, sn = 1;

int main(int argc, char * argv[]) {

    //This one's interesting
        
    cin >> n >> m;
    
    if(n % 2) {
        cout << m;
        n--;
    } else {
        if(m >= 0) cout << m-1 <<' '<< 1;
        else cout << m+1 <<' '<< -1;
        n-=2;
        m--;
        sn = 2;
    }
    
    n /= 2;
    while(n--) {
        if(sn == m || -sn == m) sn++;
        cout <<' '<< sn <<' '<< -sn;
        sn+=2;
    }
        
    return 0;
}
