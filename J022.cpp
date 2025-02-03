
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
typedef double _D;
typedef string str;
typedef const long long constant;

char N;
_ n;

_ value(char a);
void dfs(str p, _ letter, bool first);
int main(int argc, char * argv[]) {
   
    cin >> N;
    n = value(N);
    
    dfs("", 1, true);
    
    return 0;
}

void dfs(str p, _ letter, bool first) { // does it count as dfs? idk its recursion so
    for(_ i = letter; i <= n; i++) {
        if(5*letter <= 4*i || first) dfs(p + (char)(i-1+'A'), i, false);
    }
    if(p.length() >= 2 && p[p.length()-1] == N) cout << p << endl;
    return;
}

_ value(char a) {
    return a - 'A' + 1;
}
