
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

int main(int argc, char * argv[]) {
    
    freopen("title.in", "r", stdin);
    freopen("title.out", "a", stdout);
    
    str a;
    getline(cin, a);
    cout << a.length() - count(a.begin(), a.end(), ' ') << endl;
    
    return 0;
}
