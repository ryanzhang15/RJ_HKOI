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

_ bad[2018][3];

int main(int argc, char * argv[]) {
    
    bad[2017][0] = 53; bad[2017][1] = 35; bad[2017][2] = 26;
    bad[2016][0] = 55; bad[2016][1] = 21; bad[2016][2] = 13;
    bad[2015][0] = 42; bad[2015][1] = 39; bad[2015][2] =  9;
    bad[2014][0] = 36; bad[2014][1] = 32; bad[2014][2] =  8;
    bad[2013][0] = 31; bad[2013][1] = 31; bad[2013][2] = 26;
    bad[2012][0] = 37; bad[2012][1] = 20; bad[2012][2] = 17;
    bad[2011][0] = 32; bad[2011][1] = 25; bad[2011][2] = 23;
    bad[2010][0] = 28; bad[2010][1] = 20; bad[2010][2] = 16;
    bad[2009][0] = 36; bad[2009][1] = 28; bad[2009][2] = 13;
    bad[2008][0] = 30; bad[2008][1] = 29; bad[2008][2] = 11;
    bad[2007][0] = 41; bad[2007][1] = 19; bad[2007][2] =  8;
    bad[2006][0] = 40; bad[2006][1] = 22; bad[2006][2] = 13;
    bad[2005][0] = 25; bad[2005][1] = 17; bad[2005][2] = 12;
    bad[2004][0] = 19; bad[2004][1] = 15; bad[2004][2] = 13;
    bad[2003][0] = 18; bad[2003][1] = 12; bad[2003][2] = 12;
    bad[2002][0] = 17; bad[2002][1] = 13; bad[2002][2] =  8;
    bad[2001][0] = 13; bad[2001][1] = 11; bad[2001][2] = 10;
    bad[2000][0] = 14; bad[2000][1] =  9; bad[2000][2] =  8;
    
    //this took so long
    
    _ yr; cin >> yr;
    cout << bad[yr][0] <<' '<< bad[yr][1] <<' '<< bad[yr][2] << endl;
    
    
    
    return EXIT_SUCCESS;
}
