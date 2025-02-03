#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 5E5+8;

struct linked_list_node {
    _ v, next, back;
    bool ex;
} a[maxn];
struct pq_node {
    _ df, a, b, aa, ab;
    bool operator < (const pq_node &y) const {
        if(df != y.df) return df > y.df;
        return min(aa, ab) > min(y.aa, y.ab);
    }
};
priority_queue<pq_node> q;
_ n;

void pq_insert(_ x, _ y);
void remove_node(_ x);
int main() {
    
    scanf("%lld", &n);
    for(_ i = 1; i <= n; ++i) scanf("%lld", &a[i].v);
    for(_ i = 1; i <= n-1; ++i) a[i].next = i+1;
    a[n].next = 1;
    for(_ i = 2; i <= n; ++i) a[i].back = i-1;
    a[1].back = n;
    for(_ i = 1; i <= n; ++i) a[i].ex = true;
    for(_ i = 1; i <= n; ++i) pq_insert(i, a[i].next);
    for(; --n; ) {
        pq_node t;
        for(;; q.pop()) {
            t = q.top();
            //printf("df: %lld a: %lld b: %lld aa: %lld ab %lld\n", t.df, t.a, t.b, t.aa, t.ab);
            if(a[t.a].ex && a[t.b].ex) break;
        }
        //printf("CHOSEN--> df: %lld a: %lld b: %lld aa: %lld ab %lld\n", t.df, t.a, t.b, t.aa, t.ab);
        printf("%lld ", min(t.aa, t.ab));
        remove_node(t.aa < t.ab ? t.a : t.b);
    }
    putchar(10);
    
    return 0;
}

void remove_node(_ x) {
    a[x].ex = false;
    pq_insert(a[x].back, a[x].next);
    a[a[x].back].next = a[x].next;
    a[a[x].next].back = a[x].back;
    return;
}

void pq_insert(_ x, _ y) {
    q.push((pq_node){abs(a[x].v-a[y].v), x, y, a[x].v, a[y].v});
}
