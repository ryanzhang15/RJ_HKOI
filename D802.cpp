
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
typedef double _D;
typedef string str;
typedef const long long constant;

constant maxn = 2E3+88;

_ n, state, data[maxn], sc;
int main(int argc, char * argv[]) {
   
    cin >> n >> state;
    for(_ i = 0; i < n; i++) cin >> data[i];
    
    //illegal
    ///but so much easier
    /*
    if(state) sort(data, data+n);
    else sort(data, data+n, greater<_>());
     */
    ///also faster because can use quicksort
    
    for(_ i = 0; i < n-1; i++) {
        for(_ j = 0; j < n-i-1; j++) {
            if(!state) {
                if(data[j] > data[j+1]) {
                    swap(data[j], data[j+1]);
                    sc++;
                }
            } else {
                if(data[j] < data[j+1]) {
                    swap(data[j], data[j+1]);
                    sc++;
                }
            }
        }
    }
    
    cout << sc << endl;
    for(_ i = 0; i < n; i++) cout << data[i] << ' ';
    cout << endl;
    
    return 0;
}

