/*
 ID: ryanjz2024
 LANG: C++11
 TASK: queue
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

#include <algorithm>
#include <numeric>

using namespace std;
typedef unsigned int dex;
typedef long long fex;

int main(int argc, char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    queue<int> q; //c++ has built-in queue. beautiful.
    
    int N = 0; cin >> N;
    
    for(dex i = 0; i < N; i++) {
        string cmd = "";
        cin >> cmd;
        if(cmd == "PUSH") {
            int a = 0; cin >> a;
            q.push(a);
        } else if(cmd == "SIZE") {
            cout << q.size() << endl;
        } if(cmd == "POP") {
            if(q.empty()) {
                cout << "Cannot pop" << endl;
            } else {
                q.pop();
            }
        } if(cmd == "FRONT") {
            if(q.empty()) {
                cout << "Empty" << endl;
            } else {
                cout << q.front() << endl;
            }
        }
        
    }
    
    return 0;
    
}

