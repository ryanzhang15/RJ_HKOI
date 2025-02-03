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

str hkid;
_ sum;

int main(int argc, char * argv[]) {
    
    cin >> hkid;
    if(hkid.length() == 8) sum += (9*(hkid[0]-'A'+10)%11 + 8*(hkid[1]-'A'+10)%11)%11;
    else sum += 5 + 8*(hkid[0]-'A'+10)%11;
        
    for(_ i = hkid.length()-1, j = 2; hkid[i] >= '0' && hkid[i] <= '9'; i--, j++) {
        sum = (sum + (hkid[i]-'0')*j)%11;
    }
    
    sum %= 11;
    
    if(sum == 1) cout << hkid << "(A)" << endl;
    else cout << hkid << '(' << (11-sum)%11 << ')' << endl;
    
    return 0;
}

