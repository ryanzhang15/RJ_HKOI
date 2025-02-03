
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
#define _lin "%lld"
#define _llin "%lld%lld"
#define _lllin "%lld%lld%lld"
#define _llllin "%lld%lld%lld%lld"
std::string _l = "%lld";
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

_ n, ptr;
str c;

int main(int argc, char * argv[]) {
    
    cin >> n;
    for(_ i = 1; i <= n; ++i, ptr = 0) {
        cout << "Case #" << i << ": ";
        cin >> c;
        if(next_permutation(c.begin(), c.end())) cout << c << endl;
        else {
            sort(c.begin(), c.end());
            for(; c[ptr] == '0'; ) ++ptr;
            cout << c[ptr];
            for(_ i = 1; i <= ptr+1; ++i) cout << '0';
            cout << c.substr(ptr+1) << endl;
        }
    }
    
    return 0;
}

