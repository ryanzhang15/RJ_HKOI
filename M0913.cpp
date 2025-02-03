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

vector<_> data;
_ n;

int main(int argc, char * argv[]) {
    
    cin >> n;
    _ fn; 
    while(n--) {
        _ cmd; cin >> cmd;
        switch(cmd) { //seldom use switch case
            case 1:
                cin >> fn;
                data.push_back(fn);
                break;
            case 2:
                cin >> fn;
                data.erase(find(data.begin(), data.end(), fn));
                break;
            case 3:
                for(_ i : data) cout << i << ' ';
                cout << endl;
                break;
            case 4:
                vector<_> a = data;
                sort(a.begin(), a.end());
                for(_ i : a) cout << i << ' ';
                cout << endl;
                break;
        }
    }
    
    return 0;
}
