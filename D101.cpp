/*
ID: ryanjz2024
LANG: C++11
TASK: phone_number
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
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    string n = ""; cin >> n;
    string dec = (n[0] == '2' || n[0] == '3') ? "Fixed" : "Mobile";
    cout << dec << endl;
    
    return 0;
}
