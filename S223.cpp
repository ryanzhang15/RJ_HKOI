#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant big = 1E6;

str go[900], gda[1008][1008], gdb[2000008], a, b;
_ gsv[1008][1008];

void dfsb(_ x);
void dfsa(_ x);
_ gcd(_ a, _ b);
int main() {
	
	memset(gsv, ~0, sizeof gsv);
//		printf("%lld\n", gcd(6, 20));

	go['0'] = "08";
	go['1'] = "0134789";
	go['2'] = "28";
	go['3'] = "389";
	go['4'] = "489";
	go['5'] = "5689";
	go['6'] = "68";
	go['7'] = "03789";
	go['8'] = "8";
	go['9'] = "89";
	go['+'] = "+";
	go['-'] = "+-/";
	go['*'] = "*";
	go['/'] = "+/";
	for(char ch = getchar(); ch != '='; ch = getchar()) a += ch;
	for(char ch = getchar(); ch != '\n' && ch != '\r' && ch != EOF; ch = getchar()) b += ch;
	dfsa(0);
	dfsb(0);
	puts("Impossible");
		
	return 0;
}

_ gcd(_ a, _ b) {
	if(~gsv[a][b]) return gsv[a][b];
	if(!b) return a;
	_ rv = gcd(b, a%b);
	gsv[a][b] = rv;
	return gsv[a][b];
}

void dfsa(_ x) {
	if(x == a.length()) {
//		cout << a << ' ';
		_ ta = 0, tb = 0, op = 0;
		for(_ i = 0; ; ++i) {
			if(!(a[i] >= '0' && a[i] <= '9')) {
				op = i;
				break;
			}
			ta = (ta<<3)+(ta<<1)+(a[i]^48);
		}
		for(_ i = op+1; i < a.length(); ++i) tb = (tb<<3)+(tb<<1)+(a[i]^48);
		if(a[op] == '/' && tb == 0) return;
		if(a[op] == '+') ta += tb;
		ef(a[op] == '-') ta -= tb;
		ef(a[op] == '*') ta *= tb;
		else {
			if(!tb) ta = tb = 1000;
			if(!ta) {
				ta = 0;
				tb = 1;
			} else {
				_ g = gcd(ta, tb);
				ta /= g;
				tb /= g;
			}
		}
//		cout << ta << ' ' << tb << endl;
		if(a[op] != '/') gdb[ta+big] = a;
		else gda[ta][tb] = a;
		return;
	}
	char c = a[x];
	for(char i : go[c]) {
		a[x] = i;
		dfsa(x+1);
	} 
	a[x] = c;
	return;
}

void dfsb(_ x) {
	if(x == b.length()) {
//		cout << b << ' ';
		_ ta = 0, tb = 0, op = 0;
		for(_ i = 0; ; ++i) {
			if(!(b[i] >= '0' && b[i] <= '9')) {
				op = i;
				break;
			}
			ta = (ta<<3)+(ta<<1)+(b[i]^48);
		}
		for(_ i = op+1; i < b.length(); ++i) tb = (tb<<3)+(tb<<1)+(b[i]^48);
		if(b[op] == '/' && tb == 0) return;
//		if(b[op] != '/' || ta != 0) return;
		if(b[op] == '+') ta += tb;
		ef(b[op] == '-') ta -= tb;
		ef(b[op] == '*') ta *= tb;
		else {
			if(!tb) ta = tb = 1000;
			if(!ta) {
				ta = 0;
				tb = 1;
			} else {
				_ g = gcd(ta, tb);
				ta /= g;
				tb /= g;
			}
		}
//		cout << ta << ' ' << tb << endl;
//		if(ta == -160) {
//			puts("wat");
//		}
		if(b[op] != '/') {
			if(!gdb[ta+big].empty()) {
				cout << gdb[ta+big] << '=' << b << endl;
				exit(0);
			}
			if(ta <= 1000 && ta >= 0 && !gda[ta][1].empty()) {
				cout << gda[ta][1] << '=' << b << endl;
				exit(0);
			}
		} else {
			if(tb == 1 && !gdb[ta+big].empty()) {
				cout << gdb[ta+big] << '=' << b << endl;
				exit(0);
			}
			if(!gda[ta][tb].empty()) {
				cout << gda[ta][tb] << '=' << b << endl;
				exit(0);
			}
		}
		return;
	}
	char c = b[x];
	for(char i : go[c]) {
		b[x] = i;
		dfsb(x+1);
	} 
	b[x] = c;
	return;
}
