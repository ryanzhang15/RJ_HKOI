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

constant maxw = 1E4+8;

_ n, m, c;
map<str, str> data;
str sentence[maxw];

int main(int argc, char * argv[]) {
    
    cin >> n;
    while(n--) {
        str a, b; cin >> a >> b;
        data[a] = b;
    }
    cin >> m;
    while(m--) {
        memset(sentence, 0, sizeof(sentence));
        getchar();
        c = 0;
        while(true) {
            char a = getchar();
            if(a == '\n') break;
            if(a == ' ')  c++;
            else sentence[c] += a;
        }
        str ka, kb; cin >> ka >> kb;
        for(char i : kb) {
            _ pos = find(ka.begin(), ka.end(), i)-ka.begin();
            if(data.find(sentence[pos]) == data.end()) {
                cout << sentence[pos] << ' ';
            } else {
                cout << data[sentence[pos]] << ' ';
            }
        }
        cout << endl;
    }
    
    return 0;
}

