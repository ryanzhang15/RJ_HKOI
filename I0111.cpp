
#ifdef __cplusplus
extern "C" {
#endif
void init(int S);
void update(int X, int Y, int A);
int sum(int L, int B, int R, int T);
#ifdef __cplusplus
}
#endif

int n, t[1025][1025];

void init(int S) {
    n = S;
    return;
}

void update(int X, int Y, int A) {
    ++X;
    ++Y;
    for(int i = X; i <= n; i += i & (-i)) for(int j = Y; j <= n; j += j & (-j)) t[i][j] += A;
    return;
}

int sum(int L, int B, int R, int T) {
    ++L;
    ++B;
    ++R;
    ++T;
    int a, b, c, d;
    a = b = c = d = 0;
    for(int i = R; i; i -= i & (-i)) for(int j = T; j; j -= j & (-j)) a += t[i][j];
    for(int i = L-1; i; i -= i & (-i)) for(int j = T; j; j -= j & (-j)) b += t[i][j];
    for(int i = R; i; i -= i & (-i)) for(int j = B-1; j; j -= j & (-j)) c += t[i][j];
    for(int i = L-1; i; i -= i & (-i)) for(int j = B-1; j; j -= j & (-j)) d += t[i][j];
    return a-b-c+d;
}
