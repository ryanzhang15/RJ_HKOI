
/*
 ID: ryanjzh1
 LANG: C++11
 TASK: combo
 */

#include <cstdlib>

#include <iostream>
#include <fstream>

#include <string>
#include <cmath>

#include <vector>
#include <map>

#include <algorithm>
#include <numeric>

using namespace std;
typedef unsigned int dex;
typedef long long fex;

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    
    int N = 0;
    cin >> N;
    
    vector<int> c (N, 1);
    
    for(int i = 1; i <= N; i++) {
        for(int j = i - 1; j < N; j += i) {
            c[j] = (c[j] == 0) ? 1 : 0;
        }
    }
    
    cout << count(c.begin(), c.end(), 0) << endl;
    
    return 0;
    
}
