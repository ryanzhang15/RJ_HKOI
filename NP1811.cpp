
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

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
typedef const long long maxn;

maxn mn = 1e5+88;
_ n, ctr, holes[mn];

int main(int argc, char * argv[]) {
    
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    
    cin >> n; _ in = 0;
    while(in < n) cin >> holes[in++];
    
    for(_ i = 1; i < n; i++) {
        if(holes[i] > holes[i-1]) ctr += holes[i] - holes[i-1];
    }
    
    cout << ctr + holes[0] << endl;
    
    return 0;
}

