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

_ b, p, m;

_ bpm(_ n);
int main(int argc, char * argv[]) {
    
    cin >> b >> p >> m;
    cout << bpm(p) << endl;
    
    return 0;
}

_ bpm(_ n) {
    if(!n) return 1;
    if(n%2) {
        _ a = bpm(n/2);
        return (((a*a)%m)*b)%m;
    } else {
        _ a = bpm(n/2);
        return (a*a)%m;
    }
}
