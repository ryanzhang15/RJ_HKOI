/*
 ID: ryanjz2024
 LANG: C++11
 TASK: napster
 */

#include <cstdlib>

#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>

#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>

#include <algorithm>
#include <numeric>

using namespace std;
typedef unsigned int dex;
typedef long long fex;

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    
    vector<int> factors = {0};
    scanf("%d", &factors[0]);
    int N = factors[0];
    int i = 0; bool d = true;
    while(d) {
        d = false;
        for(dex j = 2; j <= (dex)round(sqrt(factors[i])); j++) {
            if(!(factors[i] % j)) {
                factors.push_back(factors[i] / j);
                factors[i] = j;
                d = true;
                break;
            }
        }
        i++;
    }
    printf("%d=", N);
    for(fex j = 0; j < factors.size();j++) {
        if(j != 0 && factors[j]) {
            printf("*");
        } printf("%d", factors[j]);
    } printf("\n");
    
    return 0;
    
}


