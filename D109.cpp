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

_ money[] = {1000, 500, 100, 50, 20, 10}; //oops last time i put 200
_ n, i;

int main(int argc, char * argv[]) {
    
    //just a simple greedy algorithm
    i = 0;
    cin >> n;
    while(n) {
        if(n < money[i]) i++;
        else {
            n -= money[i];
            cout << money[i] << endl;
        }
    }
    
    return 0;
}
