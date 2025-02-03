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

constant maxn = 5E6+8;

_0 bad[maxn]; //never had to do this before
_ n;

int main(int argc, char * argv[]) {
    
    //\
    この問題が大嫌いですね。ひどりです！
    //・・・・・・・・・・・・・・・・
    
    cin >> n;
    for(_ i = 0; i < n; i++) cin >> bad[i];
    sort(bad, bad+n);
    cout << bad[n/2] << endl;
    
    return 0;
}
