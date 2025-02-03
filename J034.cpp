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

struct building {
    _ x1, x2, y1, y2;
    void getBuilding() {
        scanf(_llllin, &x1, &y1, &x2, &y2);
        return;
    }
} a, b;

_D s = 1E12;
pair<_, _> coords[10];

_D dist(_ x1, _ x2, _ y1, _ y2);
int main(int argc, char * argv[]) {
    
    a.getBuilding();
    b.getBuilding();
    if((a.x1 >= b.x1 && b.x2 >= a.x1) || (a.x2 >= b.x1 && b.x2 >= a.x1)) s = min(abs(a.y1-b.y2), abs(a.y2-b.y1));
    if((a.y1 >= b.y1 && b.y2 >= a.y1) || (a.y2 >= b.y1 && b.y2 >= a.y1)) s = min(abs(a.x1-b.x2), abs(a.x2-b.x1));
    
    if(s == 1E12) {
        coords[1] = {a.x1, a.y1};
        coords[2] = {a.x2, a.y2};
        coords[3] = {a.x1, a.y2};
        coords[4] = {a.x2, a.y1};
        coords[5] = {b.x1, b.y1};
        coords[6] = {b.x2, b.y2};
        coords[7] = {b.x1, b.y2};
        coords[8] = {b.x2, b.y1};
        for(_ i = 1; i <= 4; ++i) for(_ j = 5; j <= 8; ++j) s = min(s, dist(coords[i].first, coords[j].first, coords[i].second, coords[j].second));
    }
    
    printf("%.3Lf\n", s);
    
    return 0;
}

_D dist(_ x1, _ x2, _ y1, _ y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
