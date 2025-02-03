/*
ID: ryanjz2024
LANG: C++11
TASK: word_puzzle
*/

//I was left no choice, but...
//  to use recursion. >_<

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

vector<vector<pair<int, int>>> dir (8, {{-999, -999}});
vector<vector<pair<int, int>>> fir (8, {{-999, -999}});

vector<pair<int, int>> l_a (char t, int b, vector<string> g, int x, int y, bool ft);
vector<pair<int, int>> l_c (vector<string> g, string lf, vector<pair<int, int>> plc, int b);

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0);
    
    vector<pair<int, int>> locs = {};

    int N = 0;
    cin >> N;
    
    vector<string> g = {};
    for(int i = 0; i < N; i++) {
        string a = {};
        cin >> a;
        g.push_back(a);
    }
    
    string lf = "";
    cin >> lf;
    
    if(lf.size() == 1) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(g[i][j] == lf[0]) {
                    locs.push_back(make_pair(i, j));
                }
            }
        }
        cout << locs.size() << endl;
        for(fex i = 0; i < locs.size(); i++) {
            cout << locs[i].first + 1 << ' ' << locs[i].second + 1 << endl;
        }
        exit(0);
    }
    
    string llf (lf.size() - 1, ' ');
    for(int i = 1; i < lf.length(); i++) {
        llf[i - 1] = lf[i];
    }
    
    pair<int, int> t_bool = {1, 1};
    pair<int, int> f_bool = {0, 0};
    
    vector<pair<int, int>> starting;
    starting.push_back(make_pair(0, 0));
    starting.push_back(make_pair(0, 0));
    
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(g[i][j] == lf[0]) {
                starting[1] = make_pair(i, j);
                auto check = l_c(g, llf, starting, N)[0];
                if(check == t_bool) {
                    locs.push_back(make_pair(i, j));
                }
                dir.clear();
                dir = fir;
            }
        }
    }
    
    cout << locs.size() << endl;
    for(fex i = 0; i < locs.size(); i++) {
        cout << locs[i].first + 1 << ' ' << locs[i].second + 1 << endl;
    }
    
    return 0;
    
}

vector<pair<int, int>> l_c (vector<string> g, string lf, vector<pair<int, int>> plc, int b) {
    //base case
    if(plc[0].second == lf.length() - 1) {
        for(fex i = 1; i < plc.size(); i++) {
            bool ft = (plc[0].second == 0) ? true : false;
            if(l_a(lf[lf.length() - 1], b, g, plc[i].first, plc[i].second, ft)[0].second > 0) {
                vector<pair<int, int>> ffff;
                ffff.push_back(make_pair(1, 1));
                return ffff;
            }
        }
        vector<pair<int, int>> ffff;
        ffff.push_back(make_pair(0, 0));
        return ffff;
    }
    vector<pair<int, int>> rv = {};
    rv.push_back(make_pair(0, plc[0].second + 1));
    for(int i = 1; i < plc.size(); i++) {
        bool ft = (plc[0].second == 0) ? true : false;
        auto fsitc = l_a(lf[plc[0].second], b, g, plc[i].first, plc[i].second, ft);
        if(fsitc[0].second == 0) continue;
        for(int j = 1; j < fsitc.size(); j++) {
            rv.push_back(fsitc[j]);
        }
    }
    return l_c(g, lf, rv, b);
}

vector<pair<int, int>> l_a (char t, int b, vector<string> g, int x, int y, bool ft) {
    vector<pair<int, int>> rv = {};
    rv.push_back(make_pair(0, 0));
    if(x > 0 && y > 0) {
        if(g[x - 1][y - 1] == t && (find(dir[0].begin(), dir[0].end(), make_pair(x, y)) != dir[0].end() || ft)) {rv.push_back(make_pair(x - 1, y - 1)); rv[0].second++; dir[0].push_back(make_pair(x - 1, y - 1));}
    }
    if(x > 0) {
        if(g[x - 1][y] == t && (find(dir[1].begin(), dir[1].end(), make_pair(x, y)) != dir[1].end() || ft)) {rv.push_back(make_pair(x - 1, y)); rv[0].second++; dir[1].push_back(make_pair(x - 1, y));}
    }
    if(y > 0) {
        if(g[x][y - 1] == t && (find(dir[2].begin(), dir[2].end(), make_pair(x, y)) != dir[2].end() || ft)) {rv.push_back(make_pair(x, y - 1)); rv[0].second++; dir[2].push_back(make_pair(x, y - 1));}
    }
    if(x > 0 && y < b - 1) {
        if(g[x - 1][y + 1] == t && (find(dir[3].begin(), dir[3].end(), make_pair(x, y)) != dir[3].end() || ft)) {rv.push_back(make_pair(x - 1, y + 1)); rv[0].second++; dir[3].push_back(make_pair(x - 1, y + 1));}
    }
    if(x < b - 1 && y > 0) {
        if(g[x + 1][y - 1] == t && (find(dir[4].begin(), dir[4].end(), make_pair(x, y)) != dir[4].end() || ft)) {rv.push_back(make_pair(x + 1, y - 1)); rv[0].second++; dir[4].push_back(make_pair(x + 1, y - 1));}
    }
    if(y < b - 1) {
        if(g[x][y + 1] == t && (find(dir[5].begin(), dir[5].end(), make_pair(x, y)) != dir[5].end() || ft)) {rv.push_back(make_pair(x, y + 1)); rv[0].second++; dir[5].push_back(make_pair(x, y + 1));}
    }
    if(x < b - 1) {
        if(g[x + 1][y] == t && (find(dir[6].begin(), dir[6].end(), make_pair(x, y)) != dir[6].end() || ft)) {rv.push_back(make_pair(x + 1, y)); rv[0].second++; dir[6].push_back(make_pair(x + 1, y));}
    }
    if(x < b - 1 && y < b - 1) {
        if(g[x + 1][y + 1] == t && (find(dir[7].begin(), dir[7].end(), make_pair(x, y)) != dir[7].end() || ft)) {rv.push_back(make_pair(x + 1, y + 1)); rv[0].second++; dir[7].push_back(make_pair(x + 1, y + 1));}
    }
    return rv;
}


