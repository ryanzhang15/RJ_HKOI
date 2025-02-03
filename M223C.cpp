#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <unordered_map>
#include <bitset>
#include <string>
#include <stack>
#include <unordered_set>
#include <vector>
#include <map>

#define ef else if
#define mp(x, y) make_pair(x, y)
#define pr(x, y) pair< x, y >

using namespace std;

typedef long long _;
typedef long long ll;
typedef int _0;
typedef double _D;
typedef string str;
typedef const long long constant;

inline _ read() {
    _ x = 0, d = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') d *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*d;
}

inline void read(str & a) {
    a.clear();
    char ch = getchar();
    for(; ch == ' ' || ch == '\n'; ) ch = getchar();
    for(; !(ch == ' ' || ch == '\n' || ch == EOF); ch = getchar()) a += ch;
    return;
}

inline void read(char * a) {
    char ch = getchar();
    for(; ch == ' ' || ch == '\n'; ) ch = getchar();
    for(; !(ch == ' ' || ch == '\n' || ch == EOF); ch = getchar()) {
        *a = ch;
        ++a;
    }
    *a = '\0';
    return;
}

int n,fnt,bck,top,bot,l,r;
string s;

int main() {
    n=read(),top=read(),bot=read(),l=read(),r=read(),fnt=read(),bck=read();
    read(s);
    for(int i=0;i<n;i++){
        if(s[i]=='L'){
            swap(r,top);
            swap(top,l);
            swap(l,bot);
        }
        if(s[i]=='R'){
            swap(r,top);
            swap(r,bot);
            swap(l,bot);
        }
        if(s[i]=='U'){
            swap(fnt,top);
            swap(top,bck);
            swap(bck,bot);
        }
        if(s[i]=='D'){
            swap(fnt,top);
            swap(fnt,bot);
            swap(bot,bck);
        }
    }
    cout<<top<<" "<<bot<<" "<<l<<" "<<r<<" "<<fnt<<" "<<bck;
    return 0;
}
