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

str a, b;
str A, B;
_0 strcmp(str a, str b);
int main(int argc, char * argv[]) {
    
    cin >> a >> b; A = a; B = b;
    for(char & i : a) i = tolower(i);
    for(char & i : b) i = tolower(i);
    for(_ i = a.size()-1; i >= 0; i--) {
        if(!(a[i] >= 'a' && a[i] <= 'z')) a.pop_back();
        else break;
    }
    for(_ i = b.size()-1; i >= 0; i--) {
        if(!(b[i] >= 'a' && b[i] <= 'z')) b.pop_back();
        else break;
    }
    _ state = strcmp(a, b);
    if(state == 1) cout << A << " is greater than " << B << endl;
    else if(!state) cout << A << " is equal to " << B << endl;
    else cout << A << " is less than " << B << endl;
    
    return 0;
}

_0 strcmp(str a, str b) {
    _ i = 0, j = 0;
    while(i < a.length() && j < b.length()) {
        if(!(a[i] >= 'a' && a[i] <= 'z')) {i++; continue;}
        if(!(b[j] >= 'a' && b[j] <= 'z')) {j++; continue;}
        if(a[i] != b[j]) {
            if(a[i] < b[j]) return -1;
            else            return  1;
        } else {
            i++; j++;
        }
    }
    if(i < a.length()) return  1;
    if(j < b.length()) return -1;
    return 0;
}
