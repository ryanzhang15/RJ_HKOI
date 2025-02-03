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

constant maxn = 3E5; //They DIDNT GIVE ME A MAXNNNN

str p[maxn];
_ n, cnt;

int main(int argc, char * argv[]) {
    
    cin >> n; getchar();
    while(n--) {
        str a; getline(cin, a);
        _ as = 0;
        for(char i : a.substr(9)) as += i;
        if(as == stoll(a.substr(5, 4))) p[cnt++] = a;
        else n++;
    }
    
    sort(p, p+cnt);
    for(_ i = 0; i < cnt; i++) cout << p[i].substr(9);
    cout << endl;
    
    return 0;
}
