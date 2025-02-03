
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
#include <bitset>

#include <algorithm>
#include <numeric>
#define ef else if
#define el else

using namespace std;

typedef long long _;
typedef size_t st;
typedef string str;
typedef const long long constant;

map<str, map<str, str> > rec;
map<str, _> fc;
str cmd, fl, rl, dsc, dt, c, cr, cf, a[2];
vector<str> r, f;

int main() {
    
   // freopen("/Users/ryan/Desktop/debug/data.in", "r", stdin);
//    freopen("/Users/ryan/Desktop/debug/c8k.out", "w", stdout);
//
    for(; cin >> cmd && cmd != "done"; ) if(cmd == "rem") getline(cin, dsc);
    else {
        cin >> rl >> fl;
        r.clear();
        f.clear();
        if(rl == "*") for(map<str, map<str, str> >::iterator i = rec.begin(); i != rec.end(); ++i) r.push_back(i -> first);
        else {
            for(st i = rl.find(','); i != str::npos; i = rl.find(',')) {
                r.push_back(rl.substr(0, i));
                rl = rl.substr(i+1);
            }
            r.push_back(rl);
        }
        if(fl == "*") for(map<str, _>::iterator i = fc.begin(); i != fc.end(); ++i) f.push_back(i -> first);
        else {
            for(st i = fl.find(','); i != str::npos; i = fl.find(',')) {
                f.push_back(fl.substr(0, i));
                fl = fl.substr(i+1);
            }
            f.push_back(fl);
        }
        if(cmd == "show") {
            for(vector<str>::iterator i = r.begin(); i != r.end(); ++i) {
                cr = *i;
                for(vector<str>::iterator j = f.begin(); j != f.end(); ++j) {
                    cf = *j;
                    cout << cr <<'\n'<< cf << endl;
                    if(!rec[cr].count(cf)) cout << "NO DATA" << endl;
                    else cout << rec[cr][cf];
                    cout << '.' << endl;
                }
            }
            cout << '*' << endl;
        } ef(cmd == "append") {
            dt.clear();
            cin.ignore();
            for(; getline(cin, c) && c != "."; ) {
                dt += c;
                dt += '\n';
            }
            for(vector<str>::iterator i = r.begin(); i != r.end(); ++i) {
                cr = *i;
                if(!rec.count(cr)) rec[cr] = {};
                for(vector<str>::iterator j = f.begin(); j != f.end(); ++j) {
                    cf = *j;
                    if(!rec[cr].count(cf)) {
                        rec[cr][cf] = dt;
                        if(!fc.count(cf)) fc[cf] = 1;
                        else ++fc[cf];
                    }
                    else rec[cr][cf] += dt;
                }
            }
        } ef(cmd == "delete") for(vector<str>::iterator i = r.begin(); i != r.end(); ++i) {
            cr = *i;
            for(vector<str>::iterator j = f.begin(); j != f.end(); ++j) {
                if(!rec.count(cr)) break;
                cf = *j;
                if(rec[cr].count(cf)) {
                    rec[cr].erase(cf);
                    if(fc.count(cf) && !--fc[cf]) fc.erase(cf);
                }
                if(!rec[cr].size()) rec.erase(cr);
            }
        }
    }
    
    return 0;
}
