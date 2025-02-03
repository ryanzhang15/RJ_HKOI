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

_ n;
bool t, s;

int main(int argc, char * argv[]) {
    
    cin >> n;
    _ rt = sqrt(n);
    if(rt*rt == n) s = true;
    
    rt = sqrt(8*n+1);
    if(rt*rt == 8*n+1) t = true;
    
    if(s && t) cout << "Both" << endl;
    else if(s) cout << "Square" << endl;
    else if(t) cout << "Triangular" << endl;
    else       cout << "Neither" << endl;
    
    return 0;
}
