#ifdef __cplusplus
extern "C" {
#endif
void Init();
void TypeLetter(char L);
void UndoCommands(int U);
char GetLetter(int P);
#ifdef __cplusplus
}
#endif

using namespace std;

typedef int _;
typedef const long long constant;

constant maxn = 1E6+5;
constant maxlg = maxn*21;

_ n, cnt, r[maxn], le[maxlg], ri[maxlg], sz[maxn], ln[maxn], cur;
char t[maxlg];

inline _ build(_ l, _ r) {
	_ rt = ++cnt, md = (l+r)>>1;
	if(l < r) {
		le[rt] = build(l, md);
		ri[rt] = build(md+1, r);
	}
	return rt;
}

inline _ update(_ pre, _ pos, _ l, _ r, char x) {
	_ rt = ++cnt;
	if(l == r) {
		t[cnt] = x;
		return rt;
	}
	le[rt] = le[pre];
	ri[rt] = ri[pre];
	_ md = (l+r)>>1;
	if(md >= pos) le[rt] = update(le[pre], pos, l, md, x);
	else ri[rt] = update(ri[pre], pos, md+1, r, x);
	return rt;
}

inline char query(_ pos, _ l, _ r, _ x) {
	if(l == r) return t[pos];
	_ md = (l+r)>>1;
	if(md > x) return query(le[pos], l, md, x);
	else return query(ri[pos], md+1, r, x);
}

void Init() {
	r[++cur] = build(1, 1E6);
	return;
}

void TypeLetter(char L) {
	ln[++cur] = ln[cur-1]+1;
	r[cur] = update(r[cur-1], ln[cur], 1, 1E6, L);
	return;
}

void UndoCommands(int U) {
	r[++cur] = r[cur-U-1];
	ln[cur] = ln[cur-U-1];
	return;
}

char GetLetter(int P) {
	return query(r[cur], 1, 1E6, P);
}
