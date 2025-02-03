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
typedef __int128 _;
typedef int _0;
typedef unsigned int u_0;
typedef double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E6+88;

_ cur = -1E10, curmax = -1E10, score[maxn], ans = -1E10;
long long n, p;

int main(int argc, char  * argv[]) {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(0);
    
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    
    cin >> n >> p;
    for(_ i = 0; i < n; i++) {
        long long a; cin >> a;
        if(cur+a > a) cur = cur+a;
        else cur = a;
        curmax = max(curmax, cur);
        score[i] = curmax;
        //cout << score[i] << ' ';
    }
    //cout << endl;
    
    cur = score[0]*2;
    ans = score[0];
    for(_ i = 1; i < n; i++) {
        ans = max(ans, cur);
        _ temp = score[i];
        score[i] = cur;
        cur = max(cur, score[i] + temp);
    }
    
    cout << (long long)(ans % p) << endl;
    
    return 0;
}
