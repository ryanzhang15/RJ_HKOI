/*
ID: ryanjz2024
LANG: C++11
TASK: date_comparison
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
    
    vector<int> dates (6, 0);
     
    for(int i = 0; i < 6; i++) {
        cin >> dates[i];
    }
    
    for(int i = 0; i < 3; i++) {
        if(dates[i] < dates [i + 3]) {
            cout << "Before" << endl;
            exit(0);
        } else if(dates[i] > dates [i + 3]) {
            cout << "After" << endl;
            exit(0);
        }
    } cout << "Same" << endl;
    
    return 0;
    
}

