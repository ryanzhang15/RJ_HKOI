/*
ID: ryanjz2024
LANG: C++11
TASK: bus_fare
*/

#include <cstdlib>

#include <iostream>
#include <iomanip>
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

    double a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    cout << fixed << setprecision(3);
    cout << 0.5f * a * b * sin(c * M_PI / 180) << endl;
    
    return 0;
    
}
