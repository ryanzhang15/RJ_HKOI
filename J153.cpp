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
#include <queue>
#include <list>
#include <set>

#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lli"
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
#define _llllin "%lli%lli%lli%lli"
std::string _l = "%lli";
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

str o, t, f;
bool ins;

int main(int argc, char * argv[]) {
    
    cin >> o;
    reverse(o.begin(), o.end());
    cin >> t;
    for(char i : t) {
        if(i == 'D' && !o.empty()) o.pop_back();
        else if(i == 'I') ins = !ins;
        else if(i != 'D') {
            if(ins && !o.empty()) o.pop_back();
            f += i;
        }
    }
    
    reverse(o.begin(), o.end());
    cout << f << o << endl;
    
    return 0;
}
