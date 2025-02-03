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
std::string _f = "%llf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxsqrtn = 8E4+8;
 
_ n, r, l;
bool used[maxsqrtn];

int main(int argc, char * argv[]) {
    
    //while(true) {
        l = r = 0;
        scanf(_lin, &n);
        for(_ i = 1; i < ceil(sqrt(n)); ++i) {
            if(!(n%i)) r+=2;
            if(i > 1 && !((n-1+i)%(2*i-1))) {
                if(used[i]) continue;
                if(used[i] = true);
                if((n-1+i)/(2*i-1) < sqrt(n)) used[(n-1+i)/(2*i-1)] = true;
                l++;
                if((n-1+i)/(2*i-1) != i) l++;
            }
        }
        if(sqrt(n) == floor(sqrt(n)) && !(n%(_)round(sqrt(n)))) r++;
        
        printf(fs(_l+" "+_l+"\n"), r, l);
    //}
    
    return 0;
}
