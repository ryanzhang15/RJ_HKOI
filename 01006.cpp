/*
ID: ryanjz2024
LANG: C++11
TASK: Octopus
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
typedef unsigned long long u_;
typedef long long _;
typedef size_t _t;
typedef double __;
typedef bool b_;
typedef int s_;
typedef unsigned int us_;
typedef short _s;
typedef unsigned short u_s;
typedef pair<s_, s_> p_s__;
typedef vector<s_> v_s__;
typedef vector<pair<s_, s_>> space;


int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0)
    
    s_ v = 0, tr = 0, ff = 0; cin >> v >> tr;
    while(tr --> 0) {
        s_ a; cin >> a; v -= a;
        if(v <= 0) {
            while(v <= 0) {
                ff++;
                v += 250;
            }
        }
    }
    
    cout << '$' << ff*250 << endl;
    
    return 0;
    
}

