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

constant maxn = 1E3+8;
bool dead[maxn];
_ n, p = 1;

_ kill(_ p);
int main(int argc, char * argv[]) {

    cin >> n;
    while(1) {
        _ a = kill(p);
        if(a == p) break;
        cout << ((!a) ? n : a) << ' ';
        p = kill(a);
        dead[p] = false;
    } cout <<'\n'<< ((!p) ? n : p) << endl;
    
    return 0;
}

_ kill(_ p) {
    while(dead[(++p)%n]) p %= n; //some shady stuff
    dead[p%n] = true;
    return p%n;
}
