#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
const int inf = 200;
int n,m;
int a[111];
int vis[111],b[111];
int s;
#define _ int
void recur(_ k, _ u, _ x) {
    if(u == n+1) {
        s = min(k, s);
        return;
    }
    int remain = 0;
    for (int i=1;i<=n;i++) if(!vis[i])remain+=a[i];
    int th = m-b[k];
    remain = max(0,remain-th);
    
    if(k + (remain+m-1)/m >= s) return;
    
    bool w = true;
    for ( _ i= 1;i<=n; ++i) {
        if (vis[i]) continue;
        if (b[k]+a[i]<=m) {
            w=false;
        }
    }
    if (w==false) {
        for(_ i = x; i <= n; ++i) {
            if(vis[i]) continue;
            vis[i] = true;
            if(b[k] + a[i] <= m) {
                b[k] += a[i];
                recur(k, u+1, i+1);
                b[k] -= a[i];
            }
            vis[i] = false;
        }
    } else {
        for(_ i = 1; i <= n && w; ++i)
            if(!vis[i]) {
                vis[i] = true;
                b[k+1] += a[i];
                recur(k+1, u+1, i+1);
                b[k+1] -= a[i];
                w = vis[i] = false;
            }
    }
    
    return;
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    
    sort(a+1,a+1+n); reverse(a+1,a+1+n);
    
    s=inf;
    vis[1]=true;
    b[1]+=a[1];
    recur(1,2,2);
    b[1]=0;
    vis[1]=0;
    
    printf("%d\n",s);
    return 0;
}


