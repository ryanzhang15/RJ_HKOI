
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

vector<_0> books;
vector<_0> results;

int main(int argc, char * argv[]) {
    
    freopen("librarian.in", "r", stdin);
    freopen("librarian.out", "w", stdout);
    
    _0 N = 0, Q = 0; cin >> N >> Q;
    for(_0 i = 0; i < N; i++) {
        _0 a = 0; cin >> a; books.push_back(a);
    }
    sort(books.begin(), books.end());
    _ size = books.size();
    
    for(_0 i = 0; i < Q; i++) {
        _0 a = 0, b = 0; cin >> a >> b;
        _0 book = -1;
        for(_ j = 0; j < size; j++) {
            if(books[j] % (_0)pow(10, a) == b) {
                book = books[j];
                break;
            }
        }
        results.push_back(book);
    }
    
    size = results.size();
    for(_ i = 0; i < size; i++) {
        cout << results[i] << endl;
    }
    
    return 0;
    
}


