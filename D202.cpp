/*
ID: ryanjz2024
LANG: C++11
TASK: factors
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
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    
    int N = 0; cin >> N;
    vector<int> sol = {};
    for(int i = 1; i <= (int)ceil(sqrt(N)); i++) if(N % i == 0) {sol.push_back(i); sol.push_back(N/i);}
    sort(sol.begin(), sol.end());
    cout << sol[0] << endl;
    for(int i = 1; i < sol.size(); i++) {
            if(sol[i] != sol[i - 1]) cout << sol[i] << endl;
    }
    
    return 0;
}
