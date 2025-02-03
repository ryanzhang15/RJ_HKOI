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

constant maxn = 1E3+8;
constant maxc = 2E5+8;
_ c, n, a[maxn], dp[maxc], cnt;

void addItem();
int main() {
    
    scanf("%lld%lld", &c, &n);
    fill(dp+1, dp+1+c, -1E15);
    for(_ i = 1; i <= n; ++i) addItem();
    for(_ i = 1; i <= cnt; ++i) for(_ j = c; j >= a[i]; --j) dp[j] = max(dp[j], dp[j-a[i]]+a[i]);
    printf("%lld\n", *max_element(dp, dp+1+c));
    
    return 0;
}

void addItem() {
    _ nt, t;
    scanf("%lld%lld", &nt, &t);
    for(_ i = 1; ; i <<= 1) {
        if(i >= nt) {
            a[++cnt] = t*nt;
            break;
        }
        a[++cnt] = i*t;
        nt -= i;
    }
    return;
}

