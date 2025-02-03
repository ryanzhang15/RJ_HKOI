
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

typedef pair<_, _> ticket;

_ n, ans;
deque<ticket> yhj;

bool getTicket(_ t, _ p);
int main(int argc, char * argv[]) {
    
    freopen("transfer.in", "r", stdin);
    freopen("transfer.out", "w", stdout);
    
    cin >> n;
    while(n --> 0) {
        _ a, b, c; cin >> a >> b >> c;
        if(!a) {
            ticket cur = {c+45, b};
            yhj.push_back(cur);
            ans += b;
        } else {
            if(getTicket(c, b)) continue;
            else ans += b;
        }
        //cout << ans << endl;
    }
    //cout << endl;
    cout << ans << endl;
    
    return 0;
}

bool getTicket(_ t, _ p) {
    if(yhj.empty()) return false;
    stack<ticket> pile;
    while(!yhj.empty()) {
        ticket cur = yhj.front(); yhj.pop_front();
        if(cur.first >= t && cur.second >= p) {
            while(!pile.empty()) {
                yhj.push_front(pile.top());
                pile.pop();
            }
            return true;
        }
        else if(cur.second < p) pile.push(cur);
    }
    while(!pile.empty()) {
        yhj.push_front(pile.top());
        pile.pop();
    }
    return false;
}
