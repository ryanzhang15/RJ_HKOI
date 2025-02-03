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

_ q, cur;
bool blocks[2][10];

int main(int argc, char * argv[]) {
    
    for(_ i = 0; i <= 1; i++) //very sad for loop
        for(_ j = 0; j < 6; j++) {
            _ a; cin >> a;
            blocks[i][a] = true;
            if(a == 6) blocks[i][9] = true;
            if(a == 9) blocks[i][6] = true;
        }
    
    cin >> q;
    for(; q--; ) { //i only use for loops now
        cin >> cur;
        if((blocks[0][cur%10] && blocks[1][cur/10]) || (blocks[1][cur%10] && blocks[0][cur/10])) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}
