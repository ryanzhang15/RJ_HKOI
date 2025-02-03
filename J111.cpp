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
#define _llin "%lli%lli"
#define _lllin "%lli%lli%lli"
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";
std::string _c = "%c";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

struct node {
    _ c = 0;
    char l;
} f[30];

_ k, s, p;
char x;
str m;

bool cmp(node a, node b);
int main(int argc, char * argv[]) {
        
    scanf(fs(_l+" "+_c), &k, &x);
    getchar_unlocked();
    getline(cin, m);
    for(_ i = 0; i <= 25; i++) f[i].l = 'a' + i;
    for(char i : m) {
        i = tolower(i);
        if(!(i >= 'a' && i <= 'z')) continue;
        f[i-'a'].c++;
    }
    
    sort(f, f+26, cmp);
    
    s = -(f[k-1].l-x);
    
    for(char &i : m) {
        if(!(i >= 'a' && i <= 'z') && !(i >= 'A' && i <= 'Z')) continue;
        if(i >= 'A' && i <= 'Z') {
            p = ((i-'A')+s+26)%26;
            i = p + 'A';
        } else {
            p = ((i-'a')+s+26)%26;
            i = p + 'a';
        }
    }
    
    cout << m << endl;
    
    return 0;
}

bool cmp(node a, node b) {
    return a.c > b.c;
}
