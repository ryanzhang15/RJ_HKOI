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

str board[25];
_ n, tx, ty, bx, by;
char marker;

int main(int argc, char * argv[]) {
    
    //why r they making me draw rectangles
    //just why
    for(_ i = 0; i < 25; i++) board[i] = str (80, ' ');
    
    cin >> n;
    while(n--) {
        getchar();
        marker = getchar();
        cin >> tx >> ty >> bx >> by;
        //figure out the frame first;
        for(_ i = tx; i <= bx; i++) {
            board[ty][i] = marker;
            board[by][i] = marker;
        }
        for(_ i = ty+1; i <= by-1; i++)
            for(_ j = tx; j <= bx; j++) {
                if(j == tx || j == bx) board[i][j] = marker;
                else board[i][j] = ' ';
            }
    }
    
    for(_ i = 0; i < 25; i++) cout << board[i] << endl;
    
    return 0;
}
