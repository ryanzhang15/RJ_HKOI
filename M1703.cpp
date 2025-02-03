#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef unsigned long long _;
typedef const long long constant;

constant maxn = 9600+8;
constant maxp = 64+8;

_ n, dp[maxn][maxp], t;

void soak(_ x);
_ getPhoto();
int main() {

	scanf("%llu", &n);
	dp[0][0] = 1;
	for(_ i = 1; i <= n; ++i) {
		t = getPhoto();
		for(_ j = 0; j <= 63; ++j) if((t & j) != t) dp[i][j] = dp[i-1][j];
		else dp[i][j] = dp[i-1][j] + dp[i-1][j^t];
	}
	
	printf("%llu\n", dp[n][63]);
	
	return 0;
}

_ getPhoto() {
	_ rv = 0;
	for(_ i = 1; ; ++i) {
		char ch, ch2;
		if(i > 6) dp[1342142324134231][3] =3 ;
		for(ch = getchar(); !(ch >= 'A' && ch <= 'Z'); ) ch = getchar();
		ch2 = getchar();
		if(ch == 'S') soak(ch2 == 'o' ? 3 : 2);
		ef(ch == 'Y') soak(ch2 == 'e' ? 3 : 2);
		ef(ch == 'E') soak(3);
		ef(ch == 'U') soak(2);
		if(ch == 'S' && ch2 == 'o') rv |= (1<<0);
		ef(ch == 'S' && ch2 == 'i') rv |= (1<<1);
		ef(ch == 'Y' && ch2 == 'e') rv |= (1<<2);
		ef(ch == 'Y' && ch2 == 'u') rv |= (1<<3);
		ef(ch == 'E') rv |= (1<<4);
		ef(ch == 'U') rv |= (1<<5);
		if(getchar() != ',') break;
	}
	return rv;
}

void soak(_ x) {
	for(_ i = 1; i <= x; ++i) getchar();
	return;
}