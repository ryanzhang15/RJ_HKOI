#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 9+8;

char a[maxn][maxn];
set<_p> s;
struct ve {
    _p pos;
    char d;
    bool operator < (const ve &b) {
        if(pos.first != b.pos.first) return pos.first < b.pos.first;
        if(pos.second != b.pos.second) return pos.second < b.pos.second;
        return d == 'd';
    }
};
vector<ve> ans;
_ bm;

void check(_p p, char d);
ve makeMove(_p p, char d);
void checkRight(_p p);
void checkDown(_p p);
char charGet();
int main() {
    
    for(_ i = 1; i <= 9; ++i) for(_ j = 1; j <= 9; ++j) a[i][j] = charGet();
    
    //swap right
    for(_ i = 1; i <= 9; ++i) for(_ j = 1; j <= 8; ++j) {
        swap(a[i][j], a[i][j+1]);
        check(make_pair(i, j), 'r');
        swap(a[i][j], a[i][j+1]);
    }
    
    //swap down
    for(_ i = 1; i <= 8; ++i) for(_ j = 1; j <= 9; ++j) {
        swap(a[i][j], a[i+1][j]);
        check(make_pair(i, j), 'd');
        swap(a[i][j], a[i+1][j]);
    }
    
    if(!bm) {
        puts("No move");
        exit(0);
    }
    sort(ans.begin(), ans.end());
    printf("%lld\n", bm);
    for(vector<ve>::iterator i = ans.begin(); i != ans.end(); ++i) printf("(%lld, %lld) %c\n", (*i).pos.first, (*i).pos.second, (*i).d);
    
    return 0;
}

char charGet() {
    char c = getchar();
    for(; c == '\n' || c == '\r' || c == ' '; ) c = getchar();
    return c;
}

void checkDown(_p p) {
    char r = a[p.first][p.second];
    set<_p> c;
    for(_ i = p.first; i <= 9; ++i) if(a[i][p.second] == r) c.insert(make_pair(i, p.second));
    else break;
    for(_ i = p.first; i >= 1; --i) if(a[i][p.second] == r) c.insert(make_pair(i, p.second));
    else break;
    if(c.size() >= 3) for(set<_p>::iterator i = c.begin(); i != c.end(); ++i) s.insert(*i);
    return;
}

void checkRight(_p p) {
    char r = a[p.first][p.second];
    set<_p> c;
    for(_ i = p.second; i <= 9; ++i) if(a[p.first][i] == r) c.insert(make_pair(p.first, i));
    else break;
    for(_ i = p.second; i >= 1; --i) if(a[p.first][i] == r) c.insert(make_pair(p.first, i));
    else break;
    if(c.size() >= 3) for(set<_p>::iterator i = c.begin(); i != c.end(); ++i) s.insert(*i);
    return;
}

ve makeMove(_p p, char d) {
    ve a;
    a.pos = p;
    a.d = d;
    return a;
}

void check(_p p, char d) {
    s.clear();
    if(d == 'd') {
        checkDown(p);
        checkDown(make_pair(p.first+1, p.second));
        checkRight(p);
        checkRight(make_pair(p.first+1, p.second));
    } else {
        checkDown(p);
        checkDown(make_pair(p.first, p.second+1));
        checkRight(p);
        checkRight(make_pair(p.first, p.second+1));
    }
    if(s.size() >= 3 && 5*pow(3, s.size()-3) > bm) {
        bm = 5*pow(3, s.size()-3);
        ans.clear();
        ans.push_back(makeMove(p, d));
    } ef(5*pow(3, s.size()-3) == bm) ans.push_back(makeMove(p, d));
    return;
}

