
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

_ a, b;

_ gcd(_ a, _ b);
int main(int argc, char * argv[]) {
    
    cin >> a >> b;
    _ g = gcd(a, b);
    cout << g << '\n' << a*b/g << endl;
    
    return 0;
}

//just your everyday gcd algorithm
_ gcd(_ a, _ b) {
    if(b != 0) return gcd(b, a%b);
    else return a;
}
