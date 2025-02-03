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
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <algorithm>
#include <numeric>
#include <random>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, k, q, head;
struct node {
    _ v, next, pre, lm, rm;
} a[maxn];
char ch;
bool tk;

int main() {
    //freopen("/Users/ryanzhang/Desktop/debug/data.in", "r", stdin);
    //freopen("/Users/ryanzhang/Desktop/debug/other.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &k, &q);
    for(_ i = 2; i <= n; ++i) a[i].pre = i-1;
    for(_ i = 1; i <= n-1; ++i) a[i].next = i+1;
    a[1].pre = n;
    a[n].next = 1;
    _ p = 1;
    for(_ j = k; j <= n; ++p, ++j) a[p].v = j;
    for(_ j = 1; j <= k-1; ++p, ++j) a[p].v = j;
    head = 1;
    scanf(" ");
    for(; q--; ) {
        if(~a[head].v && ~a[a[head].pre].v) {
            a[head].lm = a[a[head].pre].lm;
            a[head].rm = a[a[head].pre].rm;
        }
        ch = getchar();
        if(ch == 'T') {
            printf("%lld\n", a[head].v);
            if(~a[head].v) {
                a[head].v = -1;
                a[a[head].next].rm = a[head].rm;
                if(!tk) a[a[head].next].rm = head;
                a[a[head].lm].rm = head;
                a[a[head].next].lm = a[head].next;
            }
            tk = true;
            head = a[head].next;
        } ef(ch == 'B' && tk) {
            if(!~a[head].v) {
                head = a[head].next;
                continue;
            }
            _ x = a[head].rm;
            if(a[head].lm == a[a[head].rm].next) {
                a[head].lm = head;
                a[head].rm = x;
            } else {
                if(~a[a[head].pre].v) {
                    a[head].lm = head;
                    a[a[a[head].pre].lm].rm = x;
                }
                if(~a[a[x].next].v && a[a[x].next].lm != head) {
                    a[a[x].next].lm = head;
                    a[head].rm = a[a[x].next].rm;
                } ef(!~a[a[x].next].v) a[head].rm = a[x].next;
            }
            if(x != a[head].pre) {
                a[a[x].pre].next = a[x].next;
                a[a[x].next].pre = a[x].pre;
                a[x].pre = a[head].pre;
                a[x].next = head;
                a[a[head].pre].next = x;
                a[head].pre = x;
            }
        } ef(ch == 'N') head = a[head].next;
    }
    
    return 0;
}




