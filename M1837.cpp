#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

_ n, a, b;

int main() {
	
	scanf("%lld", &n);
	for(; n--; ) {
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", (86400*b%a+1)*(86400*b%a+1)*(a-86400*b%a+1)*(a-86400*b%a+1));
	}
	
	return 0;
}