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

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E6+8;

_ n, k, p, f, a[maxn], c;

int main() {
    
    memset(a, ~0, sizeof a);
    scanf("%lld%lld%lld%lld", &n, &k, &p, &f);
    for(_ i = 0, j = 0; i <= k; ++i, j = (j+p)%f) if(!~a[j]) a[j] = i;
    for(; n--; ) {
        scanf("%lld", &c);
        _ mn = a[(c%f)];
        if(!~mn) {
            putchar('0');
            continue;
        }
        if(c-(mn*p) < 0) {
            putchar('0');
            continue;
        }
        _ t = mn + (c-(mn*p))/f;
        if(t > k) {
            putchar('0');
            continue;
        }
        putchar('1');
    }
        
    putchar(10);
    fflush(stdout);
    
    return 0;
}

