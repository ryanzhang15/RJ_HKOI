#include <immintrin.h>
#include <stdio.h>
#include <string.h>

#pragma G++ optimize("Ofast")
#pragma G++ target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")

int strcount(const char* s, const char* t, unsigned int slen, unsigned int tlen) {
    register int i, rv = 0;
    for(i = 0; i+tlen-1 < slen; ++i) {
        const __m256i x = _mm256_loadu_si256((__m256i const *)(s+i));
        const __m256i y = _mm256_loadu_si256((__m256i const *)t);
        const __m256i z = _mm256_cmpeq_epi8(x, y);
        unsigned bt = _mm256_movemask_epi8(z);
        if((bt & ((1LL<<tlen)-1)) == ((1LL<<tlen)-1)) ++rv;
    }
    return rv;
}

#ifndef ONLINE_JUDGE
char a[30001], b[33];
int main() {
    scanf("%s %s", a, b);
    printf("%d\n", strcount(a, b, strlen(a), strlen(b)));
    return 0;
}
#endif
