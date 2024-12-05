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

int arr[100000];
int brr[10000];

int main()
{
    int n;
    int k = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    brr[0] = -10000000;
    int ans = 0;

    for (int x = 0; x <= 20000; x++)
    {
        for (int i = 1; i <= n; i++)
        {
            brr[i] = arr[i] ^ x;
        }
        bool isok = true;
        for (int i = 1; i <= n; i++)
        {
            if (brr[i] < brr[i - 1])
            {
                isok = false;
                break;
            }
        }
        if (isok)
        {
            for (int i = 1; i <= n; i++)
            {
                cout << " " << brr[i] << " ";
            }

            if (x <= k)
                ans++;
            cout << x << "  ";
            string s = "0000000000";
            int temp = 1;
            for (int wei = 1; wei <= 10; wei++)
            {
                if (x & temp)
                    s[10 - wei] = '1';
                temp *= 2;
            }
            cout << s << endl;
        }
    }
    cout << ans << endl;
}