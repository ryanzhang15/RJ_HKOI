/*
ID: ryanjz2024
LANG: C++11
TASK: 3n+1
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
    
    int N; cin >> N; cout << N << endl;
    while (N != 1) {
        N = (N % 2 == 0) ? N / 2 : 3*N + 1;
        cout << N << endl;
    }
    
    return 0;
    
}

