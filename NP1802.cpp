
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

vector<_> army;

int main(int argc, char * argv[]) {
    
    freopen("fight.in", "r", stdin);
    freopen("fight.out", "w", stdout);
    
    _ N; cin >> N; _ n = N;
    
    while(N --> 0) {
        _ a; cin >> a; army.push_back(a);
    }
    _ m; cin >> m;
    _ p1, s1, s2; cin >> p1 >> s1 >> s2;
    army[p1 - 1] += s1;
    
    _ lp = 0, rp = 0;
    
    for(_ i = 0; i < m - 1; i++) {
        lp += (m - i - 1) * army[i];
    }
    for(_ i = m; i < n; i++) {
        rp += (i - m + 1) * army[i];
    }
    
    _ d = abs(lp - rp); m--;
    _ curbest = m;
    for(_ i = 0; i < n; i++) {
        if(i == m) {
            _ cand = abs(lp - rp);
            if(cand < d) {
                curbest = i;
                d = cand;
            }
        } else if(i < m) {
            _ cand = abs((lp + (m - i) * s2) - rp);
            if(cand < d) {
                curbest = i;
                d = cand;
            }
        } else if(i > m) {
            _ cand = abs((rp + (i - m) * s2) - lp);
            if(cand < d) {
                curbest = i;
                d = cand;
            }
        }
    } cout << ++curbest << endl;
    
    
    return 0;
    
}

