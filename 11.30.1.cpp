#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline ll read()
{
    ll x = 0;
    int t = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            t = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    return x * t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int z0, h;
    int x1, x2, y1, y2;
    z0 = read();
    h = read();
    x1 = read();
    y1 = read();
    x2 = read();
    y2 = read();

    if (x2 < x1)
        swap(x2, x1);
    if (y2 < y1)
        swap(y2, y1);

    int asd;
    asd = read();

    while (asd--)
    {
        int x, y, z;
        x = read(), y = read(), z = read();

        if (x >= x1 && x <= x2 && y >= y1 && y <= y2 && z >= z0 && z <= z0 + h)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}

/*

1 1 -1 -1 1 1
3
-1 -1 1
0 0 2
1 2 2

*/