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

_ n;

int main(int argc, char * argv[]) {
    
    cin >> n; getchar();
    for(_ i = 1; i <= n; i++) {
        str a; getline(cin, a);
        str b, cmd, c;
        _ cnt = 0;
        for(char j : a) {
            b += j;
            if(j == '"') cnt++;
            if(cnt == 2) break;
        }
        cnt = 0;
        for(char j : a.substr(b.size())) {
            if(cmd == " Replace ") cnt -= 2;
            if(j == '"') cnt++;
            if(cnt == 1) break;
            cmd += j;
        }
        c = a.substr(b.size()+cmd.size());
        c = c.substr(1, c.size()-2);
        if(cmd == " Cut ") {
            _ pos = b.find(c);
            if(pos != str::npos) b.erase(pos, c.size());
            cout << "Command #" << i << ": " << b << endl;
        } else if(cmd == " Append ") {
            cout << "Command #" << i << ": " << b.substr(0, b.size()-1) << c << '"' << endl;
        } else if(cmd.substr(1, 6) == "Insert") {
            _ pos = 0;
            for(char j : cmd.substr(8)) {
                if(j != ' ') {
                    pos *= 10;
                    pos += j-'0';
                }
            }
            b.insert(pos, c);
            cout << "Command #" << i << ": " << b << endl;
        } else {
            str rs;
            for(char j : cmd.substr(10)) {
                if(j == '"') break;
                rs += j;
            }
            _ pos = b.find(rs);
            if(pos != str::npos) {
                b.replace(pos, rs.size(), c);
            }
            cout << "Command #" << i << ": " << b << endl;
        }
    }
    
    return 0;
}
