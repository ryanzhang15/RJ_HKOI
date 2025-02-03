#ifdef __cplusplus
extern "C" {
#endif
void answer(char option);
int score();
void exam();
#ifdef __cplusplus
}
#endif

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
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <algorithm>
#include <numeric>
#include <random>
#define ef else if

using namespace std;

typedef long long _;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 10+8;

_ a[maxn], c, s1, s2, s3;

void exam() {
    for(_ i = 1; i <= 64; ++i) for(_ j = 1; j <= 10; ++j) {
        if(j == 8 || j == 9 || j == 10) answer('A'+(i-1)/16);
        ef(j == 7) answer('A');
        else {
            if(i <= (1<<(j-1))) answer('A');
            ef(i <= (1<<j)) answer('B');
            else {
                if(j == 1) {
                    if(i <= 4) answer('X');
                    else answer('A'+(i-5)/15);
                } else {
                    _ c = 1<<j;
                    answer('A'+(i-c-1)/((64-c)>>2));
                }
            }
        }
    }
    s1 = score();
    c = s1-112;
    for(_ i = 1, j = 1; i <= 6; ++i, j <<= 1) a[i] = c & j ? 5 : 6;
    a[7] = c & 64 ? 1 : 7;
    for(_ i = 1; i <= 64; ++i) for(_ j = 1; j <= 10; ++j) {
        if(j == 6) answer(a[6] == 5 ? 'A'+(i-1)/32 : 'C'+(i-1)/32);
        ef(j == 9 || j == 10) answer('A'+(i-1)/16);
        ef(j == 8) {
            if(i <= 32) answer('A');
            else answer('B');
        } ef(j == 7) answer(a[7] == 1 ? 'X' : 'B');
        else {
            if(i <= (1<<(j-1))) answer(a[j] == 5 ? 'A' : 'C');
            else {
                if(j == 1 && i == 2) answer('X');
                else {
                    _ c = max(2, 1<<(j-1));
                    answer(a[j] == 5 ? 'A'+(i-c-1)/((64-c)>>1) : 'C'+(i-c-1)/((64-c)>>1));
                }
            }
        }
    }
    s2 = score();
    c = s2-s1-208;
    for(_ i = 1, j = 1; i <= 5; ++i, j <<= 1) {
        if(a[i] == 5) a[i] = c & j ? 1 : 2;
        else a[i] = c & j ? 3 : 4;
    }
    if(c & 32) a[8] = 5;
    else a[8] = 6;
    if(a[7] != 1) {
        if(c & 64) a[7] = 2;
        else a[7] = 6;
    }
    for(_ i = 1; i <= 64; ++i) for(_ j = 1; j <= 10; ++j) {
        if(j <= 5) answer(a[j]+'A'-1);
        ef(j == 6) {
            if(i <= 16) answer(a[j] == 5 ? 'A' : 'C');
            else answer(a[j] == 5 ? 'A'+(i-17)/24 : 'C'+(i-17)/24);
        } ef(j == 7) {
            if(a[j] <= 4) answer('X');
            else answer(a[j] == 5 ? 'A' : 'C');
        } ef(j == 8) {
            if(i <= 32) answer(a[j] == 5 ? 'A' : 'C');
            else answer(a[j] == 5 ? 'A'+(i-33)/16 : 'C'+(i-33)/16);
        }
        ef(j <= 8) {
            if(a[j] <= 4) answer(a[j]+'A'-1);
            ef(i <= (1<<(j-2))) answer(a[j] == 5 ? 'A' : 'C');
            else answer('X');
        } ef(j == 9) {
            if(i == 1) answer('B');
            ef(i <= 3) answer('C');
            ef(i <= 6) answer('D');
            ef(i <= 8) answer('X');
            else answer('A'+(i-9)/14);
        } ef(j == 10) {
            if(i <= 4) answer('B');
            ef(i <= 12) answer('C');
            ef(i <= 24) answer('D');
            else answer('A'+(i-25)/10);
        }
    }
    s3 = score();
    c = s3-s2-384;
    for(_ i = 6, j = 16; i <= 8; i += 2, j <<= 1) if(a[i] > 4) {
        if(a[i] == 5) a[i] = c & j ? 1 : 2;
        else a[i] = c & j ? 3 : 4;
    }
    if(a[7] > 4) {
        if(a[7] == 5) a[7] = c & 64 ? 1 : 2;
        else a[7] = c & 64 ? 3 : 4;
    }
    c &= 15;
    a[9] = c%4+1;
    a[10] = c/4+1;
    for(_ i = 193; i <= 1E4; ++i) for(_ j = 1; j <= 10; ++j) answer(a[j]+'A'-1);
    
    return;
}

#ifndef ONLINE_JUDGE
#include <cstdio>
#include <cstdlib>
#include <cmath>
char s[11];
int question, correct, scorecount;
void answer(char option) {
    if (option != 'A' && option != 'B' &&
        option != 'C' && option != 'D' &&
        option != 'X') {
        printf("Wrong Answer: Invalid option");
        exit(0);
    }
    if (question == 100000) {
        printf("Wrong Answer: Too many answer calls");
        exit(0);
    }
    correct += option == s[question++ % 10];
}
int score() {
    scorecount++;
    return correct;
}
double scoring(int correct, int scorecount) {
    if (correct < 25000 || scorecount > 40) return 0.0;
    return fmin(100.0, 36.0 * pow(tan((correct + 80000) / 115387.33), 1.0 / pow(scorecount + 1.0, 0.8)) - 28);
}
int main() {
    scanf("%s", s);
    exam();
    if (question != 100000) {
        printf("Wrong Answer: Only %d answer calls", question);
        return 0;
    }
    printf("Score presses p = %d\n", scorecount);
    printf("Correct answers s = %d\n", correct);
    printf("Final score x = %.3f\n", scoring(correct, scorecount));
    return 0;
}
#endif
