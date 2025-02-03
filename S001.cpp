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

#define fs(str) (str).c_str()
#define _lin "%lli"
std::string _l = "%lli";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%llf";

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxk = 1E4+8;

_ k, m, dp[35][maxk], a[35];

void retrace(_ i, _ j);
void knapsack();
int main(int argc, char * argv[]) {
    
    //knapsack???
    
    scanf(_lin, &k);
    if(!k) {
        printf("\n\n");
        exit(0);
    } //they did say k might = 0;
    
    knapsack();
    printf("\n");
    knapsack();
    printf("\n");
    
    return 0;
}

void knapsack() {
    scanf(_lin, &m);
    for(_ i = 1; i <= m; i++) {
        scanf(_lin, &a[i]);
        for(_ j = 1; j <= k; j++) {
            if(a[i] > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]]+a[i]);
        }
    }
    //recursively retrace;
    retrace(m, k);
}

void retrace(_ i, _ j) {
    if(!dp[i][j]) return;
    if(dp[i][j] != dp[i-1][j]) {
        //this was picked
        printf(fs(_l+" "), a[i]);
        retrace(i-1, j-a[i]);
    } else retrace(i-1, j);
    return;
}
