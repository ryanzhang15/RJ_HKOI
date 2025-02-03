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

constant maxn = 1E3+88;

_ n, rg[4][2], a[maxn], oc, tc, thc;
queue<pair<_, _> > swaps;

void sortOut(_ n);
int main(int argc, char * argv[]) {
    
    cin >> n;
    for(_ i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 1) oc++;
        else if(a[i] == 2) tc++;
        else thc++;
    }
    rg[1][0] = 1; rg[1][1] = oc;
    rg[2][0] = oc+1; rg[2][1] = rg[2][0] + tc - 1;
    rg[3][0] = rg[2][1]+1; rg[3][1] = n;
    
    sortOut(1);
    sortOut(1);
    sortOut(2);
    
    cout << swaps.size() << endl;
    while(!swaps.empty()) {
        cout << swaps.front().first <<' '<< swaps.front().second << endl;
        swaps.pop();
    }
    
    return 0;
}

void sortOut(_ n) {
    if(n == 1) {
        tc = 0; thc = 0;
        stack<_> tcpos, thpos;
        for(_ i = rg[1][0]; i <= rg[1][1]; i++) {
            if(a[i] == 2) {
                tc++;
                tcpos.push(i);
            }
            if(a[i] == 3) {
                thc++;
                thpos.push(i);
            }
        }
        for(_ i = rg[2][0]; i <= rg[2][1] && tc; i++) {
            if(a[i] == 1) {
                swap(a[i], a[tcpos.top()]);
                swaps.push({i, tcpos.top()});
                tcpos.pop();
                tc--;
            }
        }
        for(_ i = rg[3][0]; i <= rg[3][1] && thc; i++) {
            if(a[i] == 1) {
                swap(a[i], a[thpos.top()]);
                swaps.push({i, thpos.top()});
                thpos.pop();
                thc--;
            }
        }
        for(_ i = rg[2][0]; i <= rg[2][1] && tc; i++) {
            if(a[i] == 3) {
                swap(a[i], a[tcpos.top()]);
                swaps.push({i, tcpos.top()});
                tcpos.pop();
                tc--;
            }
        }
        for(_ i = rg[3][0]; i <= rg[3][1] && thc; i++) {
            if(a[i] == 2) {
                swap(a[i], a[thpos.top()]);
                swaps.push({i, thpos.top()});
                thpos.pop();
                thc--;
            }
        }
    } else {
        thc = 0;
        stack<_> thpos;
        for(_ i = rg[2][0]; i <= rg[2][1]; i++) {
            if(a[i] == 3) {
                thc++;
                thpos.push(i);
            }
        }
        for(_ i = rg[3][0]; i <= rg[3][1] && thc; i++) {
            if(a[i] == 2) {
                swap(a[i], a[thpos.top()]);
                swaps.push({i, thpos.top()});
                thpos.pop();
                thc--;
            }
        }
    }
    return;
}
