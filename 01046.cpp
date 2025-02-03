
#include <cstdio>
#include <iostream>
#include <cstdlib>
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
#define _lin "%lld"
#define _llin "%lld%lld"
#define _lllin "%lld%lld%lld"
#define _llllin "%lld%lld%lld%lld"
std::string _l = "%lld";
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

_ n;
void moveLeft(_ n);
void moveRight(_ n);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    moveRight(n);
    
    return 0;
}

void moveRight(_ n) {
    if(!n) return;
    moveRight(n-1);
    puts("0 1");
    moveLeft(n-1);
    puts("1 2");
    moveRight(n-1);
    return;
}

void moveLeft(_ n) {
    if(!n) return;
    moveLeft(n-1);
    puts("2 1");
    moveRight(n-1);
    puts("1 0");
    moveLeft(n-1);
    return;
}
