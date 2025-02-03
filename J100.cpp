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

_ n, flip = 1, cnt = 1;

int main(int argc, char * argv[]) {
    
    cin >> n;
    for(_ i = 1; i > 0; i += flip) { // this is some weird stuff
        if(i == n) flip = -flip;
        for(_ j = cnt; j < cnt + i; j++) cout << j << ' ';
        cnt += i;
        cout << endl;
    }
    
    return 0;
}
