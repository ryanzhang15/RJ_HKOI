
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

_ n, a;

int main(int argc, char * argv[]) {
    
    freopen("account.txt", "r", stdin);
    
    //This question is sooo easy... if i get WA i shld quit doing this
    cin >> n;
    while(n--) {
        _ b; cin >> b;
        a += b;
    }
    
    cout << a << endl;
    
    return 0;
}
