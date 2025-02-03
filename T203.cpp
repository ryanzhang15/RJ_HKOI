#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <bitset>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>

#define fs(str) (str).c_str()
#define _lin "%lld"
#define _llin "%lld%lld"
#define _lllin "%lld%lld%lld"
#define _llllin "%lld%lld%lld%lld"
std::string _l = "%lld";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E5+88;
struct key {
    str s;
    _ f = 0, b = 0;
} a[maxn];
_ n, k, cnta, cntb, c, ac, b, ct, bgmt, mxin, ct2, bgmt2, mxin2;
bool v[maxn], fld, inmode, noti, v2[maxn];
str t, all[maxn], ans[maxn], s[maxn], ns[maxn], ns1[maxn], ns2[maxn];

_ solve(str (&ans)[maxn]), fill(str (&ans)[maxn]);
int main(int argc, char * argv[]) {
    
    ios_base::sync_with_stdio(NULL);
    cin.tie(EXIT_SUCCESS);
    
    cin >> n >> k;
    for(_ i = 1; i <= n; ++i) {
        cin >> t;
        inmode = false;
        for(char j : t) {
            if(j == 'a') ++ct;
            else {
                if(inmode) {
                    if(ct >= bgmt) {
                        bgmt2 = bgmt;
                        mxin2 = mxin;
                        bgmt = ct;
                        mxin = cntb;
                    } else if(ct > bgmt2) {
                        bgmt2 = ct;
                        mxin2 = cntb;
                    }
                }
                ct = 0;
                inmode = true;
            }
        }
        if(!inmode) all[++cnta] = t;
        else {
            a[++cntb].s = t;
            for(_ i = 0; i < t.size(); ++i, ++a[cntb].f) if(t[i] == 'b') break;
            for(_ i = t.size()-1; i >= 0; --i, ++a[cntb].b) if(t[i] == 'b') break;
        }
        b = cntb;
    }
    if(k == 1) {
        _ s = solve(ans);
        if(bgmt > s) {
            cout << bgmt << '\n' << a[mxin+1].s;
        } else {
            cout << s << endl;
            for(_ i = 1; i <= ac; ++i) {
                cout << ans[i];
                if(i != ac) cout << '-';
            }
        }
    } else {
        _ o1 = solve(ans) + solve(ans), ac1 = ac;
        memset(v, 0, sizeof v);
        ac = fld = 0;
        b = cntb;
        _ o2 = solve(s) + bgmt, ac2 = ac;
        memcpy(v2, v, sizeof v2);
        _ o3 = bgmt + bgmt2;
        _ o4 = -1E12, o5 = -1E12, o6 = -1E12, ac3 = 0, ac32 = 0, ac33 = 0, cmx1 = 0, cmx2 = 0, cmx3 = 0, inde1 = 0, inde2 = 0, inde3 = 0;
        bool noti1 = false, noti2 = false, noti3 = false;
        b = cntb-1;
        if(~b) {
            for(_ i = 1; i <= cntb; ++i) if(a[i].f+a[i].b >= cmx1) {
                cmx3 = cmx2;
                inde3 = inde2;
                cmx2 = cmx1;
                inde2 = inde1;
                cmx1 = a[i].f+a[i].b;
                inde1 = i;
            } else if(a[i].f+a[i].b >= cmx2) {
                cmx3 = cmx2;
                inde3 = inde2;
                cmx2 = a[i].f+a[i].b;
                inde2 = i;
            } else if(a[i].f+a[i].b > cmx1) {
                cmx1 = a[i].f+a[i].b;
                inde1 = i;
            }
            memset(v, 0, sizeof v);
            ac = fld = noti = 0;
            b = cntb-1;
            v[inde1] = true;
            o4 = solve(ns) + cmx1;
            ac3 = ac;
            noti1 = noti;
            memset(v, 0, sizeof v);
            ac = fld = noti = 0;
            b = cntb-1;
            v[inde2] = true;
            o5 = solve(ns1) + cmx2;
            ac32 = ac;
            noti2 = noti;
            memset(v, 0, sizeof v);
            ac = fld = noti = 0;
            b = cntb-1;
            v[inde3] = true;
            o6 = solve(ns2) + cmx3;
            ac33 = ac;
            noti3 = noti;
        }
        if(o1 >= o2 && o1 >= o3 && o1 >= o4 && o1 >= o5 && o1 >= o6) {
            cout << o1 << endl;
            for(_ i = 1; i <= ac1; ++i) {
                cout << ans[i];
                if(i != ac1) cout << '-';
            }
        } else if(o2 >= o3 && o2 >= o4 && o2 >= o5 && o2 >= o6) {
            cout << o2 << endl;
            for(_ i = 1; i <= ac2; ++i) {
                cout << s[i];
                if(i != ac2) cout << '-';
            }
            if(!v2[mxin+1]) cout << '-' << a[mxin+1].s;
        }
        else if(o3 >= o4 && o3 >= o5 && o3 >= o6) {
            cout << o3 << endl;
            if(mxin == mxin2) cout << a[mxin+1].s;
            else cout << a[mxin+1].s << '-' << a[mxin2+1].s;
        } else if(o4 >= o5 && o4 >= o6) {
            cout << o4 << endl;
            if(noti1) {
                for(_ i = 1; i <= ac3-1; ++i) cout << ns[i] << '-';
                cout << a[inde1].s << '-' << ns[ac3];
            } else {
                if(ac3 >= 1) cout << ns[1] << '-';
                cout << a[inde1].s;
                if(ac3 >= 2) cout << '-';
                for(_ i = 2; i <= ac3; ++i) {
                    cout << ns[i];
                    if(i != ac3) cout << '-';
                }
            }
        } else if(o5 >= o6) {
            cout << o5 << endl;
            if(noti2) {
                for(_ i = 1; i <= ac32-1; ++i) cout << ns1[i] << '-';
                cout << a[inde2].s << '-' << ns1[ac32];
            } else {
                if(ac32 >= 1) cout << ns1[1] << '-';
                cout << a[inde2].s;
                if(ac32 >= 2) cout << '-';
                for(_ i = 2; i <= ac32; ++i) {
                    cout << ns1[i];
                    if(i != ac32) cout << '-';
                }
            }
        } else {
            cout << o6 << endl;
            if(noti3) {
                for(_ i = 1; i <= ac33-1; ++i) cout << ns2[i] << '-';
                cout << a[inde3].s << '-' << ns2[ac33];
            } else {
                if(ac33 >= 1) cout << ns2[1] << '-';
                cout << a[inde3].s;
                if(ac33 >= 2) cout << '-';
                for(_ i = 2; i <= ac33; ++i) {
                    cout << ns2[i];
                    if(i != ac33) cout << '-';
                }
            }
        }
    }
    cout << endl;
    
    return 0;
}

