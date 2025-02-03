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
typedef string str;
typedef const long long constant;

constant maxn = 1E5+8;
constant maxd = 10+8;

_ n, m, a[maxd];
bitset<maxn> v;
struct node {
    _ md;
    str c;
};
queue<node> q;

int main() {
    
    scanf("%lld%lld", &n, &m);
    for(_ i = 1; i <= m; ++i) scanf("%lld", &a[i]);
    sort(a+1, a+1+m);
    
    q.push((node){-1, ""});
    for(; !q.empty(); q.pop()) {
        node t = q.front();
        for(_ i = 1; i <= m; ++i) {
            _ cmd = t.md;
            if(cmd == -1) cmd = a[i];
            else cmd = (cmd*10+a[i])%n;
            if(cmd && v[cmd]) continue;
            v.set(cmd);
            str ts = t.c;
            ts.push_back(a[i]^48);
            if(ts == "0") continue;
            if(!cmd) {
                cout << ts << endl;
                exit(0);
            }
            q.push((node){cmd, ts});
        }
    }
    
    puts("0");
    
    return 0;
}

