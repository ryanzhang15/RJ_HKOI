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

#define fs(str) (str).c_str()
#define _lin "%lli"
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%llf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

_ n, l;
vector<_> s, us;

int main(int argc, char * argv[]) {
    
    cin >> n >> l;
    for(_ i = 0; i < n; i++) {
        _ a; cin >> a;
        s.push_back(a);
    }
    us = s;
    sort(us.begin(), us.end());
    if(s == us && l == n) {
        cout << "No solution" << endl;
        exit(0);
    }
    if(us != s) {
        //already not in ascending order.
        //just tag on a buncha ones.
        for(_ i = 0; i < l-n; i++) cout << "1 ";
        for(_ i : s) cout << i << ' ';
        cout << endl;
        exit(0);
    }
    //in ascending order. Try to insert a one after \
        a number that isn't one. Unless they're all ones.
    for(_ i = 0; i < s.size(); i++) {
        if(s[i] > 1) {
            for(_ i = 0; i < l-n-1; i++) cout << "1 ";
            vector<_>::iterator it = s.begin();
            s.insert(it+i+1, 1);
            for(_ i : s) cout << i << ' ';
            cout << endl;
            exit(0);
        }
    }
    
    //if you're still here...
    for(_ i = 0; i < l-2; i++) cout << "1 ";
    cout << "2 1" << endl;
    
    //some very sloppy code
    
    return 0;
}
