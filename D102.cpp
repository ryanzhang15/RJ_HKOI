/*
ID: ryanjz2024
LANG: C++11
TASK: bus_fare
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
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);

    double f = 0;
    getchar();
    cin >> f;
    f *= 5;
    f = round(f);
    cout << '$' << f / 10.0f;
    if(f/10 == round(f/10)) cout << ".0";
    cout << endl;
    
    return 0;
    
}
