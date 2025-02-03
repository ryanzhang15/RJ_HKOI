
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

constant maxn = 5E3+8;
//constant maxn = 5;

_ n, b[maxn], ans;
vector<_> a;

int main(int argc, char * argv[]) {
    
    cin >> n;
    for(_ i = 0; i < n; i++) {
        _ cc; cin >> cc;
        a.push_back(cc);
    }
    for(_ i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b, b+n, greater<_>());
    
    for(_ i = 0; i < n; i++) {
        vector<_>::iterator lb = upper_bound(a.begin(), a.end(), b[i]);
        if(lb == a.end()) {
            a.erase(a.begin());
        } else {
            ans++;
            a.erase(lb);
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
