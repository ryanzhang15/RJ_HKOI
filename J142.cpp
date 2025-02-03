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

_ n, mb, mg, lb, lg, v;

int main(int argc, char * argv[]) {
    
    cin >> n;
    while(n--) {
        _ cmd; cin >> cmd;
        switch(cmd) {
            case 1:
                cin >> v;
                mb += v;
                lb += v;
                break;
            case 2:
                cin >> v;
                mg += v;
                lg += v;
                break;
            case 3:
                cin >> v;
                mg -= v;
                if(mg < 0) {
                    mb += mg;
                    mg = 0;
                }
                lb -= v;
                if(lb < 0) {
                    lg += lb;
                    lb = 0;
                }
                break;
            case 4:
                cout << mb <<' '<< lb << endl;
                break;
        }
    }
    
    return 0;
}
