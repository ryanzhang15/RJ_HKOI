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

_ n;
str c, t;
stack<str> tag;
bool in, rev;

int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    getchar();
    for(; n--; ) {
        getline(cin, c);
        for(; !tag.empty(); ) tag.pop();
        t.clear();
        in = rev = false;
        for(char i : c) {
            if(in) {
                if(i == '>') {
                    if(t.empty()) goto fail;
                    if(rev) {
                        if(tag.empty() || t != tag.top()) goto fail;
                        tag.pop();
                    } else tag.push(t);
                    t.clear();
                    in = rev = false;
                    continue;
                }
                if((i == '/' && !t.empty()) || (i == '/' && rev)) goto fail;
                if(i == ' ' || i == '<') goto fail;
                if(i == '/') rev = true;
                else t.push_back(i);
            } else {
                if(i == '<') {
                    in = true;
                    continue;
                }
                if(i == '>' || i == '/') goto fail;
            }
        }
        if(in || !tag.empty()) goto fail;
        
        puts("Yes");
        continue;
        
        fail:
        puts("No");
    }
    
    return 0;
}
