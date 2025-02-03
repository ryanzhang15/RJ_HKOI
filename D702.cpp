/*
ID: ryanjz2024
LANG: C++11
TASK: stack
*/

#include <cstdlib>

#include <iostream>
#include <iomanip>
#include <fstream>

#include <string>
#include <cmath>

#include <vector>
#include <map>
#include <queue>
#include <stack>

#include <algorithm>
#include <numeric>

using namespace std;
typedef unsigned int dex;
typedef long long fex;

int main(int argc, char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    stack<int> s = {};
    int N; cin >> N;
    
    while(N --> 0) {
        string cmd; cin >> cmd;
        if(cmd == "PUSH") {
            int a; cin >> a;
            s.push(a);
        } else if(cmd == "POP") {
            if(s.empty()) {
                cout << "Cannot pop" << endl;
            } else {
                s.pop();
            }
        } else if(cmd == "TOP") {
            if(s.empty()) {
                cout << "Empty" << endl;
            } else {
                cout << s.top() << endl;
            }
        } else if(cmd == "SIZE") {
            cout << s.size() << endl;
        }
    }
    
}
