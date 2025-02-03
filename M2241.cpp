#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 4E2+8;

_ dp[2][maxn], n, h, m;

long long maximum_sum(int N, int H, int M, std::string S) {
	n = N;
	h = H;
	m = M;
	memset(dp, -4, sizeof dp);
	dp[0][0] = 0;
	for(_ i = 1, p = 1; i <= N; ++i, p ^= 1) {
		memset(dp[p], -4, sizeof dp[p]);
		for(_ j = 0; j < M; ++j) {
//			printf("dp at i = %lld, j = %lld\n", i, j);
			_ rl = (j*h+S[i-1]-'a'+1)%m;
			dp[p][rl] = max(dp[p][rl], dp[p^1][j]);
			rl = S[i-1]-'a'+1;
			dp[p][rl] = max(dp[p][rl], dp[p^1][j]+j);
		}
	}
	_ s = -1E17;
	for(_ i = 0; i < M; ++i) s = max(s, dp[n&1][i]+i);
    return s;
}


#ifndef ONLINE_JUDGE
int main() {

	printf("%lld\n", maximum_sum(4, 2, 27, "dabb"));

	return 0;
}
#endif
