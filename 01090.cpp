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

set<_> students;
_ n;

int main(int argc, char * argv[]) {
    
    cin >> n;
    while(n--) {
        _ a; cin >> a;
        _ ps = students.size();
        students.insert(a);
        if(ps == students.size()) {
            cout << "out" << endl;
            students.erase(a);
        } else {
            cout << "in" << endl;
        }
    }
    
    return 0;
}

