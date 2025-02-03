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

struct frequency {
    _ num;
    char letter;
} jones[300];

bool done[400];
str a, b, c;
_ cnt;

bool cmp(frequency a, frequency b);
int main(int argc, char * argv[]) {
    
    cin >> a >> b;
    c = a;
    for(char i : a) {
        if(done[i]) continue;
        jones[cnt++] = {count(a.begin(), a.end(), i), i};
        done[i] = true;
    }
    sort(jones, jones+cnt, cmp);
    
    for(_ i = 0; i < cnt; i++)
        for(_ j = 0; j < a.length(); j++)
            if(a[j] == jones[i].letter) c[j] = b[i];
    
    cout << c << endl;
    
    return 0;
}

bool cmp(frequency a, frequency b) {
    return a.num > b.num;
}
