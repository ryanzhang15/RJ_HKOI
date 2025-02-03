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

constant maxn = 1E5+8;

_ n, k, d, cnt, cur, ml, start, ans[maxn], last;
str s, dd;

bool qualify(_ &cur);
void fail();
int main(int argc, char * argv[]) {
    
    cin >> n >> s >> k >> d;
    if(k > n) fail();
    for(_ i = 0; i < n; ++i) {
        cur *= 10;
        cur += s[i] - '0';
        if(qualify(cur)) {
            ans[cnt++] = i;
            cur = 0;
            last = i;
        }
    }
    
    if(last != n-1) {
        if(qualify(cur)) ans[cnt++] = start;
        else fail();
    }
    
    if(cnt < k) fail();
    
    cnt = 0;
    for(_ i = 0; i < n; i++) {
        cout << s[i];
        if(cnt < k-1 && i == ans[cnt]) {
            cout << endl;
            cnt++;
        }
    } cout << endl;
    
    return 0;
}

void fail() {
    cout << "Impossible" << endl;
    exit(0);
}

bool qualify(_ &cur) {
    cur %= d;
    return cur == 0;
}
