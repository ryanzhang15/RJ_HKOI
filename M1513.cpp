#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <bitset>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>

#define ef else if
 
using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 2E6+8;

_ a[maxn], p[maxn], n, x, y;

int main(int argc, char * argv[]) {
    
	scanf("%lld", &n);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld%lld", &x, &y);
		if(x <= n) ++a[x];
		if(y+1 <= n) --a[y+1];
	}
	for(_ i = 1; i <= n; ++i) p[i] = p[i-1]+a[i];
	for(_ i = n; i >= 0; --i) if(p[i] >= i) {
		printf("%lld\n", i);
		break;
	}
   
    return 0;
}


