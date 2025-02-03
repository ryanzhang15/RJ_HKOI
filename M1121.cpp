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

stack<_> ch;
priority_queue<_> q;
_ n, c, ctr = 1;

int main(int argc, char * argv[]) {
    
    scanf(fs(_l), &n);
    for(; n--; ) {
        scanf(fs(_l), &c);
        q.push(c);
    }
    for(; q.size()>=ctr; ctr++) {
        for(_ i = 0; i < ctr; i++) {
            _ a = q.top()-1; q.pop();
            if(a) ch.push(a);
        }
        while(!ch.empty()) {
            q.push(ch.top());
            ch.pop();
        }
    }
    
    printf(fs(_l+"\n"), ctr-1);
    
    return 0;
}

