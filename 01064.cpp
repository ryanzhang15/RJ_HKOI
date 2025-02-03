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

constant maxn = 1E5+88;

_ n, modec, cnt[maxn], c, modes[maxn];

int main(int argc, char * argv[]) {
    
    cin >> n;
    //O(n) time solution
    while(n--) {
        _D a; cin >> a;
        _ v = (_)(round(a*100));
        cnt[v]++;
        if(cnt[v] > modec) {
            modec = cnt[v];
            modes[c=0] = v;
        } else if(cnt[v] == modec) {
            modes[++c] = v;
        }
    }
    sort(modes, modes+c+1);
    for(_ i = 0; i <= c; i++) {
        _D a = (_D)modes[i]/100.0;
        printf("%6.2f\n", a);
    }
    
    
    return 0;
}
