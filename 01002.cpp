/*
 ID: ryanjzh1
 LANG: C++11
 TASK: tomato
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
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int o = 0;
    string::size_type cr = 0;
    string st = "";
    string ss = "";
    getline(cin, st);
    getline(cin, ss);
    
    while((cr = st.find(ss, cr)) != string::npos) {
        o++;
        cr++;
    }
    
    cout << o << endl;
    
    return 0;
    
}
