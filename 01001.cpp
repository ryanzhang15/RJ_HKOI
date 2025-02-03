
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
#include <random>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _ll "%lld%lld"
#define _lll "%lld%lld%lld"
#define _llll "%lld%lld%lld%lld"
#define _lllll "%lld%lld%lld%lld%lld"
#define ef else if
const std::string _l = _lin;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 5E5+8;

str in, b;
_ p = -1, t[maxn];

void get_line(str &b);
int main(int argc, char ** argv) {
    
    for(; !feof(stdin);) {
        get_line(in);
        if(in.find("\\endinput") != str::npos) break;
    }
    for(_ i = 0; i < in.length(); ++i) {
        if(b.length() == 4) b = b.substr(1);
        b.push_back(in[i]);
        if((i && in[i] == '\n' && in[i-1] == '\n') || b == "\\par" || i == in.length()-1) {
            if(~p) t[p] = -1;
            p = -1;
        }
        if((!i || in[i-1] != '\\') && in[i] == '"') {
            if(~p) {
                t[p] = 1;
                t[i] = 2;
                p = -1;
            } else p = i;
        }
    }
    
    for(_ i = 0; i < in.length(); ++i) {
        if(!~t[i]) continue;
        ef(t[i] == 1) printf("``");
        ef(t[i] == 2) printf("''");
        else putchar(in[i]);
    }
    
    return 0;
}

/*
 
 
 "
 "\par"
 \endinput
 */

void get_line(str &b) {
    for(char c = getchar(); c != '\n'; c = getchar()) b += c;
    b += '\n';
    return;
}

