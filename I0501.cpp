#ifdef __cplusplus
extern "C" {
#endif
int isDivisibleBy(int M);
int play(int N);
#ifdef __cplusplus
}
#endif

#include <bits/stdc++.h>
typedef long long _;

const long long maxn = 1E6+8;
const long long maxp = 8E4+8;

std::bitset<maxn> inp;
_ pc, p[maxp];

int play(int N) {
    inp[0] = inp[1] = true;
    for(_ i = 2; i <= N; ++i) {
        if(!inp[i]) p[++pc] = i;
        for(_ j = 1; j <= pc; ++j) {
            if(i * p[j] > N) break;
            inp[i * p[j]] = true;
            if(!(i % p[j])) break;
        }
    }
    _ rv = 1;
    for(_ i = 1; i <= pc; ++i) {
        if(rv * p[i] > N) break;
        _ c = 1;
        for(_ j = 1; c*p[i]*rv <= N && isDivisibleBy(c*p[i]); ) c *= p[i];
        rv *= c;
    }
    return rv;
}

