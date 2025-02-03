

#ifndef __cplusplus
#include <stdbool.h>
#endif
#ifdef __cplusplus
extern "C" {
#endif
void add_element(char x[]);
void compile_set();
bool check_element(char x[]);
void restore_permutation(int n, int w, int r, int result[]);
#ifdef __cplusplus
}
#endif


#include <vector>
#include <cstdio>

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 128+8;

char a[maxn];
_ rr[maxn], nn, cnt;
vector<_> v;

//void compile_set() {}
//void add_element(char x[]) {
//    printf("%s\n", x);
//    return;
//}
//bool check_element(char x[]) {
//    printf("?? %s\n", x);
//    _ rd;
//    scanf("%lld", &rd);
//    return !!rd;
//}

void permutation(_ l, _ r, vector<_> ps);
void insertion(_ l, _ r);
void restore_permutation(int n, int w, int r, int result[]) {
    nn = n;
    insertion(1, n);
    compile_set();
    for(_ i = 1; i <= n; ++i) v.push_back(i);
    permutation(1, n, v);
    for(_ i = 1; i <= n; ++i) result[i-1] = (int)rr[i]-1;
//    for(_ i = 1; i <= n; ++i) printf("%lld ", rr[i]-1);
//    putchar(10);
    return;
}

void insertion(_ l, _ r) {
    if(l == r) return;
    for(_ i = l-1; i >= 1; --i) a[i] = '1';
    for(_ i = r+1; i <= nn; ++i) a[i] = '1';
    for(_ i = l; i <= r; ++i) a[i] = '0';
    for(_ i = l; i <= l+((r-l)>>1); ++i) {
        a[i] = '1';
        add_element(a+1);
        a[i] = '0';
    }
    _ md = (l+r)>>1;
    insertion(l, md);
    insertion(md+1, r);
    return;
}

void permutation(_ l, _ r, vector<_> ps) {
    if(l == r) {
        rr[ps[0]] = l;
        return;
    }
    vector<_> lv, rv;
    for(_ i = 1; i <= nn; ++i) a[i] = '1';
    for(_ i : ps) a[i] = '0';
    for(_ i : ps) {
        a[i] = '1';
        if(check_element(a+1)) lv.push_back(i);
        else rv.push_back(i);
        a[i] = '0';
    }
    _ md = (l+r)>>1;
    permutation(l, md, lv);
    permutation(md+1, r, rv);
    return;
}

