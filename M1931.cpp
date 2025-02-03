
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
typedef pair<_, _> _p;
typedef const long long constant;

_ n, v1, v2, v3, v4;

int main() {
    
    scanf("%lld%lld%lld%lld%lld", &n, &v1, &v2, &v3, &v4);
    printf("%lld\n", (_)pow(4, n-1)*n*(v1+v2+v3+v4));
    
    return 0;
}


