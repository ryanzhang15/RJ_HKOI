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
typedef float _D;
typedef string str;
typedef const long long constant;

str mon;
_   day;

int main(int argc, char * argv[]) {
    
    
    cin >> mon >> day;
    if(mon == "OCT") {
        if(day%10 >= 8 || day/10 >= 8) {
            cout << "No solution" << endl;
            exit(0);
        }
        _ ans = 0, cnt = 0;
        while(day) {
            ans += day%10 * pow(8, cnt);
            day /= 10;
            cnt++;
        }
        if(ans <= 31) {
            cout << "DEC " << ans/10 << ans%10 << endl;
        } else cout << "No solution" << endl;
    } else {
        _ ans = 0;
        ans = (day%8)+10*(day/8);
        if(ans <= 31) {
            cout << "OCT " << ans/10 << ans%10 << endl;
        } else cout << "No solution" << endl;
    }
    
    return 0;
}

