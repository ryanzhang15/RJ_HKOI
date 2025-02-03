#pragma GCC optimize("Ofast")

#include <immintrin.h>
#include <stdio.h>
#include <math.h>

float correl(const float* x, const float* y, unsigned int len) {
	int i;
	float sx = 0, sy = 0, sxx = 0, syy = 0, sxy = 0;
	for (i = 0; i < len; i++) {
		sx += x[i];
		sy += y[i];
		sxy += x[i] * y[i];
		sxx += x[i] * x[i];
		syy += y[i] * y[i];
	}
	float numer = len * sxy - sx * sy;
	float denom = sqrt(len * sxx - sx * sx) * sqrt(len * syy - sy * sy);
	if(denom == 0) return 1;
	return numer / denom;
}

#ifndef ONLINE_JUDGE
float x[100000], y[100000];
int main() {
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%f", &x[i]);
	}
	for (i = 0; i < n; i++) {
		scanf("%f", &y[i]);
	}
	printf("%.4f\n", correl(x, y, n));
	return 0;
}
#endif