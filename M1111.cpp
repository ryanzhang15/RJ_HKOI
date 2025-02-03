
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>

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

str n; str ncpy;

int main(int argc, char * argv[]) {
    
    str n; cin >> n;
    sort(n.begin(), n.end());
    ncpy = n;
    reverse(ncpy.begin(), ncpy.end());
    cout << ncpy << endl;
    _ size = n.length();
    if(n[0] == '0') {
        for(_ j = 1; j < size; j++) {
            if(n[j] != '0') {
                swap(n[0], n[j]);
                break;
            }
        }
    }
    cout << n << endl;
    
    
    return 0;
}

