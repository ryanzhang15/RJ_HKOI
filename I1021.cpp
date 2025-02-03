
#ifdef __cplusplus
extern "C" {
#endif
char faceup(int C);
void play();
#ifdef __cplusplus
}
#endif

// TODO: global variables can be declared here

char l[100];
int t = 25;
bool v[100];

void play() {
    // TODO: implementation
    for(int i = 1; i < 50; i += 2) {
        l[i] = faceup(i);
        l[i+1] = faceup(i+1);
        if(l[i] == l[i+1]) {
            --t;
            v[i] = v[i+1] = true;
        }
    }
    if(!t) return;
    for(int i = 1; i <= 50; ++i) {
        if(v[i]) continue;
        char f = l[i];
        faceup(i);
        for(int j = i+1; j <= 50; ++j) {
            if(v[j]) continue;
            if(l[j] == f) {
                --t;
                v[j] = true;
                faceup(j);
                break;
            }
        }
        v[i] = true;
    }
    return;
}
