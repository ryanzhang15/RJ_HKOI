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

pair<_, _> pp[108];
_ n;

bool cmp(pair<_, _> a, pair<_, _> b);
int main(int argc, char * argv[]) {
    
    cin >> n;
    for(_ i = 0; i < n; i++) cin >> pp[i].first >> pp[i].second;
    
    sort(pp, pp+n, cmp);
    
    for(_ i = 0; i < n; i++) cout << pp[i].first <<' '<< pp[i].second << endl;
    
    return 0;
}

bool cmp(pair<_, _> a, pair<_, _> b) {
    return a.first*a.first + a.second*a.second < b.first*b.first + b.second*b.second;
}
