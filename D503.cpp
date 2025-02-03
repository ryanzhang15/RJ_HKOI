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

_ size[6];

int main(int argc, char * argv[]) {
    
    freopen("chart.txt", "w", stdout);
    
    for(_ i = 0; i < 6; i++) cin >> size[i];
    
    cout << "+-------------------------+" << endl;
    for(_ i = 10; i > 0; i--) {
        cout << "| ";
        for(_ j = 0; j < 6; j++) {
            if(size[j] >= i) cout << "### ";
            else cout << "    ";
        }
        cout << "|" << endl;
    }
    cout << "+-------------------------+" << endl;
    
    return 0;
}

