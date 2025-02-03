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

str board[3];

bool checkForWin(char p);
int main(int argc, char * argv[]) {
    
    for(_ i = 0; i < 3; i++) cin >> board[i];
    if(checkForWin('X')) cout << "X wins" << endl;
    else if(checkForWin('O')) cout << "O wins" << endl;
    else {
        bool flag = false;
        for(_ i = 0; i < 3; i++) {
            for(_ j = 0; j < 3; j++)
                if(board[i][j] == '.') {
                    flag = true;
                    break;
                }
            if(flag) break;
        }
        if(flag) cout << "Not ended" << endl;
        else cout << "Draw" << endl;
    }
    
    return 0;
}

bool checkForWin(char p) {
    str win = "   ";
    win[0] = win[1] = win[2] = p;
    //rows;
    for(_ i = 0; i < 3; i++) if(board[i] == win) return true;
    //cols;
    for(_ i = 0; i < 3; i++) if(board[0][i] == p && board[1][i] == p && board[2][i] == p) return true;
    //diagonals;
    if(board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
    if(board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;
    return false;
}
