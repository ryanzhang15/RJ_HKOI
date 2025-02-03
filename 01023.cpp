
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

constant maxn = 1E5;

_ n, k, arr[maxn]; //those bastards didn't give me maxn
int main(int argc, char * argv[]) {
    
    //time to make good use of the std lower bound function;;;
    cin >> n >> k;
    
    for(_ i = 0; i < n; i++) cin >> arr[i];
    _ l = lower_bound(arr, arr+n, k) - arr; //some shady stuff
    
    if(l > 0 && (_)abs(k-arr[l-1]) < (_)abs(arr[l]-k)) cout << arr[l-1] << endl;
    else cout << arr[l] << endl; // some more shady stuff
    
    return 0;
}

