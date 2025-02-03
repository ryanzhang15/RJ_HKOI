
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
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

_ n, x;

int main() {
    
    scanf("%lld", &n);
    if(!n) {
        puts("1\n0");
        exit(0);
    }
    x = sqrt(n);
    if(x*(x+1) >= n) {
        printf("%lld\n", x<<1);
        for(_ i = 0; i <= x-1; ++i) printf("%lld ", i);
        for(_ i = 1; i <= x; ++i) printf("%lld ", i*x);
    } else {
        printf("%lld\n", (x<<1)+1);
        for(_ i = 0; i <= x-1; ++i) printf("%lld ", i);
        for(_ i = 1; i <= x; ++i) printf("%lld ", i*x);
        printf("%lld ", x*x+x);
    }
    putchar(10);
    
    return 0;
}

