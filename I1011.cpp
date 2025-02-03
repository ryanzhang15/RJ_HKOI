#ifdef __cplusplus
extern "C" {
#endif
int Theory(int M, int L, int W);
void Solve();
#ifdef __cplusplus
}
#endif

// TODO: global variables can be declared here
int g[3];

void Solve() {
    // TODO: implementation
    g[0] = g[1] = g[2] = 1;
    while(true) {
        int a = Theory(g[0], g[1], g[2]);
        if(!a) return;
        g[a-1]++;
    }
    return;
}
