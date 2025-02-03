
/*
 ID: ryanjz2024
 LANG: C++11
 TASK: 铺地毯
 */

#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>

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

vector<_0> pos (70000, 0);
vector<_0> nos;
vector<_0> res;

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0)
    
    freopen("count.in", "r", stdin);
    freopen("count.out", "a", stdout);
    
    _0 N = 0; cin >> N;
    while(N --> 0) {
        _0 a = 0; cin >> a;
        pos[a] = 1;
        nos.push_back(a);
    }
    
    _ size = nos.size();
    
    for(_ i = 0; i < size; i++) {
        for(_ j = i + 1; j < size; j++) {
            if(pos[nos[i] + nos[j]] == 1) {
                res.push_back(nos[i] + nos[j]);
            }
        }
    }
    
    sort(res.begin(), res.end());
    size = res.size();
    _ cnt = 0;
    for(_0 i = 0; i < size; i++) {
        if(i != 0) if(res[i - 1] == res[i]) continue;
        cnt++;
    } cout << cnt << endl;
    
    return 0;
    
}


