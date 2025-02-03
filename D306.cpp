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

str email;

int main(int argc, char * argv[]) {
    
    //gonna use goto just to test it out
    cin >> email;
    str user = email.substr(0, email.find('@')), host = email.substr(email.find('@')+1);
    if(count(email.begin(), email.end(), '@') > 1 || !count(email.begin(), email.end(), '@')) goto invalid;
    if(user.empty() or host.size() < 3) goto invalid;
    if(user.find("..") != string::npos or user[0] == '.' or user[user.size()-1] == '.') goto invalid;
    for(char i : user)
        if(!(i >= '0' && i <= '9') && !(i >= 'a' && i <= 'z') && !(i >= 'A' && i <= 'Z') && i != '+' && i != '.') goto invalid;
    if(host.find("..") != string::npos or host[0] == '.' or host[host.size()-1] == '.') goto invalid;
    for(char i : host)
        if(!(i >= '0' && i <= '9') && !(i >= 'a' && i <= 'z') && !(i >= 'A' && i <= 'Z') && i != '-' && i != '.') goto invalid;
    if(host.find(".") == string::npos || host.find("-.") != string::npos || host.find(".-") != string::npos) goto invalid;
    
    cout << "Valid" << endl;
    return 0;
    
    invalid:
    cout << "Invalid" << endl;
    return 0;
}

