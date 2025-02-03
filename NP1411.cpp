
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

constant maxc = 200+8;

pair<bool, bool> win = {1, 0};
pair<bool, bool> los = {0, 1};
pair<bool, bool> tee = {0, 0};

pair<bool, bool> wol[5][5] = {{tee, los, win, win, los},
    {win, tee, los, win, los},
    {los, win, tee, los, win},
    {los, los, win, tee, win},
    {win, win, los, los, tee},
};

_ n, na, nb, as, bs;
_ a[maxc], b[maxc];

int main(int argc, char * argv[]) {
    
    freopen("rps.in", "r", stdin);
    freopen("rps.out", "a", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> na >> nb;
    for(_ i = 0; i < na; i++) cin >> a[i];
    for(_ i = 0; i < nb; i++) cin >> b[i];
    
    for(_ i = 0; i < n; i++) {
        as += wol[a[i%na]][b[i%nb]].first;
        bs += wol[a[i%na]][b[i%nb]].second;
    }
    
    cout << as << ' ' << bs << endl;
    
    return 0;
}

