/*
ID: ryanjz2024
LANG: C++11
TASK: story
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
    //cin.tie(0)ê
    
    vector<string> words = {};
    int WC = 5;
    while(WC --> 0) {
        string n; getline(cin , n); words.push_back(n);
    }
    
    cout << "I saw " << words[0] << " dating " << words[1] << " in a " << words[4] << " place selling " << words[2] << " while I was on a " << words[3] << '.' << endl;
    
    return 0;
    
}

