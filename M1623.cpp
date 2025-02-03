#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E2+8;

_ n, k;
bool a[maxn][maxn];

void solveD(_ k);
void solveL(_ k);
int main() {
	
	scanf("%lld %lld", &n, &k);
	if(n == 2 && k == 3) {
		puts("No solution");
		exit(0);
	}
	if(k) {
		if(k < n) {
			puts("No solution");
			exit(0);
		} ef(k <= (n*n)>>1) solveL(k);
		else {
			solveL(k>>1);
			solveD((k+1)>>1);
		}
	}
	for(_ i = 1; i <= n; ++i, putchar(10)) for(_ j = 1; j <= n; ++j) putchar(a[i][j] ? 'B' : 'X');
	
	return 0;
}

void solveL(_ k) {
	if(k & 1) {
		if(k < n<<1) {
			k -= n;
			a[n][2] = true;
			for(_ i = (n>>1)+1, j = (n>>1)+1, l = n-1; k; --i, ++j, l -= 2) if(k >= l) {
				k -= l;
				a[i][j] = true;
			}
		} else {
			k -= (n<<1)-1;
			a[n][2] = a[n][4] = true;
			if(k >= n-2) {
				k -= n-2;
				a[(n>>1)+1][(n>>1)+1] = true;
			}
			for(_ i = (n>>1)+2, j = n>>1, x = n>>1, y = (n>>1)+2, l = n-4; l >= 4; ++i, --j, --x, ++y, l -= 2) {
				if(k >= l) {
					k -= l;
					a[i][j] = true;
				}
				if(k >= l) {
					k -= l;
					a[x][y] = true;
				}
			}
			if(k) a[3][n-1] = true;
		}
	} else {
		a[1][1] = true;
		k -= n;
		for(_ i = n>>1; i >= 2; --i) {
			if(k >= (i-1)<<1) {
				k -= (i-1)<<1;
				a[i][i] = true;
			}
			if(k >= (i-1)<<1) {
				k -= (i-1)<<1;
				a[n-i+1][n-i+1] = true;
			}
		}
	}	
	return;
}

void solveD(_ k) {
	if(k & 1) {
		if(k < n<<1) {
			k -= n;
			a[n][n-1] = true;
			for(_ i = (n>>1)+1, j = (n>>1), l = n-1; k; --i, --j, l -= 2) if(k >= l) {
				k -= l;
				a[i][j] = true;
			}
		} else {
			k -= (n<<1)-1;
			a[n][n-1] = a[n][n-3] = true;
			if(k >= n-2) {
				k -= n-2;
				a[(n>>1)+1][n>>1] = true;
			}
			for(_ i = n>>1, j = (n>>1)-1, x = (n>>1)+2, y = (n>>1)+1, l = n-4; l >= 4; --i, --j, ++x, ++y, l -= 2) {
				if(k >= l) {
					k -= l;
					a[i][j] = true;
				}
				if(k >= l) {
					k -= l;
					a[x][y] = true;
				}
			}
			if(k) a[3][2] = true;
		}
	} else {
		a[1][n] = true;
		k -= n;
		for(_ i = n>>1; i >= 2; --i) {
			if(k >= (i-1)<<1) {
				k -= (i-1)<<1;
				a[n-i+1][i] = true;
			}
			if(k >= (i-1)<<1) {
				k -= (i-1)<<1;
				a[i][n-i+1] = true;
			}
		}
	}
	return;
}