
#include <cstring>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <iostream>
#include <fstream>
#include <cstring>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef long double _D;
typedef pair<_, _> _p;
typedef const long long constant;

inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f = -1;
    for(; ch >= '0' && ch <= '9'; ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline void AC();
int main() {
    
//#define MULTIPLE_TESTCASES
#ifdef MULTIPLE_TESTCASES
    _ tc = read();
    for(; tc--; ) AC();
#else
    AC();
#endif
    
    return 0;
}



// ------ separation line ------



constant maxn = 1E6+8;

_ w, n, a[maxn], x, y, q, p;
vector<_p> s1, s2;

inline void AC() {
    
    w = read();
    n = read();
    for(_ i = 1; i <= n; ++i) a[read()] = i;
    x = read();
    y = read();
    for(_ i = 1; i <= w; ++i) if(a[i] == x) {
        p = i;
        break;
    }
    for(;;) {
        s1.push_back(make_pair(a[p], p));
        if(y) {
            if(p == w) break;
            if(p == 1) {
                y = false;
                continue;
            }
            if(!a[p-1]) {
                swap(a[p], a[p-1]);
                --p;
            } else --p;
        } else {
            if(p == w) {
                y = true;
                continue;
            }
            if(!a[p+1]) {
                swap(a[p], a[p+1]);
                ++p;
            } else ++p;
        }
    }
    for(;;) {
        if(y) {
            if(p == 1) y = false;
            else {
                if(!a[p-1]) {
                    swap(a[p], a[p-1]);
                    --p;
                } else --p;
            }
        } else {
            if(p == w) {
                y = true;
            } else {
                if(!a[p+1]) {
                    swap(a[p], a[p+1]);
                    ++p;
                } else ++p;
            }
        }
        s2.push_back(make_pair(a[p], p));
        if(y && p == w) break;
    }
    q = read();
    for(; q--; ) {
        x = read();
        if(x <= s1.size()-1) printf("%lld %lld\n", s1[x].second, s1[x].first);
        else {
            x -= s1.size();
            printf("%lld %lld\n", s2[x%s2.size()].second, s2[x%s2.size()].first);
        }
    }
    
    
    return;
}



