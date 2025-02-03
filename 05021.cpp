#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long double _D;

_D v, a, b, c, t[43];

void notSure();
void onBoard();
void consign();
int main() {
	
	scanf("%Lf%Lf%Lf%Lf", &v, &a, &b, &c);
	if(b > c) swap(b, c);
	if(a > b) swap(a, b);
	if(b > c) swap(b, c);
	if(a > 130 || b > 130 || c > 130) consign();
	if(b != -1 && c != -1) {
		if(a == -1) a = v/(b*c);
		if(a > 130) consign();
		if(a+b+c > 220) consign();
		onBoard();
	} else if(c != -1) {
		if(sqrt(v/c) > 130 || 2*sqrt(v/c)+c > 220) consign();
		if(v/(c*10) <= 130 && v/(c*10)+c+10 <= 220) onBoard();
		notSure();
	} else {
		if(cbrt(v)*3 > 220) consign();
		if(v/100 <= 130) onBoard();
		notSure();
	}
	
	return 0;
}

void consign() {
	puts("Pay for consignment!");
	exit(0);
}

void onBoard() {
	puts("Carry it on board!");
	exit(0);
}

void notSure() {
	puts("Not sure!");
	exit(0);
}