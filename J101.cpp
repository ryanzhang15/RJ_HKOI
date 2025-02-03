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
#include <queue>
#include <list>
#include <set>

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

_ n, s;
pair<_, _> p[10] = {{-1, -1}, {2, 1}, {2, 2}, {2, 3}, {3, 1}, {3, 2}, {3, 3}, {4, 1}, {4, 2}, {4, 3}}, c;

_ dis(pair<_, _> a, pair<_, _> b);
int main(int argc, char * argv []) {
    
    c = p[5];
    for(; !feof(stdin); ) {
        scanf("%1lld", &n);
        if(n) {
            s += dis(c, p[n]);
            c = p[n];
        } else {
            _ disa = dis({1, 1}, c), disb = dis({1, 2}, c);
            if(disa < disb) {
                s += disa;
                c = {1, 1};
            } else {
                s += disb;
                c = {1, 2};
            }
        }
    }
    
    printf(fs(_l+"\n"), s);
    
    return 0;
}

_ dis(pair<_, _> a, pair<_, _> b) {
    return abs(a.first-b.first)+abs(a.second-b.second);
}
