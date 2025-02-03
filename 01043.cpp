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

constant maxn = 1E4+8;
//constant maxn = 9;

class linked_list {
public:
    struct node {
        bool exists;
        _ next, past, v;
    } data[maxn];
    _ s, n, c, k;
    linked_list() {
        scanf(_llin, &n, &k);
        s = n;
        c = 0;
        for(_ i = 0; i < n; ++i) {
            data[i].exists = true;
            data[i].v = i;
            data[i].past = i-1;
            data[i].next = i+1;
        }
        data[n-1].next = 0;
        data[0].past = n;
    }
    void remove(_ k) {
        --s;
        data[data[k].past].next = data[k].next;
        data[data[k].next].past = data[k].past;
        data[k].exists = false;
    };
    _ findExisting() {
        for(_ i = 0; i < n; ++i) if(data[i].exists) return i;
        return -1;
    }
    void walkAndRemove() {
        for(_ i = 0; i < (k-1)%s; ++i) c = data[c].next;
        _ d = c;
        c = data[c].next;
        remove(d);
    }
};

linked_list l;
int main(int argc, char * argv[]) {
    
    //I will do a loop linked list... dk why, but it will work
    while(l.s > 1) l.walkAndRemove();
    printf(fs(_l+"\n"), l.findExisting());
    
    return 0;
}

