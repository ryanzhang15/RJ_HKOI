
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

str f;
_ av[300], n;

int main(int argc, char * argv[]) {
    
    cin >> f;
    for(char i : f) av[i]++;
    cin >> n;
    while(n--) {
        str a; cin >> a;
        bool yes = true;
        for(char i : a) if(av[i] < count(a.begin(), a.end(), i)) {
            cout << "No" << endl;
            yes = false;
            break;
        }
        if(yes) cout << "Yes" << endl;
    }
    
    return 0;
}
