
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

constant absmax = 1E5+88;

_ a[absmax], b[absmax], c[2*absmax], n, m, ac, bc;

int main(int argc, char * argv[]) {
    
    cin >> n >> m;
    for(_ i = 0; i < n; i++) cin >> a[i];
    for(_ i = 0; i < m; i++) cin >> b[i];
    while(ac < n and bc < m) {
        if(a[ac] < b[bc]) {
            c[ac+bc] = a[ac];
            ac++;
        }
        else {
            c[ac+bc] = b[bc];
            bc++;
        }
    }
    while(ac < n) {
        c[ac+bc] = a[ac];
        ac++;
    }
    while(bc < m) {
        c[ac+bc] = b[bc];
        bc++;
    }
    
    //just your standard merge sort
    
    for(_ i = 0; i < ac+bc; i++) cout << c[i] << ' ';
    cout << endl;
    
    return 0;
}
