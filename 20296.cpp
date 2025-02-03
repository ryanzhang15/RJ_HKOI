
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

constant maxn = 300+8;

str s, n, t;
_ tg;
bool v[maxn];

void dfs();
int main(int argc, char * argv[]) {
    
    cin >> tg >> n;
    dfs();
    if(s.empty()) cout << "no solution" << endl;
    else cout << s << endl;
    
    return 0;
}

void dfs() {
    if(t.length() == 5) {
        _ ttg = 0;
        for(_ i = 1; i <= 5; ++i) {
            if(i & 1) ttg += pow(t[i-1]-'A'+1, i);
            else ttg -= pow(t[i-1]-'A'+1, i);
        }
        if(ttg == tg && (s.empty() || s < t)) s = t;
        return;
    }
    for(char i : n) if(!v[i]) {
        v[i] = true;
        t += i;
        dfs();
        t.pop_back();
        v[i] = false;
    }
    return;
}
