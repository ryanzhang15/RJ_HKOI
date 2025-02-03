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

constant maxn = 3E4+88;

struct p {
    _ score;
    str name;
} people[maxn];

_ n;

bool cmp(p a, p b);
int main(int argc, char * argv[]) {
    
    cin >> n;
    for(_ i = 0; i < n; i++) cin >> people[i].name >> people[i].score;
    sort(people, people+n, cmp);
    for(_ i = 0; i < n; i++) cout << people[i].name <<' '<< people[i].score << endl;
    
    return 0;
}

bool cmp(p a, p b) {
    if(a.score != b.score) return a.score > b.score;
    else return a.name < b.name;
}
