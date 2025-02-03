
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

_ cnt = 0, a, b;

bool column[14], leftd[28], rightd[28];
_ q[14];

void dfs (_ row);
bool isvalid(_ i, _ j);

int main(int argc, char * argv[]) {
    
    cin >> a >> b;
    swap(a, b);
    a--;b--;
    q[a] = b;
    column[b] = true;
    leftd[a-b+8] = rightd[a+b] = true;
    
    dfs(0);
    
    return 0;
}

void dfs (_ row) {
    if(row == a) {
        dfs(row + 1);
        return;
    }
    if(row == 8) {
        for(_ i = 0; i < 8; i++) cout << q[i] + 1 << ' ';
        cout << endl;
        return;
    }
    for(_ i = 0; i < 8; i++) {
        if(isvalid(row, i)) {
            column[i] = leftd[row - i + 8] = rightd[row + i] = true;
            q[row] = i;
            dfs(row + 1);
            column[i] = leftd[row - i + 8] = rightd[row + i] = false;
        }
    }
    return;
}

bool isvalid(_ i, _ j) {
    return (!column[j] && !leftd[i - j + 8] && !rightd[i + j]);
}

