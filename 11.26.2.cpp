#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int read()
{
    int goal, mark;
    char mid;
    mid = getchar();
    for (; (mid < '0' || mid > '9') && mid != '-';)
    {
        mid = getchar();
    }
    mark = 1;
    if (mid == '-')
    {
        mid = getchar();
        mark = -1;
    }
    goal = 0;
    for (; mid >= '0' && mid <= '9';)
    {
        goal *= 10;
        goal += mid - '0';
        mid = getchar();
    }
    return goal * mark;
}
const int MAXN = 1e5 + 5;
struct make
{
    long long x, y;
};
make s[MAXN];
make ss[MAXN];
make num[MAXN];
int check(make one, make two, make three, make four)
{
    long long a, b, c, d;
    a = two.x - one.x;
    b = four.x - three.x;
    c = two.y - one.y;
    d = four.y - three.y;
    return a * d - b * c < 0;
}
int cmp(make one, make two)
{
    long long a, b, c, d;
    a = two.x - num[0].x;
    b = one.x - num[0].x;
    c = two.y - num[0].y;
    d = one.y - num[0].y;
    if (a * d - b * c != 0)
    {
        return a * d - b * c < 0;
    }
    else
    {
        return a < b;
    }
}
int main()
{
    int t, n, mark, s_num, p, ss_num;
    long long add, a, b, c, d, answer;
    t = read();
    for (int i = 0; i < t; i++)
    {
        n = read();
        num[1].x = read();
        num[1].y = read();
        mark = 1;
        for (int j = 2; j <= n; j++)
        {
            num[j].x = read();
            num[j].y = read();
            if (num[j].y < num[mark].y || (num[j].y == num[mark].y && num[j].x < num[mark].x))
            {
                mark = j;
            }
        }
        num[0] = num[mark];
        num[mark] = num[n];
        n--;
        sort(num + 1, num + n + 1, cmp);
        s[0] = num[0];
        s[1] = num[1];
        s_num = 1;
        p = 0;
        for (int j = 2; j <= n; j++)
        {
            for (; s_num >= 2; s_num--)
            {
                if (check(s[s_num - 1], s[s_num], s[s_num - 1], num[j]) == 1)
                {
                    p++;
                    num[p] = s[s_num];
                }
                else
                {
                    break;
                }
            }
            s_num++;
            s[s_num] = num[j];
        }
        if (p == 0)
        {
            cout << "-1" << endl;
            continue;
        }
        add = 0;
        for (int j = 1; j <= s_num - 1; j++)
        {
            a = s[j].x - s[0].x;
            b = s[j + 1].x - s[0].x;
            c = s[j].y - s[0].y;
            d = s[j + 1].y - s[0].y;
            add += a * d - b * c;
        }
        n = p;
        mark = 1;
        for (int j = 2; j <= n; j++)
        {
            if (num[j].y < num[mark].y || (num[j].y == num[mark].y && num[j].x < num[mark].x))
            {
                mark = j;
            }
        }
        num[0] = num[mark];
        num[mark] = num[n];
        n--;
        sort(num + 1, num + n + 1, cmp);
        ss[0] = num[0];
        ss[1] = num[1];
        ss_num = 1;
        if (n == 0)
        {
            ss_num = 0;
        }
        for (int j = 2; j <= n; j++)
        {
            for (; ss_num >= 2; ss_num--)
            {
                if (check(ss[ss_num - 1], ss[ss_num], ss[ss_num - 1], num[j]) == 0)
                {
                    break;
                }
            }
            ss_num++;
            ss[ss_num] = num[j];
        }
        s[s_num + 1] = s[0];
        ss[ss_num + 1] = ss[0];
        for (int j = 0; j <= ss_num; j++)
        {
            ss[j + ss_num * 1 + 1] = ss[j];
        }
        answer = 1000000000;
        p = 0;
        for (int j = 0; j <= s_num; j++)
        {
            for (;; p++)
            {
                if (n == 0 || check(ss[p], ss[p + 1], s[j], s[j + 1]) == 1)
                {
                    a = s[j].x - ss[p].x;
                    b = s[j + 1].x - ss[p].x;
                    c = s[j].y - ss[p].y;
                    d = s[j + 1].y - ss[p].y;
                    if (a * d - b * c < answer)
                    {
                        answer = a * d - b * c;
                    }
                    break;
                }
            }
        }
        answer = add - answer;
        cout << answer << endl;
    }
    return 0;
}
