
#ifdef __cplusplus
extern "C" {
#endif
int examine(int X, int Y);
void solution(int XC, int YC);
void findCenter(int N, int X0, int Y0);
#ifdef __cplusplus
}
#endif

#include <cstdio>
#include <cstdlib>
#define ef else if

typedef long long _;

using namespace std;

_ d, r, l, t, b, x, p, lb, rb, md, s, n, cx, cy, lt, rt, up, dw, cnt;

//void solution(int XC, int YC) {
//    printf("SOL: %d %d\n", XC, YC);
//    exit(0);
//}
//
//int examine(int X, int Y) {
//    printf("? %d %d\n", X, Y);
//    _ x;
//    scanf("%lld", &x);
//    return (int)x;
//}

void findCenter(int N, int X0, int Y0) {
    n = N;
    x = X0+1;
    if(x < n) {
        p = 2;
        for(; examine(x, Y0); p <<= 1) {
            x += p;
            if(x > n) {
                x = n;
                break;
            }
        }
    } else x = n;
    lb = X0;
    rb = x;
    for(; lb <= rb; ) {
        md = (lb+rb)>>1;
        if(examine(md, Y0)) {
            s = md;
            lb = md+1;
        } else rb = md-1;
    }
    r = s;
    x = X0-1;
    if(x > 1) {
        p = 2;
        for(; examine(x, Y0); p <<= 1) {
            x -= p;
            if(x < 1) {
                x = 1;
                break;
            }
        }
    } else x = 1;
    lb = x;
    rb = X0;
    for(; lb <= rb; ) {
        md = (lb+rb)>>1;
        if(examine(md, Y0)) {
            s = md;
            rb = md-1;
        } else lb = md+1;
    }
    l = s;
    d = r-l+1;
    x = Y0+1;
    if(x < n) {
        p = 2;
        for(; examine(X0, x); p <<= 1) {
            x += p;
            if(x > n) {
                x = n;
                break;
            }
        }
    } else x = n;
    lb = Y0;
    rb = x;
    for(; lb <= rb; ) {
        md = (lb+rb)>>1;
        if(examine(X0, md)) {
            s = md;
            lb = md+1;
        } else rb = md-1;
    }
    t = s;
    b = s-d+1;
    cx = l+(d>>1);
    cy = b+(d>>1);
    for(; cx-dw*(d<<1) > 0 && examine(cx-dw*(d<<1), cy); ) ++dw;
    for(; cx+up*(d<<1) <= n && examine(cx+up*(d<<1), cy); ) ++up;
    for(; cy-lt*(d<<1) > 0 && examine(cx, cy-lt*(d<<1)); ) ++lt;
    for(; cy+rt*(d<<1) <= n && examine(cx, cy+rt*(d<<1)); ) ++rt;
    --lt;
    --rt;
    --dw;
    --up;
    if(!lt && rt == 2 && !up && dw == 2) solution(cx-d*2, cy+d*2);
    ef(!lt && rt == 2 && up == 1 && dw == 1) solution(cx, cy+d*2);
    ef(!lt && rt == 2 && up == 2 && !dw) solution(cx+d*2, cy+d*2);
    ef(!lt && rt == 1 && !up && dw == 1) solution(cx-d, cy+d);
    ef(!lt && rt == 1 && up == 1 && !dw) solution(cx+d, cy+d);
    ef(lt == 1 && rt == 1 && !up && dw == 2) solution(cx-d*2, cy);
    ef(lt == 1 && rt == 1 && up == 1 && dw == 1) solution(cx, cy);
    ef(lt == 1 && rt == 1 && up == 2 && !dw) solution(cx+d*2, cy);
    ef(lt == 1 && !rt && !up && dw == 1) solution(cx-d, cy-d);
    ef(lt == 1 && !rt && up == 1 && !dw) solution(cx+d, cy-d);
    ef(lt == 2 && !rt && !up && dw == 2) solution(cx-d*2, cy-d*2);
    ef(lt == 2 && !rt && up == 1 && dw == 1) solution(cx, cy-d*2);
    else solution(cx+d*2, cy-d*2);
 
    return;
}

//int main() {
//    findCenter(15, 1, 1);
//    return 0;
//}
