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

void ms(_ l, _ r);

_ n;
int main(int argc, char * argv[]) {
    
    //they rly want me to know my merge sort
    cin >> n;
    ms(1, n);
    
    return 0;
}

void ms(_ l, _ r) {
    if(l == r) return;
    ms(l, l+(r-l)/2);
    ms(l+(r-l)/2+1, r);
    cout << l <<' '<< l+(r-l)/2 <<' '<< l+(r-l)/2+1 <<' '<< r << endl;
    return;
}
