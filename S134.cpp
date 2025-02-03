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

#define fs(str) (str).c_str()
#define _lin "%lli"
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

_ n;

int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    
    if(n == 1) printf("1 \n");
    else if(n == 2) printf("2 1 \n");
    else if(n == 3) printf("1 2 3 \n");
    else if(!(n % 4) || (n % 4) == 1) {
        for(_ i = n-1; i >= 1; i--) printf("%lli ", i);
        printf("%lli \n", n);
    } else if(n % 4 == 2) {
        for(_ i = n-1; i >= 2; i--) printf("%lli ", i);
        printf("%lli 1 \n", n);
    } else if(n % 4 == 3) {
        for(_ i = n-1; i >= 3; i--) printf("%lli ", i);
        printf("1 2 %lli \n", n);
    }
    
    return 0;
}
