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

#include <algorithm>
#include <numeric>

using namespace std;
typedef unsigned int dex;
typedef long long fex;

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    
    int N; cin >> N; int no = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << no << ' ';
            no += 4;
        } cout << endl; no -= 4;
    }
    
    return 0;
    
}

