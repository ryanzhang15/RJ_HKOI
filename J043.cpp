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

struct node {
    _ x, y, dir, steps;
    //for dir, 0 = up, 1 = down, 2 = left, 3 = right \
    //4 = up left, 5 = up right, 6 = down left, 7 = down right;
};

char board[8][8];
_ ans, dx[] = {-1, 1, 0, 0, -1, -1, 1, 1}, dy[] = {0, 0, -1, 1, -1, 1, -1, 1}, score[8][8];
queue<node> q;

int main(int argc, char * argv[]) {
    
    for(_ i = 0; i < 8; i++)
        for(_ j = 0; j < 8; j++) cin >> board[i][j];
    for(_ i = 0; i < 8; i++)
        for(_ j = 0; j < 8; j++)
            if(board[i][j] == 'B') {
                if(i-1 >= 0 and board[i-1][j] == 'W') q.push({i, j, 1, 0});
                if(i+1 < 8  and board[i+1][j] == 'W') q.push({i, j, 0, 0});
                if(j-1 >= 0 and board[i][j-1] == 'W') q.push({i, j, 3, 0});
                if(j+1 < 8  and board[i][j+1] == 'W') q.push({i, j, 2, 0});
                if(i-1 >= 0 and j-1 >= 0 and board[i-1][j-1] == 'W') q.push({i, j, 7, 0});
                if(i-1 >= 0 and j+1 < 8  and board[i-1][j+1] == 'W') q.push({i, j, 6, 0});
                if(i+1 < 8  and j-1 >= 0 and board[i+1][j-1] == 'W') q.push({i, j, 5, 0});
                if(i+1 < 8  and j+1 < 8  and board[i+1][j+1] == 'W') q.push({i, j, 4, 0});
            }
    //now that our queue is full,
    //BFS
    while(!q.empty()) {
        node temp = q.front(); q.pop();
        temp.x += dx[temp.dir];
        temp.y += dy[temp.dir];
        temp.steps++;
        if(temp.x < 0 || temp.y < 0 || temp.x >= 8 || temp.y >= 8) continue;
        if(board[temp.x][temp.y] == '.') {
            score[temp.x][temp.y] += temp.steps;
            ans = max(ans, score[temp.x][temp.y]);
        }
        else q.push(temp);
    }
    
    cout << ans << endl;
    
    return 0;
}
