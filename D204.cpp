/*
ID: ryanjz2024
LANG: C++11
TASK: text_graphics
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

void dcout(int s, int se);

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    
    int N; cin >> N;
    int counter = -1;
    for(int i = (N - 1)/2; i > 0; i--) {
        dcout(i, counter);
        counter += 2;
    }
    for(int i = 0; i <= (N-1)/2; i++) {
        dcout(i, counter);
        counter -= 2;
    }
    
    
    return 0;
    
}

void dcout(int s, int se) {
    while(s --> 0) cout << ' ';
    cout << '#';
    if(se <= 0) {cout << '\n'; return;}
    while(se --> 0) cout << ' ';
    cout << '#' << '\n';
    return;
}
