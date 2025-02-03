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

str in;
char out[] = {'a', 'b', 'c', 'd', 'e', '-', 's', 'h', 'i', 'j'};
_0 out2[500];

int main(int argc, char ** argv) {
    
    out2['a'] = '0';
    out2['b'] = '1';
    out2['c'] = '2';
    out2['d'] = '3';
    out2['e'] = '4';
    out2['-'] = '5';
    out2['s'] = '6';
    out2['h'] = '7';
    out2['i'] = '8';
    out2['j'] = '9';
    getline(cin, in);
    if(in[0] >= '0' && in[0] <= '9') {
        //in = to_string(stoi(in));
        for(char i : in) putchar(out[i-'0']);
    } else {
//        bool st = false;
//        for(char i : in) {
//            if(i != 'a') st = true;
//            if(st)
                for(char i : in) putchar(out2[i]);
        //}
    }
    putchar(10);
    
    return 0;
}
