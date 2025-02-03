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

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 3E5;
//constant maxn = 5;

struct ints {
    _ head = 0, tail = 0, data[maxn], a = 0;
    void push(_ p) {
        data[head] = p;
        head++;
        head %= maxn;
    }
    void pop() {
        tail++;
        tail %= maxn;
    }
    void itr(_ p) {
        _ i = tail;
        priority_queue<_> pq;
        for(; data[i] != p; i++, i %= maxn) pq.push(data[i]);
        a += pq.size();
        while(!pq.empty()) {
            push(pq.top());
            pq.pop();
            pop();
        }
        pop();
    }
} q;

_ n, a, b[maxn], c;
stack<_> holder;

int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
//    for(_ i = 0; i < n; ++i) {
//        scanf(_lin, &a);
//        holder.push(a);
//    }
//
//    for(; !holder.empty(); holder.pop()) q.push(holder.top());
//
//    for(_ i = n; i >= 1; --i) q.itr(i);
//
//    printf(fs(_l+"\n"), q.a);
    
    for(_ i = 1; i <= n; ++i) scanf(_lin, &b[i]);
    
    c = n;
    for(_ i = n; i >= 1; --i) if(b[i] == c) c--;
    printf(fs(_l+"\n"), c);
    
    return 0;
}


