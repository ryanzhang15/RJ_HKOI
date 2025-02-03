

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

int main(int argc, char * argv[]) {
    
    _0 n; cin >> n;
    
    for(_0 i = 0; i < 10; i++) {
        for(_0 j = 1; j <= 10; j++) {
            if(!((10*i+j) % n)) cout << "Clap";
            else if((j == n || i == n) && j != 10) cout << "Clap";
            else cout << 10*i + j;
            if(j != 10) cout << ' ';
        } cout << endl;
    }
    
    return 0;
}

