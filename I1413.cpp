#ifdef __cplusplus
extern "C" {
#endif
void initialize(int n);
int hasEdge(int u, int v);
#ifdef __cplusplus
}
#endif

// TODO: global variables can be declared here
int deg[1508];

void initialize(int n) {
    // TODO: implementation
    return;
}

int hasEdge(int u, int v) {
    // TODO: implementation
    int mx = u > v ? u : v;
    return ++deg[mx]==mx;
}

