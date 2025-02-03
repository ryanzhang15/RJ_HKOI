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

constant maxn = 1E4+8;

_ n, h;
_ data[maxn], ne[maxn];

void speak(_ p);
int main(int argc, char * argv[]) {
    
    cin >> n >> h;
    for(_ i = 1; i <= n; i++) cin >> data[i];
    for(_ i = 1; i <= n; i++) cin >> ne[i];
    
    if(h) cout << data[h] << endl;
    speak(ne[h]);
    cout << "End" << endl;
    
    return 0;
}

void speak(_ p) {
    if(p == h or !p) return;
    cout << data[p] << endl;
    speak(ne[p]);
    return;
}
