
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

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define _lllll "%lld%lld%lld%lld%lld"
#define ef else if
const std::string _l = _lin;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

struct school {
    _ no, spc, stdc;
    _D ss;
    bool operator < (const school &b) const {
        return no < b.no;
    }
} a[15];
struct student {
    _D ds;
    _ a[15], s, id;
    bool g;
} s[1005];
_ n, m, d;

bool cmp(student a, student b);
void addStudent(school &h, student &s);
int main(int argc, char ** argv) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) scanf(_ll, &a[i].no, &a[i].spc);
    scanf(_lin, &m);
    for(_ i = 1; i <= m; ++i) {
        scanf(_lin, &s[i].id);
        for(_ j = 1; j <= n; ++j) scanf(_lin, &s[i].a[j]);
        scanf("%Lf", &s[i].ds);
        s[i].s = s[i].ds*100;
    }
    sort(s+1, s+1+m, cmp);
    for(_ i = 1; i <= n; ++i) for(_ j = 1; j <= n; ++j) for(_ k = 1; k <= m && a[j].spc; ++k) if(!s[k].g && s[k].a[i] == a[j].no) addStudent(a[j], s[k]);
    sort(a+1, a+1+n);
    puts("School    No. of students    Average score");
    for(_ i = 1; i <= 42; ++i) putchar('*');
    putchar(10);
    for(_ i = 1; i <= n; ++i) {
        if(!a[i].stdc) continue;
        for(_ i = 1; i <= 2; ++i) putchar(32);
        if(a[i].no < 10) putchar('0');
        printf("%lld", a[i].no);
        printf("%14lld", a[i].stdc);
        printf("%20.2Lf", round(a[i].ss/(_D)a[i].stdc)/100.0);
        for(_ i = 1; i <= 4; ++i) putchar(32);
        putchar(10);
    }
    
    return 0;
}

void addStudent(school &h, student &s) {
    ++h.stdc;
    --h.spc;
    h.ss += s.s;
    s.g = true;
    return;
}

bool cmp(student a, student b) {
    return a.s > b.s;
}
