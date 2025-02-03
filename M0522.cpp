#include <bits/stdc++.h>

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 7+8;

_ a[maxn], b[maxn], mbmc;

void match();
void rotateY();
void rotateX();
int main() {
    
    for(_ i = 1; i <= 6; ++i) scanf("%lld", &a[i]);
    for(_ i = 1; i <= 6; ++i) scanf("%lld", &b[i]);
    for(_ i = 1; i <= 6; ++i) mbmc += !!b[i];
    
    for(_ k = 1; k <= 4; ++k, rotateY()) for(_ i = 1; i <= 4; ++i, rotateX()) for(_ j = 1; j <= 4; ++j, rotateY()) match();
    
    return 0;
}

void rotateX() {
    //2 -> 3, 3 -> 4, 4 -> 5, 5 -> 2
    _ sv = a[2];
    a[2] = a[5];
    a[5] = a[4];
    a[4] = a[3];
    a[3] = sv;
    return;
}

void rotateY() {
    //4 -> 6, 6 -> 2, 2 -> 1, 1 -> 4
    _ sv = a[4];
    a[4] = a[1];
    a[1] = a[2];
    a[2] = a[6];
    a[6] = sv;
    return;
}

void match() {
    _ mc = 0;
    for(_ i = 1; i <= 6; ++i) if(a[i] == b[i]) ++mc;
    if(mc == mbmc) {
        for(_ i = 1; i <= 6; ++i) printf("%lld ", a[i]);
        putchar(10);
        exit(0);
    }
    return;
}




