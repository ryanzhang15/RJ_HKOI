/*
ID: ryanjz2024
LANG: C++11
TASK: enumeration
*/

#include <cstdlib>

#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>

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
typedef unsigned int dex;
typedef long long fex;

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    
    vector<int> nos = {};
    
    int N; cin >> N;
    while(N --> 0) {
        int a; cin >> a; nos.push_back(a);
        sort(nos.begin(), nos.end());
        for(auto it : nos) {
            cout << it << ' ';
        } cout << endl;
    }
    
    return 0;
    
}

