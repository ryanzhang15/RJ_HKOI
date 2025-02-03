
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>

#include <algorithm>
#include <numeric>

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef double _D;
typedef string str;
typedef const long long constant;

constant maxn = 1E6+2;

struct treeNode {
    _ houdai = 0;
    _ data;
    _ left;
    _ right;
} tree[maxn];

_ n, jiadp[maxn], ans;

bool dfs(_ l, _ r);
void dfs(_ point);
int main(int argc, char * argv[]) {
    
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "a", stdout);
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    if(!n) {
        cout << 0 << endl;
        exit(0);
    }
    
    for(_ i = 1; i <= n; i++) {
        cin >> tree[i].data;
    }
    for(_ i = 1; i <= n; i++) {
        cin >> tree[i].left >> tree[i].right;
    }
    dfs(1);
    
    for(_ i = 1; i <= n; i++) {
        if(dfs(tree[i].left, tree[i].right)) {
            ans = max(ans, tree[i].houdai);
        }
    }
    cout << ans << endl;
    
    return 0;
}

void dfs(_ point) {
    tree[point].houdai = 1;
    if(tree[point].left != -1) {
        dfs(tree[point].left);
        tree[point].houdai += tree[tree[point].left].houdai;
    }
    if(tree[point].right != -1) {
        dfs(tree[point].right);
        tree[point].houdai += tree[tree[point].right].houdai;
    }
    return;
}

bool dfs(_ l, _ r) {
    if(tree[l].data != tree[r].data) return false;
    else if(l == -1 and r == -1) return true;
    else return(dfs(tree[l].left, tree[r].right) && dfs(tree[r].left, tree[l].right));
}
