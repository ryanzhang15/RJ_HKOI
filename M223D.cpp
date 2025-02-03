#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <random>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <unordered_map>
#include <bitset>
#include <string>
#include <stack>
#include <unordered_set>
#include <vector>
#include <map>

#define ef else if
#define mp(x, y) make_pair(x, y)
#define pr(x, y) pair< x, y >

using namespace std;

typedef long long _;
typedef long long ll;
typedef int _0;
typedef double _D;
typedef string str;
typedef const long long constant;

inline _ read() {
    _ x = 0, d = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') d *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*d;
}

ll n,m,c,ans,at;
struct board{
    ll t,l,r;
}t[100005];

int main() {
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++){
        cin>>t[i].t;
    }
    for(int i=1;i<=n;i++){
        cin>>t[i].l>>t[i].r;
    }
    for(int i=1;i<=n;i++){
        if(c<=t[i].r&&c>=t[i].l){
            at+=t[i].t;
            continue;
        }
        if(c<t[i].l){
            if(t[i].l-c>t[i].t+at){
                cout<<"No";
                return 0;
            }
            else{
                ans+=t[i].l-c;
            }
            if(t[i].l-c>t[i].t){
                at-=t[i].l-c-t[i].t;
            }
            else{
                at+=t[i].t-(t[i].l-c);
            }
        }
        ef(c>t[i].r){
            if(c-t[i].r>t[i].t+at){
                cout<<"No";
                return 0;
            }
            else{
                ans+=c-t[i].r;
            }
            if(c-t[i].r>t[i].t){
                at-=c-t[i].r-t[i].t;
            }
            else{
                at+=t[i].t-(c-t[i].r);
            }
        }
    }
    cout<<"Yes"<<endl;
    cout<<ans;
    return 0;
}
