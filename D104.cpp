
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

_D a, b, c, discriminant; //big fancy word

int main(int argc, char * argv[]) {
    
    cin >> a >> b >> c;
    discriminant = b*b-4*a*c;
    if(discriminant < 0) {
        printf("None\n"); //why not use printf
    } else if(!discriminant) {
        printf("%.3f\n", -b/(2*a));
    } else {
        auto rootA = (-b+sqrt(discriminant))/(2*a), rootB = (-b-sqrt(discriminant))/(2*a);
        printf("%.3f\n%.3f\n", min(rootA, rootB), max(rootA, rootB));
    }
    
    return 0;
}

