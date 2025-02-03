#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <deque>
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
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

str ting;
_ ec;

int main(int argc, char * argv[]) {
    
    getline(cin, ting);
    if(count(ting.begin(), ting.end(), ',') != 5) cout << "Invalid" << endl;
    else {
        bool isEmpty = true;
        for(char i : ting) {
            if(i == ',') {
                if(isEmpty) ec++;
                isEmpty = true;
            } else {
                if(i != ' ' && i != '\t') isEmpty = false;
            }
        }
        if(isEmpty) ec++;
        cout << ec << endl;
    }
    
    return 0;
}

