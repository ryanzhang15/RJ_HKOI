#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 5E3+8; //not sure what size

_ n, m, k, sr, sc, er, ec, cnt;
struct outputStatement {
	str dir;
	_ len;
} o[maxn]; 

outputStatement ms(str dir, _ len);
void findPath(_ l, _ r, _ bnd, str f, str b);
int main() {
	
	scanf("%lld%lld%lld%lld%lld%lld%lld", &n, &m, &k, &sr, &sc, &er, &ec);
	if(sr < er) findPath(sr, er, n, "down", "up");
	if(sr > er) findPath(n-sr+1, n-er+1, n, "up", "down");
	if(sc < ec) findPath(sc, ec, m, "right", "left");
	if(sc > ec) findPath(m-sc+1, m-ec+1, m, "left", "right");
	printf("%lld\n", cnt);
	for(_ i = 1; i <= cnt; ++i) cout << o[i].dir <<' '<< o[i].len << endl;
	
	return 0;
}

void findPath(_ l, _ r, _ bnd, str f, str b) {
	vector<outputStatement> cand1, cand2, bc;
	_ d = r-l, c = d/k;
	if(!c) for(_ i = 1; i <= d; ++i) cand1.push_back(ms(f, 1));
	else {
	    cand1.push_back(ms(f, k*c));
	    for(_ i = 1; i <= d-k*c; ++i) cand1.push_back(ms(f, 1));
	}
	bc = cand1;
	++c;
	if(k < bnd) {
	    _ rmn = k*c-d, lc = l;
	    if(k*c < bnd) {
	        for(; rmn >= 1 && lc >= 2; --lc, --rmn) cand2.push_back(ms(b, 1));
	        cand2.push_back(ms(f, k*c));
	        lc += k*c;
	        for(; lc != r; --lc) cand2.push_back(ms(b, 1));
	    } else {
	        for(; rmn >= 1 && lc >= 2; --lc, --rmn) cand2.push_back(ms(b, 1));
	        cand2.push_back(ms(f, k));
	        for(; rmn >= 1; --rmn) cand2.push_back(ms(b, 1));
	        cand2.push_back(ms(f, k*(c-1)));
	    }
	    if(cand2.size() < bc.size()) bc = cand2;
	}
	for(vector<outputStatement>::iterator i = bc.begin(); i != bc.end(); ++i) o[++cnt] = *i;
	return;
}

outputStatement ms(str dir, _ len) {
	return (outputStatement){dir, len};
}

/*
1 16 15
1 3
1 15
*/