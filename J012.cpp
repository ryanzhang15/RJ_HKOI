/*
ID: ryanjz2024
LANG: C++11
TASK: queue
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

#include <algorithm>
#include <numeric>

using namespace std;
typedef unsigned int dex;
typedef long long fex;

string c(string n, int p);
string inc(string n);

int main(int argc, char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int N = 0; cin >> N;
    string n = ""; cin >> n;
    string str (N, '0');
    
    for(dex i = 0; i < pow(2, N); i++) {
        cout << n << endl;
        str = inc(str);
        int chasf = 0;
        for(dex j = 0; j < str.length(); j++) {
            if(str[j] == '1') {chasf = j; break;}
        }
        n = c(n, chasf);
    }
    
    return 0;
    
}

string c(string n, int p) {
    map<char, char> k = {{'1', '0'}, {'0', '1'}};
    n[p] = k[n[p]];
    return n;
}

string inc(string n) {
    int ctr = 0;
    while(ctr < n.length()) {
        if(n[ctr] == '0') {n[ctr] = '1'; break;}
        ctr++;
    }
    for(dex i = 0; i < ctr; i++) n[i] = '0';
    return n;
}
