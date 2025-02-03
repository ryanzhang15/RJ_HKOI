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

_ av[300], n, k;
str a, b;

void permutate(str cur);
int main(int argc, char * argv[]) {
    
    cin >> n >> k;
    
    cin >> a;
    for(char i : a) {
        if(!av[i]++) {
            b += i;
        }
    }
    
    sort(b.begin(), b.end());
    
    permutate("");
    
    return 0;
}

void permutate(str cur) {
    if(cur.length() == n) {
        cout << cur << endl;
        if(!--k) exit(0);
        return;
    }
    for(char i : b) {
        if(av[i]) {
            av[i]--;
            permutate(cur + i);
            av[i]++;
        }
    }
    return;
}
