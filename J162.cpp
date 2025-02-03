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

map<str, _D> k = {{"PST", -8}, {"MST", -7}, {"EST", -5}, {"GMT", 0}, {"MSK", 3}, {"IST", 5.5}, {"NPT", 5.75}, {"HKT", 8}, {"JST", 9}, {"ACDT", 10.5}};

_ h, m;
str tz1, tz2;
_D shift;

int main(int argc, char * argv[]) {
    
    //actually not that difficult;
    cin >> h >> m >> tz1 >> tz2;
    h += floor(k[tz2]-k[tz1]);
    m += 60*(k[tz2]-k[tz1]-floor(k[tz2]-k[tz1]));
    if(m >= 60) {
        m -= 60;
        h++;
    }
    cout << setw(2) << setfill('0') << (h+24)%24 <<' '<< setw(2) << setfill('0') << m << endl;
    
    return 0;
}
