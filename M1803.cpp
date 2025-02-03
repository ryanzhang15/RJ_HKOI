#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef string str;
typedef const long long constant;

constant maxn = 1E6+8;
list<str> t[maxn];
list<str>::iterator s[maxn];
str c;
_ n = 1, top;

int main() {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(EXIT_SUCCESS);
    
    for(bool a = false; cin >> c; a = false) {
        if(c[c.length()-1] == '.') {
            c = c.substr(0, c.length()-1);
            a = true;
        }
        t[n].push_back(c);
        n += a;
    }
    --n;
    for(_ i = 1; i <= n; ++i) {
        top = 0;
        for(list<str>::iterator j = t[i].begin(); j != t[i].end(); ++j) {
            s[++top] = j;
            if(top >= 3 && *s[top-2] == "I" && *s[top-1] == "love" && *s[top] == "you") {
                j = s[top-2];
                --j;
                t[i].erase(s[top-2], ++s[top]);
                top -= 3;
            }
        }
    }
    for(_ i = 1; i <= n; ++i) {
        if(t[i].empty()) continue;
        for(list<str>::iterator j = t[i].begin(); j != t[i].end(); ++j) {
            if(j != t[i].begin()) cout << ' ';
            cout << *j;
        }
        cout << ". ";
    }
    
    return 0;
}


