
#ifdef __cplusplus
extern "C" {
#endif
void MinMax(long long s, long long t, long long* mn, long long* mx);
long long findGap(int T, int N);
#ifdef __cplusplus
}
#endif

// TODO: global variables can be declared here

using namespace std;

typedef long long _;
typedef const long long constant;

#define ef else if
#include <algorithm>

constant maxn = 1E5+8;

_ a[maxn];

long long findGap(int T, int N) {
    _ n = N, rv = -1E18, l = 0, r = 1E18, t, c;
    if(T == 1) {
        for(_ i = 1, j = n; i <= j; ++i, --j) {
            MinMax(l, r, &a[i], &a[j]);
            l = a[i]+1;
            r = a[j]-1;
        }
        for(_ i = 1; i <= n-1; ++i) rv = max(rv, a[i+1]-a[i]);
    } else {
        MinMax(0, 1E18, &l, &r);
        t = (r-l-1)/n+1;
        c = l;
        for(_ i = l+1; i <= r; i += t+1) {
            _ x, y;
            MinMax(i, i+t, &x, &y);
            if(~x) {
                rv = max(rv, x-c);
                c = y;
            }
        }
    }
    return rv;
}

#ifndef ONLINE_JUDGE
#include <cstdio>
#include <cmath>
int subtask_num, N;
long long A[100001];
long long call_count;
void MinMax(long long s, long long t, long long* mn, long long* mx) {
    int lo = 1, hi = N, left = N+1, right = 0;
    if (s > t) { lo /= 0; }
    while (lo <= hi){
        int mid = (lo+hi) >> 1;
        if (A[mid] >= s) hi = mid - 1, left = mid;
        else lo = mid + 1;
    }
    lo = 1, hi = N;
    while (lo <= hi) {
        int mid = (lo + hi) >> 1;
        if (A[mid] <= t) lo = mid + 1, right = mid;
        else hi = mid - 1;
    }
    if (left > right) *mn = *mx = -1;
    else{
        *mn = A[left];
        *mx = A[right];
    }
    if (subtask_num == 1) call_count++;
    else if (subtask_num == 2) call_count += right - left + 2;
}
int main() {
    scanf("%d %d", &subtask_num, &N);
    for (int i = 1; i <= N; i++) {
       scanf("%lld", &A[i]);
    }
    printf("%lld\n", findGap(subtask_num, N));
    printf("%lld\n", call_count);
    return 0;
}
#endif
