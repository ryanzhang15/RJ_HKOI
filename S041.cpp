
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

str num;

int main(int argc, char * argv[]) {
    
    _ n; cin >> n;
    
    cin >> num;
    _ ans = 0;
    for(char i : num) ans = (ans*10+i-'0')%11; //range based for loop
    
    if(ans == 10) ans = -1;
    cout << ans << endl;
    
    return 0;
    
}
