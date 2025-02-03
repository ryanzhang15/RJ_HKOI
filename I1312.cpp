//#include <bits/stdc++.h>
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
typedef const long long constant;

_ h, w, a[7], t, c;

int main() {
    
    scanf("%lld%lld", &h, &w);
    for(_ i = 1; i <= h; ++i) {
        scanf("%lld%lld%lld", &a[1], &a[2], &a[3]);
        c = a[1]+a[2]+a[3];
        for(_ j = 1; j <= w-1; ++j) {
            scanf("%lld%lld%lld", &a[1], &a[2], &a[3]);
            t += abs(c-a[1]-a[2]-a[3]);
            c = a[1]+a[2]+a[3];
        }
    }
    
    t /= (h*(w-1));
    if(t <= 7) puts("4");
    ef(t <= 20) puts("1");
    ef(t <= 59) puts("2");
    else puts("3");
    
    return 0;
}

