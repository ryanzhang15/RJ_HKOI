
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

_ n;

int main(int argc, char * argv[]) {
    
    cin >> n;
    for(_ i = 0; i < n; i++) {
        for(_ j = i*i+1;; j -= i) {
            cout << j << ' ';
            if(j==1) break;
        } cout << endl;
    }
    
    return 0;
}
