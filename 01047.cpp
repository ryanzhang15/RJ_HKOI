
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
#include <unordered_map>
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 10+8;

_ n, x, in[maxn];

vector<vector<_> > r (3, vector<_>()), s1 (3, vector<_>()), s2 (3, vector<_>()), s3 (3, vector<_>());
map<vector<vector<_> >, pair<pair<_, _>, vector<vector<_> > > > v;
queue<vector<vector<_> > > q;

void o(vector<vector<_> > c);
int main(int argc, char * argv[]) {

    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &in[i]);
    for(_ i = n; i >= 1; --i) r[in[i]].push_back(i);
    for(_ i = n; i >= 1; --i) s1[0].push_back(i);
    for(_ i = n; i >= 1; --i) s2[1].push_back(i);
    for(_ i = n; i >= 1; --i) s3[2].push_back(i);
    if(s1 == r || s2 == r || s3 == r) exit(0);
    q.push(r);
    for(; !q.empty(); q.pop()) {
        vector<vector<_> > t = q.front();
        for(_ i = 0; i <= 2; ++i) for(_ j = 0; j <= 2; ++j) if(i != j && !t[i].empty() && (t[j].empty() || t[i][t[i].size()-1] < t[j][t[j].size()-1])) {
            vector<vector<_> > c = t;
            c[j].push_back(c[i][c[i].size()-1]);
            c[i].pop_back();
            if(v.count(c)) continue;
            v[c] = make_pair(make_pair(i, j), t);
            if(c == s1 || c == s2 || c == s3) {
                o(c);
                exit(0);
            }
            q.push(c);
        }
    }

    return 0;
}

void o(vector<vector<_> > c) {
    if(c == r) return;
    o(v[c].second);
    printf("%lld %lld\n", v[c].first.first, v[c].first.second);
    return;
}

