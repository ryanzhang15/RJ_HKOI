
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

_ a, b;
char c, d;

int main(int argc, char * argv[]) {
    
    //I was gonna write bfs
    //but then i realised... you don't have to
    cin >> c >> a >> d >> b;
    cout << max((_)abs(c-d), abs(b-a)) << endl;
    
    return 0;
}

