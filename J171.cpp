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

str a, c;
_ n, al;

int main(int argc, char * argv[]) {
    
    cin >> a >> n;
    a = a + '@';
    getchar_unlocked();
    while(n--) {
        al = 0;
        getline(cin, c);
        bool nw = true;
        for(char &i : c) {
            if(nw && toupper(i) == a[al]) {
                i = toupper(i);
                al++;
            } else {
                i = tolower(i);
            }
            if(i == ' ') nw = true;
            else nw = false;
        }
        if(al == a.length()-1) cout << c << endl;
        else cout << "No :(" << endl;
    }
    
    
    return 0;
}

