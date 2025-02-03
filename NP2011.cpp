#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

_ n, r, yr, mn, d, mnc[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

inline _ read();
inline _ getMonA(_ yr, _ mn);
inline bool isleapA(_ yr);
inline _ getMonB(_ yr, _ mn);
inline bool isleapB(_ yr);
int main() {
    
    freopen("julian.in", "r", stdin);
    freopen("julian.out", "w", stdout);
    
    n = read();
    for(; n--; ) {
        r = read();
        yr = -4713;
        mn = 1;
        d = 1;
        if(r <= 2299160) {
            //jump 4-year blocks
            _ jmp = r / (365*3+366);
            r -= jmp * (365*3+366);
            yr += jmp<<2;
            if(yr >= 0) ++yr;
            //jump 1-year blocks
            for(;;) {
                _ f = isleapB(yr) ? 366 : 365;
                if(r < f) break;
                ++yr;
                if(!yr) ++yr;
                r -= f;
            }
            //jump 1-month blocks
            for(;;) {
                _ f = getMonB(yr, mn);
                if(r < f) break;
                if(++mn == 13) {
                    mn = 1;
                    if(!++yr) ++yr;
                }
                r -= f;
            }
            //jump 1-day blocks
            for(; r; r--) {
                if(++d > getMonB(yr, mn)) {
                    d = 1;
                    if(++mn == 13) {
                        mn = 1;
                        if(!++yr) ++yr;
                    }
                }
            }
        } else {
            r -= 2299160;
            yr = 1582;
            mn = 10;
            d = 14;
            //jump 400-year blocks
            _ jmp = r / (400*365+97);
            r -= jmp * (400*365+97);
            yr += jmp * 400;
            /*
             //jump 1-year blocks
             for(;;) {
             _ f = isleapA(yr) ? 366 : 365;
             if(r < f) break;
             ++yr;
             if(!yr) ++yr;
             r -= f;
             }
             */
            //jump 1-month blocks
            for(;;) {
                _ f = getMonA(yr, mn);
                if(r < f) break;
                if(++mn == 13) {
                    mn = 1;
                    if(!++yr) ++yr;
                }
                r -= f;
            }
            //jump 1-day blocks
            for(; r; r--) {
                if(++d > getMonA(yr, mn)) {
                    d = 1;
                    if(++mn == 13) {
                        mn = 1;
                        ++yr;
                    }
                }
            }
        }
        printf("%lld %lld %lld ", d, mn, yr < 0 ? -yr : yr);
        if(yr < 0) puts("BC");
        else putchar('\n');
    }
    
    return 0;
}

inline bool isleapB(_ yr) {
    if(yr < 0) return !((yr+1)%4);
    return !(yr%4);
}

inline _ getMonB(_ yr, _ mn) {
    if(mn != 2) return mnc[mn];
    else return isleapB(yr) ? 29 : 28;
}

inline bool isleapA(_ yr) {
    if(!(yr % 400) || (yr % 100 && !(yr % 4))) return true;
    else return false;
}

inline _ getMonA(_ yr, _ mn) {
    if(mn != 2) return mnc[mn];
    else return isleapA(yr) ? 29 : 28;
}

inline _ read() {
    _ x = 0, f = 1; char ch = getchar();
    for(; !isdigit(ch); ) {
        ch = getchar();
        if(ch == '-') f = -1;
    }
    for(; isdigit(ch); ) {
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x*f;
}


