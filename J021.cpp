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

struct dmy {
    _ day, month, year;
    str monthStr;
} dates[101];

_ n;
char discard;
str months;

bool cmp(dmy a, dmy b);
int main(int argc, char * argv[]) {
    
    cin >> n;
    for(_ i = 0; i < n; i++) {
        cin >> dates[i].day >> discard >> dates[i].monthStr >> dates[i].year;
        if(dates[i].monthStr == "January") dates[i].month = 1;
        if(dates[i].monthStr == "February") dates[i].month = 2;
        if(dates[i].monthStr == "March") dates[i].month = 3;
        if(dates[i].monthStr == "April") dates[i].month = 4;
        if(dates[i].monthStr == "May") dates[i].month = 5;
        if(dates[i].monthStr == "June") dates[i].month = 6;
        if(dates[i].monthStr == "July") dates[i].month = 7;
        if(dates[i].monthStr == "August") dates[i].month = 8;
        if(dates[i].monthStr == "September") dates[i].month = 9;
        if(dates[i].monthStr == "October") dates[i].month = 10;
        if(dates[i].monthStr == "November") dates[i].month = 11;
        if(dates[i].monthStr == "December") dates[i].month = 12;
    }
    
    sort(dates, dates+n, cmp);
    
    for(_ i = 0; i < n; i++) cout << dates[i].day << ", " << dates[i].monthStr <<' '<< dates[i].year << endl;

    return 0;
}

bool cmp(dmy a, dmy b) {
    if(a.year != b.year) return a.year < b.year;
    if(a.month != b.month) return a.month < b.month;
    return a.day < b.day;
}
