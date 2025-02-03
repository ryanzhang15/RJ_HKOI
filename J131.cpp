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
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxm = 1E4+8;
struct node {
    _ id, choice;
} bucket[maxm];

_ n, m, pos[maxm], cnt;
bool flag;

bool cmp(node a, node b);
int main(int argc, char * argv[]) {
    
    cin >> n >> m;
    
    while(1) {
        if(flag) {
            cout << cnt << endl;
            for(_ i = 1; i <= m; ++i) cout << min(pos[i], n) <<' ';
            cout << endl;
            exit(0);
        }
        for(_ i = 1; i <= m; i++) {
            cin >> bucket[i].choice;
            bucket[i].id = i;
        }
        sort(bucket+1, bucket+1+m, cmp);
        for(_ i = 1; i <= m; i++) {
            if(bucket[i].choice == bucket[i-1].choice || bucket[i].choice == bucket[i+1].choice) continue;
            if((pos[bucket[i].id] += bucket[i].choice) >= n) flag = true;
        }
        cnt++;
    }
    
    return 0;
}

bool cmp(node a, node b) {
    return a.choice < b.choice;
}
