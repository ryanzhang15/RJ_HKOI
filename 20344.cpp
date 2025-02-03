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

#define fs(str) (str).c_str()
#define _lin "%lli"
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
#define _llllin "%lli%lli%lli%lli"
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

_ n, a[5], t, u, c;

int main(int argc, char * argv[]) {
    
    while(scanf(_lin, &n) && n) {
        a[0] = a[1] = a[2] = a[3] = a[4] = 0;
        for(_ i = 1; i <= n; i++) {
            if(i == 100) ++a[4];
            else {
                t = i / 10;
                u = i % 10;
                if(t == 9) {
                    ++a[2];
                    ++a[4];
                }
                if(t == 8) {
                    a[2] += 3;
                    ++a[3];
                }
                if(t == 7) {
                    a[2] += 2;
                    ++a[3];
                }
                if(t == 6 || t == 4) {
                    ++a[2];
                    ++a[3];
                }
                if(t == 5) ++a[3];
                if(t == 3) a[2] += 3;
                if(t == 2) a[2] += 2;
                if(t == 1) ++a[2];
                if(u == 9) {
                    ++a[0];
                    ++a[2];
                }
                if(u == 8) {
                    a[0] += 3;
                    ++a[1];
                }
                if(u == 7) {
                    a[0] += 2;
                    ++a[1];
                }
                if(u == 6 || u == 4) {
                    ++a[0];
                    ++a[1];
                }
                if(u == 5) a[1]++;
                if(u == 3) a[0] += 3;
                if(u == 2) a[0] += 2;
                if(u == 1) ++a[0];
            }
        }
        printf("%lli: %lli i, %lli v, %lli x, %lli l, %lli c\n", n, a[0], a[1], a[2], a[3], a[4]);
    }
    
    return 0;
}
