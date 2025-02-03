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
    
    int N = 0; cin >> N;
    
    for(dex i = 1; i <= N; i++) {
        int a = pow(i, 2);
        for(dex j = 0; j < N; j++) {
            cout << a+(i*j) << ' ';
        }
        cout << endl;
    }
    
    return 0;
    
}

