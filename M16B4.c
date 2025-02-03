#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#pragma G++ optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma G++ target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

typedef __int128 ll;

ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
/* 
 * modular exponentiation
 */
ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}
 
/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
bool Miller(ll p,int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && p % 2==0)
    {
        return false;
    }
    ll s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return false;
        }
    }
    return true;
}
void isprime(const long long* array, char* result, unsigned int len) {
	srand((unsigned int)time(NULL));
	for(register int i = 0; i < len; ++i) result[i] = Miller(array[i], 5) ? '1' : '0';
    return;
}

#ifndef ONLINE_JUDGE
long long a[2000];
char r[2001];
int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
    isprime(a, r, n);
    printf("%s\n", r);
    return 0;
}
#endif