#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxc = 8+8;

_ a[maxc], d;
str cl;
vector<_> v;

int main() {
	
	for(_ i = 1; i <= 7; ++i) scanf("%lld", &a[i]);
	scanf("%lld", &d);
	cin >> cl;
	if(cl == "cyan") printf("%lld\n", a[1]*d);
	ef(cl == "magenta") printf("%lld\n", a[2]*d);
	ef(cl == "yellow") printf("%lld\n", a[3]*d);
	ef(cl == "red") {
		if(d & 1) {
			--d;
			_ mn = min((d>>1)*(a[2]+a[3]), a[5]*d);
			printf("%lld\n", min(mn+a[2]+a[3], mn+a[5]));
		} else printf("%lld\n", min((d>>1)*(a[2]+a[3]), a[5]*d));
	} ef(cl == "green") {
		if(d & 1) {
			--d;
			_ mn = min((d>>1)*(a[1]+a[3]), a[6]*d);
			printf("%lld\n", min(mn+a[1]+a[3], mn+a[6]));
		} else printf("%lld\n", min((d>>1)*(a[1]+a[3]), a[6]*d));
	} ef(cl == "blue") {
		if(d & 1) {
			--d;
			_ mn = min((d>>1)*(a[1]+a[2]), a[7]*d);
			printf("%lld\n", min(mn+a[1]+a[2], mn+a[7]));
		} else printf("%lld\n", min((d>>1)*(a[1]+a[2]), a[7]*d));
	} ef(cl == "black") {
		v.push_back(a[1]+a[2]+a[3]);
		v.push_back(a[5]+a[6]+a[7]);
		v.push_back(a[1]+(a[5]<<1));
		v.push_back(a[2]+(a[6]<<1));
		v.push_back(a[3]+(a[7]<<1));
		v.push_back(a[4]*3);
		_ bc = *min_element(v.begin(), v.end());
		if(d % 3) printf("%lld\n", min((d+2)/3*bc, d/3*bc+(d%3)*a[4]));
		else printf("%lld\n", d/3*bc);
	}
	
	return 0;
}