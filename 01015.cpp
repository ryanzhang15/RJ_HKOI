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

bool inbalance;
map<char, _> k = {{'(', 0}, {'[', 1}, {'{', 2}};
map<char, char> match = {{')', '('}, {']', '['}, {'}', '{'}};
_ f[3];
str n;

bool check(str n);
int main(int argc, char * argv[]) {
    
    getline(cin, n);
    if(check(n)) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}

bool check(str n) {
    stack<char> s;
    for(char i : n) {
        if(i != '(' && i != '[' && i != '{' && i != ')' && i != ']' && i != '}') continue;
        if(i == '(' || i == '[' || i == '{') {
            s.push(i);
            continue;
        }
        if(s.empty()) return false;
        if(s.top() != match[i]) return false;
        s.pop();
    }
    return s.empty();
}
