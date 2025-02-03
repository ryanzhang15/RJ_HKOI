#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

#include <immintrin.h>
#include <stdio.h>
#include <string.h>

int t[100001];
void ncr(int n, int* result) {
    int i, j;
    for (i = 0; i <= n; i++) {
        result[0] = result[i] = 1;
        for (j = 1; j < i; j++) {
            result[j] = (t[j - 1] + t[j]) % 1000000007;
        }
        memcpy(t, result, sizeof t);
    }
}

#ifndef ONLINE_JUDGE
int a[100001];
int main() {
    int n, i;
    scanf("%d", &n);
    ncr(n, a);
    for (i = 0; i <= n; i++) {
        printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
    return 0;
}
#endif