
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

typedef pair<_, _> _p;

_ n, p = 1, sp = 1;
char c, l;
vector<_p> y, w;

int main() {
    
    scanf("%lld", &n);
    for(c = getchar(); c != 'W' && c != 'Y' && c != 'G'; ) c = getchar();
    l = c;
    if(c == 'G') {
        ++p;
        ++sp;
    }
    for(_ i = 2, c = n == 1 ? 'G' : getchar(); i <= n+1; ++i, c = i == n+1 ? 'G' : getchar()) {
        if(c == 'G' && l == 'G') {
            sp = i+1;
            p = i+1;
            continue;
        }
        if(c != l && l != 'G') {
            //wrap it up
            if(l == 'Y') y.push_back(make_pair(p, i-1));
            else w.push_back(make_pair(p, i-1));
            p = i+(c=='G');
        }
        if(c == 'G') {
            if(y.size() >= w.size()) {
                for(vector<_p>::iterator j = w.begin(); j != w.end(); ++j) printf("Grow %lld %lld\n", (*j).first, (*j).second);
                printf("Grow %lld %lld\n", sp, i-1);
            }
            else {
                for(vector<_p>::iterator j = y.begin(); j != y.end(); ++j) printf("Blow %lld %lld\n", (*j).first, (*j).second);
                printf("SuperGrow %lld %lld\n", sp, i-1);
            }
            y.clear();
            w.clear();
            sp = i+1;
        }
        l = c;
    }
    
finish:
    puts("Finish");
    
    return 0;
}
