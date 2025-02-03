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

_ n, v[] = {1, 5, 10, 25, 50}, c;

void dfs(_ a, _ p);
int main(int argc, char * argv[]) {
    
    // a dfs will do
    scanf(_lin, &n);
    dfs(0, 0);
    if(c == 1) printf("There is only 1 way to produce %lli cents change.\n", n);
    else printf("There are %lli ways to produce %lli cents change.\n", c, n);
    
    return 0;
}

void dfs(_ a, _ p) {
    if(a > n) return;
    if(a == n) {
        c++;
        return;
    }
    for(_ i = p; i < 5; i++) dfs(a + v[i], i);
    return;
}
