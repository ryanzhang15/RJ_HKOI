//WRITTEN BY CHATGPT

#include <bits/stdc++.h>
using namespace std;
map<string, int> topping_price;
int tea_price[11] = {0, 15, 15, 15, 18, 18, 18, 20, 20, 30, 30};
int ice_price[4] = {0, 0, 2, 3};
int sugar_price[5] = {0, 0, 1, 2, 4};

int main()
{
    topping_price["Pearl"] = 4;
    topping_price["Pudding"] = 4;
    topping_price["Aloe"] = 5;
    topping_price["Agar"] = 5;
    topping_price["Grass Jelly"] = 6;
    topping_price["Lychee Jelly"] = 6;
    topping_price["Coffee Jelly"] = 6;
    topping_price["Red Beans"] = 7;
    topping_price["Crystal Jelly Ball"] = 7;

    int b, n;
    char i[20], s[20];
    scanf("%d ", &b);
    scanf("%[^\n]s ", i);
    scanf("%s", s);
    scanf("%d ", &n);

    int price = tea_price[b];
    if (strcmp(i, "Normal") == 0)
        price += ice_price[1];
    else if (strcmp(i, "Less Ice") == 0)
        price += ice_price[2];
    else if (strcmp(i, "No Ice") == 0)
        price += ice_price[3];

    if (strcmp(s, "100%") == 0)
        price += sugar_price[1];
    else if (strcmp(s, "50%") == 0)
        price += sugar_price[2];
    else if (strcmp(s, "30%") == 0)
        price += sugar_price[3];
    else if (strcmp(s, "0%") == 0)
        price += sugar_price[4];
    
    map<string, bool> m;
    char t[20];
    for (int i = 0; i < n; i++)
    {
        scanf("%[^\n,]s", t);
        if (i != n-1) scanf(", ");
        if (m[t] == false)
        {
            price += topping_price[t];
            m[t] = true;
        }
    }
    printf("%d\n", price);
    return 0;
}
