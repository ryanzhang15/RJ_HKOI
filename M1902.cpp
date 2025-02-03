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

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 10 + 10;

struct t {
    _ hr, min;
} et, cur, z[maxn][2], ab[maxn][2], bt[2], res[2];
_ n, m, ans = -1;

t slt(t a, t b);
t lgt(t a, t b);
_ timeDifference(t a[2], t b[2]);
void activityIn(_ num, t (&person)[maxn][2]);
int main(int argc, char * argv[]) {
    
    cin >> n; getchar();
    activityIn(n, z);
    cin >> m; getchar();
    activityIn(m, ab);

    for(_ i = 1; i <= n+1; ++i)
        for(_ j = 1; j <= m+1; ++j) {
            _ a = timeDifference(z[i], ab[j]);
            if(a > ans) {
                memcpy(bt, res, sizeof(res));
                ans = a;
            }
        }

    if(ans == -1) cout << "SAD" << endl;
    else printf("%02lli:%02lli-%02lli:%02lli extramarital affair ,,,ohno,,,\n", bt[0].hr, bt[0].min, bt[1].hr, bt[1].min);
    
    return 0;
}

void activityIn(_ num, t (&person)[maxn][2]) {
    et = {7, 0};
    str parse;
    for(_ i = 1; i <= num; ++i) {
        getline(cin, parse);
        cur.hr = 10*(parse[0]-'0') + parse[1]-'0'; cur.min = 10*(parse[3]-'0') + parse[4]-'0';
        person[i][0] = et; person[i][1] = cur;
        et.hr = 10*(parse[6]-'0') + parse[7]-'0'; et.min = 10*(parse[9]-'0') + parse[10]-'0';
    }
    person[num+1][0] = et; person[num+1][1] = {23, 0};
}

_ timeDifference(t a[2], t b[2]) {
    t st = lgt(a[0], b[0]);
    t et = slt(a[1], b[1]);
    res[0] = st; res[1] = et;
    if(et.hr < st.hr || ((et.hr == st.hr) && (et.min < st.min)) || (et.hr == st.hr && et.min == st.min)) return -2;
    return 60*(et.hr - st.hr) + et.min - st.min;
}

t lgt(t a, t b) {
    if(a.hr == b.hr) {
        if(a.min > b.min) return a;
        else return b;
    } else if(a.hr > b.hr) return a;
    else return b;
}

t slt(t a, t b) {
    if(a.hr == b.hr) {
        if(a.min < b.min) return a;
        else return b;
    } else if(a.hr < b.hr) return a;
    else return b;
}
