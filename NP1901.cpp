
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

char a;
_ ans = 0;

int main(int argc, char * argv[]) {
    
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    
    for(_ i = 0; i < 8; i++) {
        cin >> a;
        if(a == '1') ans++;
    } cout << ans << endl;
    
    
    return 0;
}
