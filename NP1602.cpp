
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>

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

bool isdate(str no);
_ strtoint(str s);
str inttostr(_ s);

map<_, _> mtd = {{8, 31}, {1, 31}, {3, 31}, {5, 31}, {7, 31}, {10, 31}, {12, 31}, {4, 30}, {6, 30}, {9, 30}, {11, 30}};

int main(int argc, char * argv[]) {
    
    freopen("date.in", "r", stdin);
    freopen("date.out", "a", stdout);
    
    str start = "", end = ""; cin >> start >> end;
    _ si = strtoint(start), ei = strtoint(end);
    _ s = strtoint(start.substr(0, 4)), e = strtoint(end.substr(0, 4));
    
    _ ctr = 0;
    for(_ i = s; i <= e; i++) {
        str candstr = inttostr(i);
        reverse(candstr.begin(), candstr.end());
        _ cand = i * 10000 + strtoint(candstr);
        if(cand < si || cand > ei) continue;
        if(isdate(inttostr(i))) ctr++;
    } cout << ctr << endl;
    
    
    return 0;
    
}

bool isdate(str date) {
    
    _ idate = strtoint(date);
    bool leap = ((!(idate % 4) && idate % 100) || !(idate % 400));
    
    str month = date.substr(2, 2);
    reverse(month.begin(), month.end());
    _ imonth = strtoint(month);
    if(imonth < 1 || imonth > 12) return false;
    
    _ maxdays = (imonth == 2) ? ((leap) ? 29 : 28) : mtd[imonth];
    str day = date.substr(0, 2);
    reverse(day.begin(), day.end());
    _ iday = strtoint(day);
    if(iday < 1 || iday > maxdays) return false;
    
    return true;
}

_ strtoint(str s) {
    _ no = 0;
    _ size = s.length();
    for(_ i = 0; i < size; i++) {
        no *= 10; no += (_)s[i] - 48;
    }
    return no;
}

str inttostr(_ s) {
    str rv = "";
    while(s) {
        rv.push_back((char)(s % 10 + 48));
        s /= 10;
    }
    reverse(rv.begin(), rv.end());
    return rv;
}
