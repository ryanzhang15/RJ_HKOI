
#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <iostream>
#include <cstdio>
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
#include <random>
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

struct con {
    _ t, a, b;
} a[28];
unordered_map<str, _> x = {{"Chan", 1}, {"Lee", 2}, {"Cheung", 3}, {"Wong", 4}, {"Ho", 5}, {"rat", 6}, {"cow", 7}, {"tiger", 8}, {"rabbit", 9}, {"dragon", 10}};
_ n, s, t[18];
str b, c, d;
bitset<10> v[2];

void dfs(_ d);
int main() {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(EXIT_SUCCESS);
    
    cin >> n;
    for(_ i = 1; i <= n; ++i) {
        cin >> b >> c;
        if(c == "lives") {
            a[i].t = 1;
            cin >> c >> c;
            a[i].a = x[b];
            cin >> a[i].b;
        } ef(c == "does") {
            cin >> c >> c;
            if(c == "live") {
                a[i].t = 2;
                cin >> c >> c;
                a[i].a = x[b];
                cin >> a[i].b;
            } else {
                a[i].t = 4;
                cin >> c >> c;
                a[i].a = x[b];
                a[i].b = x[c];
            }
        } ef(c == "owns") {
            a[i].t = 3;
            cin >> c >> c;
            a[i].a = x[b];
            a[i].b = x[c];
        } else {
            cin >> d >> c >> c;
            if(c == "neighbours") {
                a[i].t = 5;
                a[i].a = x[b];
                a[i].b = x[d];
            } else {
                a[i].t = 6;
                cin >> c;
                a[i].a = x[b];
                a[i].b = x[d];
            }
        }
    }
    
    dfs(1);
    
    cout << s << endl;
    
    return 0;
}

void dfs(_ d) {
    if(d > 10) {
        for(_ i = 1; i <= n; ++i) if(a[i].t == 1 && t[a[i].a] != a[i].b) return;
        ef(a[i].t == 2 && t[a[i].a] == a[i].b) return;
        ef(a[i].t == 3 && t[a[i].a] != t[a[i].b]) return;
        ef(a[i].t == 4 && t[a[i].a] == t[a[i].b]) return;
        ef(a[i].t == 5 && abs(t[a[i].a] - t[a[i].b]) != 1) return;
        ef(a[i].t == 6 && abs(t[a[i].a] - t[a[i].b]) == 1) return;
        ++s;
        return;
    }
    for(_ i = 1; i <= 5; ++i) if(!v[(d-1)/5][i]) {
        v[(d-1)/5].flip(i);
        t[d] = i;
        dfs(d+1);
        v[(d-1)/5].flip(i);
    }
    return;
}
