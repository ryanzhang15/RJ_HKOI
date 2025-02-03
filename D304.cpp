/*
ID: ryanjz2024
LANG: C++11
TASK: hangman
*/

#include <cstdlib>

#include <iostream>
#include <iomanip>
#include <fstream>

#include <cmath>

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
typedef size_t _t;
typedef double __;
typedef bool b_;
typedef int s_;
typedef unsigned int us_;
typedef short _s;
typedef unsigned short u_s;
typedef pair<s_, s_> p_s__;
typedef vector<s_> v_s__;
typedef vector<pair<s_, s_>> space;
typedef char _c;
typedef string _cstr;

_cstr rplce (_cstr word, _cstr hangman, _c letter);

int main(int argc, char * argv[]) {
    
    //ios_base::sync_with_stdio(false);
    //cin.tie(0)
    
    _cstr wrd = ""; cin >> wrd;
    _cstr hmn (wrd.length(), '_');
    
    while(find(hmn.begin(), hmn.end(), '_') != hmn.end()) {
        _c guess = '\0'; cin >> guess;
        hmn = rplce(wrd, hmn, guess);
        cout << hmn << endl;
    }
    
    return 0;
    
}

_cstr rplce (_cstr word, _cstr hangman, _c letter) {
    _t wlength = word.length();
    for(_ i = 0; i < wlength; i++) {
        if(word[i] == letter) hangman[i] = letter;
    }
    return hangman;
}
