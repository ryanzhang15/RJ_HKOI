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

    int N = 0, T = 0, M = 0;
    cin >> N >> T >> M;
    
    vector<int> bg = {};
    vector<int> org = {};
    int s = 0, e = 0;
    
    for(int i = 0; i < M; i++) {
        int aff = 0;
        cin >> aff;
        org.push_back(aff);
    }
    
    sort(org.begin(), org.end());
    
    int a = 0, b = 0;
    for(int i = 0; i < M; i++) {
        a = b;
        b = org[i];
        if(i == 0) s = b - 1;
        if(i == M - 1) e = N - b;
        if(i != 0) bg.push_back(b - a - 1);
    }
    
    for(int j = 1; j <= T; j++) {
        int tot = 0;
        if(s > 0) {
            s--;
            tot++;
        }
        if(e > 0) {
            e--;
            tot++;
        }
        for(int i = 0; i < bg.size(); i++) {
            if(bg[i] > 1) {
                bg[i] -= 2;
                tot += 2;
            } else if(bg[i] == 1) {
                bg[i]--;
                tot++;
            }
        }
        M += tot;
        cout << M << endl;
    }
    
    return 0;
    
}
