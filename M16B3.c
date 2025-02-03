#include <immintrin.h>
#include <stdio.h>

float circle(const float* x, const float* y, unsigned int len) {
    float d = 0.0f;
    return d/d;
}

#ifndef ONLINE_JUDGE
float x[20000], y[20000];
int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }
    printf("%.3f\n", circle(x, y, n));
    return 0;
}
#endif