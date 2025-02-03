
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
#include <numeric>

#define fs(str) (str).c_str()
#define l "%lld"
#define ll "%lld%lld"
#define lll "%lld%lld%lld"
#define llll "%lld%lld%lld%lld"
std::string _l = l;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

_ n, k, m;
bool flag;

void dfs(_ s, _ d, _ p);
int main(int argc, char * argv[]) {
    
    scanf(lll, &n, &k, &m);
    dfs(0, 1, 0);
    if(!flag) printf("NO SOLUTION");
    putchar(10);
    
    return 0;
}

void dfs(_ s, _ d, _ p) {
    if(d > k) {
        if(s == n) flag = true;
        return;
    }
    for(_ i = p; pow(i, m) <= n; ++i) {
        dfs(s + pow(i, m), d+1, i);
        if(flag) {
            printf(fs(_l+" "), i);
            return;
        }
    }
    return;
}
