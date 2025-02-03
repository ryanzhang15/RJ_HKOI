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

str key[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
_ n, d = 1;

bool isLeap(_ n);
int main(int argc, char * argv[]) {
    
    cin >> n;
    
    //This problem is cute
    //BuT google calendar is much easier
    
    //I found out 2000 is Monday beforehand
    for(_ i = 2000; i < n; i++) {
        d = (d+1)%7;
        if(isLeap(i)) d = (d+1)%7;
    }
    
    cout << key[d] << endl;
    
    return 0;
}

bool isLeap(_ n) {
    if(n % 4) return false;
    if(!(n % 100) && n % 400) return false;
    return true;
}
