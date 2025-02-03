/*
ID: ryanjz2024
LANG: C++11
TASK: napster
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
#include <list>

#include <algorithm>
#include <numeric>

using namespace std;
typedef unsigned int dex;
typedef long long fex;

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    
    string N = ""; getline(cin, N);
    string::iterator it = N.end() - 4;
    reverse(N.begin(), it);
    cout << N << endl;
    
    return 0;
    
}

