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
typedef float _D;
typedef string str;
typedef const long long constant;

_ oop, grid[6][6] = {{0, 0, 0, 0, 0, 0}, 
    {0, 1, 1, 1, 1, 1},
    {0, 1, 2, 2, 2, 1},
    {0, 1, 2, 3, 2, 1},
    {0, 1, 2, 2, 2, 1},
    {0, 1, 1, 1, 1, 1}
};

int main(int argc, char * argv[]) {
    
    for(_ i = 1; i <= 5; i++)
        for(_ j = 1; j <= 5; j++) {
            _ a; cin >> a;
            if(a != grid[i][j]) oop++;
        }
    
    cout << (_)ceil((_D)oop/2.0) << endl;
    
    return 0;
}

