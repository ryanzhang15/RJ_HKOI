
#include <immintrin.h>
#include <stdio.h>

int sum(const int* array, unsigned int len) {
    if(len < 20) {
        int s = 0;
        for(int i = 0; i < len; ++i) s += array[i];
        return s;
    }
    register int i = 0, s = 0;
    //for(; (unsigned long)(array+i) & 31; ++i) s += array[i];
    __m256i sm = _mm256_loadu_si256((void *)(array+i));
    __m256i sm2 = _mm256_loadu_si256((void *)(array+i+8));
    i += 16;
    for (; i+16 < len; i += 16) {
        const __m256i x = _mm256_loadu_si256((void *)(array+i));
        sm = _mm256_add_epi32(sm, x);
        const __m256i y = _mm256_loadu_si256((void *)(array+i+8));
        sm2 = _mm256_add_epi32(sm2, y);
    }
    sm = _mm256_add_epi32(sm, sm2);
    sm = _mm256_hadd_epi32(sm, sm);
    sm = _mm256_hadd_epi32(sm, sm);
    s = _mm256_extract_epi32(sm, 0);
    s += _mm256_extract_epi32(sm, 4);
    for(; i < len; ++i) s += array[i];
    return s;
}


