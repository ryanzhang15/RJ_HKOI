/*
ID: ryanjz2024
LANG: C++11
TASK: ordinals
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
    //cin.tie(0)
    
    string str = ""; cin >> str; string sfx = "";
    if(str.length() >= 2) {
        if((str[str.length()-1] == '1' || str[str.length()-1] == '2' || str[str.length()-1] == '3') && str[str.length()-2] == '1') {
            cout << str << "th" << endl;
            exit(0);
        }
    }
    if(str[str.length() - 1] == '1') {
        sfx = "st";
    } else if(str[str.length() - 1] == '2') {
        sfx = "nd";
    } else if(str[str.length() - 1] == '3') {
        sfx = "rd";
    } else {
        sfx = "th";
    } cout << str << sfx << endl;
    
}

