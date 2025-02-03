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

str text, front, data;
bool home;

int main(int argc, char * argv[]) {
        
    //tf is a beiju
    while(cin >> data) { //shady shady stuff
        for(char i : data) {
            if(i == '[' || i == ']') {
                text = front+text;
                front.clear();
                if(i == '[') home = true;
                else home = false;
            } else {
                if(home) front += i;
                else text += i;
            }
        }
        cout << front+text << endl;
        front.clear();
        text.clear();
    }
    
    return 0;
}

