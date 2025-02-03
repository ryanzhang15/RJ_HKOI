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
    
    map<bool, string> d = {{true, "Yes"}, {false, "No"}};
    
    int N = 0, Q = 0; cin >> N >> Q;
    
    vector<int> v = {}, b = {};
    
    while(N --> 0) {
        int a; cin >> a; v.push_back(a);
    }
    while(Q --> 0) {
        int a; cin >> a; b.push_back(a);
    }
    for(int i = 0; i < b.size(); i++) {
        cout << d[binary_search(v.begin(), v.end(), b[i])] << endl;
    }
    
    return 0;
    
}

