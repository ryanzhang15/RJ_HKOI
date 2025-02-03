#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxd = 35+8;
str a, dp[maxd][maxd];
_ n;

str strMax(str a, str b);
str times(str a, str b);
str sub(str a, str b);
str add(str a, str b);
int main() {
	
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	
	cin >> a >> n;
	a = " " + a;
	dp[0][0] = "1";
	for(_ i = 1; i <= a.length(); ++i) dp[i][0] = a.substr(1, i);
	for(_ j = 1; j <= n; ++j) for(_ i = j+1; i <= a.length(); ++i) for(_ k = 1; k <= i-1; ++k) if(!dp[k][j-1].empty()) dp[i][j] = strMax(dp[i][j], times(a.substr(k+1, i-k), dp[k][j-1]));
	cout << dp[a.length()][n] << endl;
	
	return 0;
}

str add(str a, str b) {
    if(a.length() > b.length()) swap(a, b);
    _ al = a.length(), bl = b.length();
    for(_ i = 0; i < ceil(al / 2); i++) swap(a[i], a[al - i - 1]);
    for(_ i = 0; i < ceil(bl / 2); i++) swap(b[i], b[bl - i - 1]);
    str res = ""; _ cr = 0;
    for(_ i = 0; i < al; i++) {
        _ cur = a[i]-'0' + b[i]-'0' + cr;
        res.push_back(cur % 10 + '0');
        cr = cur / 10;
    }
    for(_ i = al; i < bl; i++) {
        _ cur = b[i]-'0' + cr;
        res.push_back(cur % 10 + '0');
        cr = cur / 10;
    }
    if(cr) res.push_back(cr + '0');
    _ rl = res.length();
    for(_ i = 0; i < ceil(rl / 2); i++) swap(res[i], res[rl - i - 1]);
    return res;
}

str sub(str a, str b) {
    if(a == b) {
        return "0";
    }
    bool negative = false;
    if(a.length() < b.length()) {
        negative = true;
        swap(a, b);
    } else if(a.length() == b.length()) {
        if(a < b) {
            negative = true;
            swap(a, b);
        }
    }
    vector<_> av, bv; _ al = a.length(), bl = b.length();
    for(_ i = 0; i < al; i++) {
        av.push_back(a[al - i - 1] - '0');
    }
    for(_ i = 0; i < bl; i++) {
        bv.push_back(b[bl - i - 1] - '0');
    }
    for(_ i = 0; i < bl; i++) {
        av[i] -= bv[i];
        if(av[i] < 0) {
            av[i] += 10;
            av[i + 1]--;
        }
    }
    bool flag = false; str res = (negative) ? "-" : "";
    for(_ i = al - 1; i >= 0; i--) {
        if(av[i]) flag = true;
        if(flag) res.push_back((char)(av[i] + '0'));
    }
    return res;
}

str times(str a, str b) {
    if(a == "0" || b == "0") return "0";
    if(a.length() < b.length()) swap(a, b);
    _ al = a.length(), bl = b.length();
    vector<_> av, bv, c (al + bl, 0);
    for(_ i = al - 1; i >= 0; i--) {
        av.push_back(a[i] - '0');
    }
    for(_ i = bl - 1; i >= 0; i--) {
        bv.push_back(b[i] - '0');
    }
    for(_ i = 0; i < al; i++) {
        for(_ j = 0; j < bl; j++) {
            c[i+j] += av[i] * bv[j];
        }
    }
    for(_ i = 0; i < al + bl; i++) {
        if(c[i] >= 10) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    bool flag = false; str res = "";
    for(_ i = al + bl - 1; i >= 0; i--) {
        if(c[i]) flag = true;
        if(flag) res.push_back((char)(c[i] + '0'));
    }
    return res;
}

str strMax(str a, str b) {
	if(b.length() != a.length()) return b.length() > a.length() ? b : a;
	return b > a ? b : a;
}