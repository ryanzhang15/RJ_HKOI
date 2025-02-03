#include <bits/stdc++.h>
#define ef else if
#define i(x) x::iterator
#define mp(x, y) make_pair(x, y)
#define v(x) vector<x > 

using namespace std;

typedef long long _;
typedef string str;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

typedef long long ll;

constant maxn = 2E5+8;
constant mod = 1E9+7;

_ n, m;
char a[maxn];
str t, da, db;
struct el {
    __int128 a[12];
};

_ rk(char a);
el exprFind(str a);
bool smol(char a, char b);
int main() {

//#define file_IO
#ifdef file_IO
    freopen("data.in", "r", stdin);
#endif

    scanf("%lld", &n);
    for(; n--; ) {
        scanf("%s", a+1);
        m = strlen(a+1);
        da.clear();
        db.clear();
        _ eq = 0;
        for(_ i = 1; i <= m; ++i) if(a[i] == '=') {
            eq = i;
            break;
        } else da.push_back(a[i]);
        for(_ i = eq+1; i <= m; ++i) db.push_back(a[i]);
        _ s = 0;
        el t1 = exprFind(da), t2 = exprFind(db);
        for(_ i = 0; i <= 9; ++i) s = (s+t1.a[i]*t2.a[i]%mod)%mod;
        printf("%lld\n", (s+mod)%mod);
    }
    
    
    return 0;
}

bool smol(char a, char b) {
    if(b == '(') return false;
    _ ab = 1, bb = 1;
    if(a == '+' || a == '-') ab = 0;
    if(b == '+' || b == '-') bb = 0;
    return ab <= bb;
}

el exprFind(str a) {
    t.clear();
    {
        stack<_> st;
        for(_ i = 0; i < a.length(); ++i) {
            if(a[i] == '?' || (a[i] >= '0' && a[i] <= '9')) t += a[i];
            ef(a[i] == '(') st.push(a[i]);
            ef(a[i] == ')') {
                for(; !st.empty() && st.top() != '('; st.pop()) t += st.top();
                st.pop();
            } else {
                for(; !st.empty() && rk(a[i]) <= rk(st.top()); st.pop()) t += st.top();
                st.push(a[i]);
            }
            //printf("%lu\n", st.size());
        }
        for(; !st.empty(); st.pop()) t += st.top(); 
    }   
    stack<el> st;
    for(char i : t) {
        if(i >= '0' && i <= '9') {
            el nw;
            for(_ j = 0; j <= 9; ++j) nw.a[j] = 0;
            nw.a[i^48] = 1;
            st.push(nw);
        } ef(i == '?') {
            el nw;
            for(_ j = 0; j <= 9; ++j) nw.a[j] = 1;
            st.push(nw);
        } ef(i == '+') {
            el x = st.top(), y;
            st.pop();
            y = st.top();
            st.pop();
            el nw;
            for(_ j = 0; j <= 9; ++j) nw.a[j] = 0;
            for(_ j = 0; j <= 9; ++j) for(_ k = 0; k <= 9; ++k) if(j+k <= 9) nw.a[j+k] = (nw.a[j+k]+x.a[j]*y.a[k]%mod)%mod;
            st.push(nw);
        } ef(i == '-') {
            el x, y = st.top();
            st.pop();
            x = st.top();
            st.pop();
            el nw;
            for(_ j = 0; j <= 9; ++j) nw.a[j] = 0;
            for(_ j = 0; j <= 9; ++j) for(_ k = 0; k <= 9; ++k) if(j-k >= 0) nw.a[j-k] = (nw.a[j-k]+x.a[j]*y.a[k]%mod)%mod;
            st.push(nw);
        } ef(i == '*') {
            el x = st.top(), y;
            st.pop();
            y = st.top();
            st.pop();
            el nw;
            for(_ j = 0; j <= 9; ++j) nw.a[j] = 0;
            for(_ j = 0; j <= 9; ++j) for(_ k = 0; k <= 9; ++k) if(j*k <= 9) nw.a[j*k] = (nw.a[j*k]+x.a[j]*y.a[k]%mod)%mod;
            st.push(nw);
        }
    }
    return st.top();
}

_ rk(char a) {
    if(a == '*') return 2;
    ef(a != '(') return 1;
    return 0;
}