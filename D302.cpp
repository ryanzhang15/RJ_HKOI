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

str a;

int main(int argc, char * argv[]) {

    //ios_base::sync_with_stdio(NULL);
    //cin.tie(0);
    
    getline(cin, a);
    cout << a.size() << '\n' << count(a.begin(), a.end(), ' ') + 1 << endl;
    
    return 0;
}
