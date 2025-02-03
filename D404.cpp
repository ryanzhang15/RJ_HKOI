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

constant maxn = 1E2+8;

_D theMatrix[maxn][maxn];
_ Neo, Morpheus;

int main(int argc, char * argv[]) {
    
    cout << fixed << setprecision(1);
    
    cin >> Neo;
    for(_ i = 1; i <= Neo; i++)
        for(_ j = 1; j <= Neo; j++)
            cin >> theMatrix[i][j];
    cin >> Morpheus;
    while(Morpheus--) {
        _ a, b;
        char Trinity;
        cin >> a >> b >> Trinity;
        if(Trinity == 'A') cout << theMatrix[min(a, b)][max(a, b)] << endl;
        else               cout << theMatrix[max(a, b)][min(a, b)] << endl;
    }
    
    //im weird;
    
    return 0;
}
