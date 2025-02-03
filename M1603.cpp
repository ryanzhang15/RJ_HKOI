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
typedef float _D;
typedef string str;
typedef const long long constant;

str p;
bool sc;
_ cnt, ans, n;

int main(int argc, char * argv[]) {
    
    cin >> n; getchar();
    while(n--) {
        cnt = sc = 0;
        getline(cin, p);
        for(char i : p) {
            if(i == '>') {
                sc = true;
                cnt = 0;
            }
            else if(sc && i == '3') cnt++;
            else if(sc && i == '<') {
                ans += cnt;
                sc = false;
            } else if(sc) sc = 0;
        }
    }
    cout << ans << endl;
    
    return 0;
}