_ solve(str (&ans)[maxn]) {
    _ rv = 0;
    if(!b) {
        rv += fill(ans);
        return rv;
    }
    if(b == 1) {
        key only;
        b = 0;
        for(_ i = 1; i <= cntb; ++i) if(!v[i]) {
            only = a[i];
            v[i] = true;
            break;
        }
        if(only.f > only.b) {
            noti = true;
            rv += only.f;
            rv += fill(ans);
            ans[++ac] = only.s;
            return rv;
        } else {
            rv += only.b;
            ans[++ac] = only.s;
            rv += fill(ans);
            return rv;
        }
    }
    if(b == 2) {
        key x, y;
        bool oa = true;
        for(_ i = 1; i <= cntb; ++i) if(!v[i]) {
            v[i] = true;
            if(oa) {
                x = a[i];
                oa = false;
            } else {
                y = a[i];
                break;
            }
        }
        b = 0;
        if(x.b+y.f > y.b+x.f) {
            rv += x.b+y.f;
            ans[++ac] = x.s;
            rv += fill(ans);
            ans[++ac] = y.s;
            return rv;
        } else {
            rv += y.b+x.f;
            ans[++ac] = y.s;
            rv += fill(ans);
            ans[++ac] = x.s;
            return rv;
        }
    }
    _ fa, fb, ba, bb;
    fa = fb = ba = bb = -1;
    for(_ i = 1; i <= cntb; ++i) if(!v[i]) {
        if(!~fa || a[i].f >= a[fa].f) {
            fb = fa;
            fa = i;
        } else if(!~fb || a[i].f > a[fb].f) fb = i;
        if(!~ba || a[i].b >= a[ba].b) {
            bb = ba;
            ba = i;
        } else if(!~bb || a[i].b > a[bb].b) bb = i;
    }
    b -= 2;
    if(fa != ba) {
        v[fa] = v[ba] = true;
        rv += a[fa].f + a[ba].b;
        ans[++ac] = a[ba].s;
        rv += fill(ans);
        ans[++ac] = a[fa].s;
        return rv;
    } else {
        if(a[fa].f + a[bb].b > a[fb].f + a[ba].b) {
            v[fa] = v[bb] = true;
            rv += a[bb].b + a[fa].f;
            ans[++ac] = a[bb].s;
            rv += fill(ans);
            ans[++ac] = a[fa].s;
            return rv;
        } else {
            v[fb] = v[ba] = true;
            rv += a[ba].b + a[fb].f;
            ans[++ac] = a[ba].s;
            rv += fill(ans);
            ans[++ac] = a[fb].s;
            return rv;
        }
    }
}

_ fill(str (&ans)[maxn]) {
    if(fld) return 0;
    _ rv = 0;
    for(_ i = 1; i <= cnta; ++i) {
        rv += all[i].length();
        ans[++ac] = all[i];
    }
    fld = true;
    return rv;
}
