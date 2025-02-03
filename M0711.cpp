#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 50+8;

_ n;
struct moves {
	str b, a;
	char ltr;
	bool operator < (const moves &thr) const {
		return a.length() > thr.a.length();
	}
} a[maxn];
str c;

int main() {
	
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	
	cin >> n;
	for(_ i = 1; i <= n; ++i) {
		cin.ignore();
		getline(cin, a[i].b);
		cin >> a[i].a;
		a[i].ltr = a[i].a[a[i].a.length()-1];
		a[i].a = a[i].a.substr(0, a[i].a.length()-1);
	}
	sort(a+1, a+1+n);
	cin.ignore();
	for(char ch; cin >> ch; ) if(ch == 'p' || ch == 'k') {
		for(_ i = 1; i <= n; ++i) if(a[i].a.length() > c.length() || a[i].ltr != ch) continue;
		ef(a[i].a == c.substr(c.length()-a[i].a.length())) {
			cout << a[i].b << endl;
			break;
		}
		c.clear();
	} else c.push_back(ch);
	
	return 0;
}