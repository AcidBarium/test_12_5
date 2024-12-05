#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define endl '\n'
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define Forget_that return
#define Just_go 0
#define Endl endl
#define ednl endl
#define eldn endl
#define dnel endl
#define enndl endl
#define Ednl endl
#define Edml endl
#define llmax 9223372036854775807
#define intmax 2147483647

struct point
{
    int id;
    ll x;
    ll y;
    point(int idd = 0, ll xxx = 0, ll yyy = 0)
    {
        id = idd;
        x = xxx;
        y = yyy;
    }
} yuanshi[200005], arr[200006], st1[2000060], st2[4000060];

inline ld dis(const point &a, const point &b)
{
    ld one = 1.0;
    return sqrt(one * (a.x - b.x) * (a.x - b.x) + one * (a.y - b.y) * (a.y - b.y));
}

inline ll crossMul(const point &a1, const point &a2, const point &b1, const point &b2)
{
    return (a2.x - a1.x) * (b2.y - b1.y) - (b2.x - b1.x) * (a2.y - a1.y);
}

inline ld dis(const point &a, const point &b1, const point &b2)
{
    ld temp = abs(crossMul(a, b1, a, b2));
    Forget_that temp / dis(b1, b2);
}

inline ll getS(const point &a, const point &b, const point &c)
{
    return abs(crossMul(a, b, a, c));
}

bool cmp1(const point &a, const point &b)
{
    ld temp = crossMul(arr[1], a, arr[1], b);
    if (temp > 0)
        return true;
    if (temp == 0 && dis(arr[1], a) < dis(arr[1], b))
        return true;
    return false;
}

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

inline void solve()
{
    int n = read();
    vector<bool> isFang(n + 1, false);
    ll xmin = llmax, ymin = llmax, idmin = llmax;
    _rep(i, 1, n)
    {
        ll xx = read(), yy = read();
        yuanshi[i].x = xx, yuanshi[i].y = yy, yuanshi[i].id = i;
        arr[i].x = xx, arr[i].y = yy, arr[i].id = i;
        if (yy < ymin || (yy == ymin && xx < xmin))
            ymin = yy, xmin = xx, idmin = i;
    }

    point temp(arr[idmin].id, arr[idmin].x, arr[idmin].y);
    arr[idmin].x = arr[1].x, arr[idmin].y = arr[1].y, arr[idmin].id = arr[1].id;
    arr[1].id = temp.id, arr[1].x = temp.x, arr[1].y = temp.y;

    sort(arr + 2, arr + 1 + n, cmp1);

    int p1 = 1;
    st1[p1] = arr[1];

    _rep(i, 2, n)
    {
        while (p1 > 1 && crossMul(st1[p1 - 1], st1[p1], st1[p1 - 1], arr[i]) <= 0)
            p1--;
        st1[++p1] = arr[i];
    }
    st1[p1 + 1] = arr[1];

    if (p1 == n)
    {
        cout << -1 << endl;
        Forget_that;
    }

    _rep(i, 1, p1) isFang[st1[i].id] = true;

    int n2 = 0;
    _rep(i, 1, n)
    {
        if (isFang[i])
            continue;
        arr[++n2] = yuanshi[i];
    }

    xmin = llmax, ymin = llmax, idmin = llmax;
    _rep(i, 1, n2)
    {
        if (arr[i].y < ymin || (arr[i].y == ymin && arr[i].x < xmin))
            ymin = arr[i].y, xmin = arr[i].x, idmin = i;
    }
    temp.x = arr[idmin].x, temp.y = arr[idmin].y, temp.id = arr[idmin].id;
    arr[idmin].x = arr[1].x, arr[idmin].y = arr[1].y, arr[idmin].id = arr[1].id;
    arr[1].id = temp.id, arr[1].x = temp.x, arr[1].y = temp.y;

    sort(arr + 2, arr + 1 + n2, cmp1);

    int p2 = 1;
    st2[p2] = arr[1];
    _rep(i, 2, n2)
    {
        while (p2 > 1 && crossMul(st2[p2 - 1], st2[p2], st2[p2 - 1], arr[i]) <= 0)
            p2--;
        st2[++p2] = arr[i];
    }
    st2[p2 + 1] = arr[1];
    st2[0] = st2[p2];

    ll sMin = llmax;

    _rep(i, 1, p1)
    {
        st1[i + p1] = st1[i + 2 * p1] = st1[i + 3 * p1] = st1[i + 4 * p1] = st1[i];
    }
    _rep(i, 1, p2)
    {
        st2[i + p2] = st2[i + 2 * p2] = st2[i + 3 * p2] = st2[i + 4 * p2] = st2[i + 5 * p2] = st2[i + 6 * p2] = st2[i + 7 * p2] = st2[i + 8 * p2] = st2[i + 9 * p2] = st2[i + 10 * p2] = st2[i];
    }

    int posi2 = 1;

    ld mintempDis = llmax;

    _rep(i, 1, p2)
    {
        if (dis(st2[i], st1[1], st1[2]) < mintempDis)
        {
            mintempDis = dis(st2[i], st1[1], st1[2]);
            posi2 = i;
        }
    }

    _rep(i, 1, p1)
    {
        while (dis(st2[posi2], st1[i], st1[i + 1]) > dis(st2[posi2 + 1], st1[i], st1[i + 1]))
        {
            posi2++;
        }
        // cout << i << " " << posi2 << "s = " << getS(st2[posi2], st1[i], st1[i + 1]) << Endl;
        sMin = min(sMin, getS(st2[posi2], st1[i], st1[i + 1]));
    }

    ld sSum = 0;

    _rep(i, 2, p1 - 1)
    {
        sSum += getS(st1[1], st1[i], st1[i + 1]);
    }
    // cout << "sum ";
    // cout << (long long)(sSum) << endl;
    // // cout << "smin " << sMin << endl;
    // cout << (long long)(sMin) << Endl;
    cout << (long long)((sSum - sMin)) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int asd;
    asd = read();
    while (asd--)
    {
        solve();
    }

    Forget_that Just_go;
}
/*

2
6
-2 0
1 -2
5 2
0 4
1 2
3 1
4
0 0
1 0
0 1
1 1

                                                                                                         -^^--
                                                                      .-++^*nvvza1!!ii1uan~;^+.         ~6@@@#8i*
                                                                 .+n!6&@@###&6%%%%%%666&#&##@@@@&3uv*-  1#6uni&@6o-.      .
                                                            .-~i6#@@&6ivo~n~~~~~oo~~~o~~~~ooonai8&##@#8vz6%znz!&@@@&66u~~3&#%u^
                                                         ^z8&@@&81vo~oooooooooooooooooooo~~oooo~~~~oai6#@@6avvvvvzau!8&##8i1%@6~
                                                     .o3&@@&81n~~oooooooooooooooooooooooooooooooooo~o!@@8uvvvvvvvvzzzzvvzzzza%@3+
                                                  .n6#@#%unoooooooooooooooooooooooooooooooooooooooooa6&!vzvvvvvvvvvvvvzvvvzva6#!-
                                               .*i&@#%1o~ooooooooooooooooooooooooooooooooooovuuvo~ooa%%!zzvvvvvvvvvzvzvvzvvv3#%*
                                             .~6@@6in~oo~oooooooooooooooooooooooooooooooooooooz36un~n363zvvvvvvvvzvzvvvzvzvv1&#1
                                            ~%@@6ao~o~~ooooooooooooooooooooooooooooooooooooooooou6!vou%81zvvvvvzvzvzvzvvvvvvv6@8;
                                          ^6@@6anooo~o~ooooooooooooooooooooooooooooooooooooooo~o~z66zou6881zvzvzzzzvvvvvvvvvv6@&n
                                        .a&@6u~o~~~o~~ooooooooooooooooooooooooooooooooooooooooo~ooz63zoou6%&81azzzzzzzzvvzvvu6@8*
                                       *8@#6vooooooooooooooooooooooooooooooooooooooooooooooooooooo~z63voonz!8&@#8iuzzzvvzvvu%@&n
                                      ~&@&un~ooo~oooooooooooooooooooooooooooooooooooooooooooooooo~~~u6uo~o~~ov1%&@@#6%3i116#@@&v.
                                     o6@%zoo~oooooooooooooooooooooooooooooooooooooooooooooooooooooooo1!voo~~oo~~~nai66##@@#6i16@6;
                                   .n#@6voooooooooooooooooooooooooooooooooooooooooooooooooooooooooooov!unoo~oooooooono~onooonov6@&a.
                                   z#@%v~ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooovzooooooooooooooooooooooon!##i+
                                  v&@%z;~oooooooooooooooooooooo~oooooooooooooooooooooooooooooooooooooovivo~oooooooooooooooooooooo1&@6+
                                 ;6@6z~~ooooooooooooooooooooooooiaoooooooooooov38ao~ooooooooooooooooooz%6nooooooooooooooooooooooooi@@6+
                                +3@&u~o~oooooooooooooooooooooov86voooooooooo~n6@@8oo~ooooooooooooooo~oa&&v~oooooooooooooooooooooooni@@u-
                               -1@@6o~ooooooooooooooooooooo~~o36uooooooooooon8#@@6noooooooooooooooooooa&&zoo~oooo~ooooooooooooooonov6@#a
                               o##6nooooooooooooooooooooooooou&3n~ooooooooov%##8#6aoooooooooooooooooon!@6uznoooooooooooooooooooooooou&@6*
                              -8@@io~ooooooooooooooooooooooov66a~ooooooooou&@%;u#6a~ooooooooooooooooov%@616@#&%8iznoooooooooooooooooo!@#u
                              ~&@8n~ooooooooooooooooooooooooa66noooooooov8@@%;-z&&1ooooooooooooooooo~1@@@@@@@@@@@@#8aooooooooooooooo~z6@6^
                             .i@#!o~ooooooooooooooooooooooon3&1~~oa136&#@@@@@&83&#iooooooooooooooooov%@@@@&3v1&@@@@@@6!voooooooooooooo6@#1.
                             ;6@6u~~ooooooooooooooooooooooov86ai&@@@@@@@#@@@@@@@@@3~oooo~~n~~ooooo~v%@@@6~-;n~v%@@&#@@@&!n~oooooooooooz&@%;
                             n6@%n~oooooooooooooooooooooooou6#@@@@@@@#!;++^~!#@@@@#8noo~n%@&a~o~o~n%@@6;o3!138###@@&%#@@@%zooooooooooov8@6n
                             a&@3~~ooooooooooooooooooooonu%#@@@@@@&3n~i@@@##&%86@@#%zooo3@@&a~o~~z8@#a-v&6voooo1#@@@&6%#@#1oooooooooooo1##u.
                             i@#1o~~oooooooooooooooo~~o1&@@@@@@%a^ .1#6ivnnonz886#&aoon!#@@%vooo1&#&a-v&&uooooooi&@#@#!vznoo~oooooooooo1@#a.
                            -3@&zooooooooooooooooo~oov3#@@@@@u.   ^3#8vooooooov8#@@ion!#@@#3~~u6@&i+.*%@!n~oooooo3@6%@@!o~oooooooooooon8@&n
                            -6@6vooooooooooooooooooov8@@@##&8^   -i@&aooooooooou&@@6u%@616#!i&@@!+..-v@#aoooooo~o1#&nz@@8no~ooooooooooa&@3^
                            -6@%voooooooooooooooooooz&@#%1a&3.   ;6#8noooooooooo8@@@@@6;*%#@%1~-.. ..u@&aooooooooz&&o-a##6n~oooooooooo8@&n
                             i@%o~~oooooooooooooooooonavooo81.   n##!noooooooooo8@#@6u+..-+-........-1@&zo~oooo~o1&8* -1&@8noooooo~ooo8&#u-
                             a&%n~ooooooooooooooooooooo~ooa%i.   n#&uooooooooooo8#3o+.. -... ........-+. +;ooooov3&u. .-i#&1ooooooni83n!@%*
                             n83oooooooooooooooooooooooooou&!.   +~;.^~oooooooou%8o..................+a661oooooni&1+  ..^6#%zoooooa&@#v!@6~
                             *zaooooooooooooooooooooooooooa%i.   .o11~~ooooooon!%a....................-v8%6unv186a+  ...-z6&!noooo3@@#i6@&o.
                             ;1aooooooooooooooooooooooooooa%i-    ;38ivoooooov!6u+. ....................+ni8863u;-..----*!&&6ao~~u&@@@6&@%;
                             u&iooooooooooooooonuzooooooooa6!*..   ^u8%31aa1363o-.........................---++--------+a%86&!oon%@#&@@@#!+
                            ;%#aoooooooooooooooa3z~oooooooa86~.--....^n16686u~-..........................--.---------..~3%!66%vn%@&6@@@@&n
                           -1@%nooooooooooooooo!8aoooooooov86o.----.--------............................---------------z8%va&&!6@%~z#@@@1-
                          .v#&uoooooooooooooooo!8a~ooooooon!6a--------------.............................-------------*3%3-n%#@@6nn1#@3;.
                          z&@3nooooooooooooooon3&1oooooooon!%i*------------.........;nauuzn~;*+-...........--------.--n%6n -3##6uaau%@!+
                        -1@#6noooooooooooooooooi63noooo~oonu66o------------........~31vvau1i!66!v-..............-....^6&!^*vuuuuau1!8&&a.
                       *8@#!ooooo~~~ooooooooooou6&u~ooooooon!%u+..-...............-v6innnnnnnna!1^...............  .~%@8vvuauuau3&#@&iv!%z-
                     +i#@6a~oonnvzvoooooooooo~~n6@6n~~ooo~~oi83;...................~3!annnnnvu6i;................+n8@@#&iauu13&##&3vov6%&&o
                  .;!@@#izu3%&@@@61noooooooooooni##1oooooo~oz%%a--.   .......... ...v661vnz163z+.............-*v3#@@8u%#61!6#@&!v~~ou&%ni@!-
               -z6#@@@@@@@##63u6@!~~oooooooooooov8@6a~oooooon3@#6v+-  ..............-*u68663z+.......... -*z6&@@&6uooo!#@#@&6zooo~v3#8;+3#!-
               .v86%86!un*.  .~&@i~oooooooooooooov6@%voooooooz%@@@#&3z*-................-+-.. .. . ..^~u8#@@#%ivo~oo~~v6@@%v~oooni6#1+ *%#u.
                            . *6@3ooooooooooooooo~u&@8zooooooou&@61%#@@@&8!a~+-.  ..........-.-+;z!66##@&3anoooooooooo~z&@3oo~v3&#3*  *6@i+
                              +%@6vooooooooooooooooa%@6aooooooou&#!oonzi66&#&6%1*- .......*366%&&&&%6unooooooooooooooo~o3#!~v6##6*  .v6@6a+.
                               n@#6nooooooooooo~~oo~z8##3vo~ooo~a%&3o~ooo~~~v86i^... ....-a&6!aznooooooooooo~~o~oooo~ov~~vi#@&i^  -a6#%!&#v
                               -u@#io~o~ooooon!&3voo~oa%@#6!avov1!3%in~o~oou866i^. ......+16%ivoo~~ooo~oooov6#&1~ooo1&#36#8a~- -n%##6v~z&#a.
                                -!@@6voo~oooov8#@#1noooooi6#@@#@@@6vvnoov3%&%!88n-.......*3%88%6v~~ooooooov6@@@6~noz6@@@&i-..o3##8ao~~o1##!+
                                ..1#@6unooooooi#@@@61noo~~~oou8#@@i~oou&@#6o. *3%i+. ....^36u*u6&8anoooooz%@%#@3~o1&@@@@&n*a6@6ivn~ooou6#&6%o.
                                   ;6@@6unooooz%@66&@#63unonaavvuavoov6#3*     ~38i*.....*6%1-.o6@@8131oa6#!;8@%u8@#a-*i6&&@&1o~~oov!6#&1o6#z.
                                    .o%@@&3zoooi@&;.oi%#@@6&@@#6uo~oi&##6-      -168n-...;68u+  .z&@@@@#@#u..6@@@@8;.   -+!@!ooov!#@@%z+ o6#v
                                       *u6@@#63!#@3^   -o3@@#&86&668&66&6^       -u88u+.-n8%z.    -v%@@@6;   ~3%3o.      .n8uu%#@#6v+   +!@3^
                                          +vi%#@@@@6o     +11o.-;i668ou63^         n68!*-i%6;       .i#@z.              -~!#@@6!o.     +!@%;
                                               +;on*            o6%3*-u&3^          v6%1~!%1+       .u@@@3*         .;16@#&3o+        ~8#&u.
                                                              .~66i+.-166~          -v8%8%%n        .u@#@@&n       +1##8a^.         .z#@83&a-
                                                    .-^;~~;~noo663* .-a66;           *!66&6&3o..    .1@#a%#6;.    ;%@6~.          -o3#8a~n8#v
                                                 +a%##@&6%%8668%6o....a66~         *i6&6!ui8#@6u^.  .!@&;*6@6+   +8@%;         +a%#@8v~~oo1&i+
                                                ^8@#8iuuuuaaa!88n+....z%6~      .~%@@61uuuuu16@@@6~ ^%@%*.*8#ii333##a     .-~3#@@&izno~~oo3@6*
                                                ;%@61aau6%6!!6%3+. ...v86o    .n6##3iuuuuuuuu8@%8#@&6@@u-18&@@&6@@@#z  -^z8@@&3uvnoooooooo3@i-
                                                -!#&iauau!68%86a~+....v88v. +z6@&u^z6!uuuuuuu8@%*^i&@&1+.3@&!ua3@@%##&##@#6868vonooooo~oov%&v
                                                 v&#8uaaaaaui388%%6iv*v6%1n8@#6a- ^i&3uuuuuua3#6~  -++   1@&!a1%@6+-*oo;^.+3@ioooooooo~oou&6~
                                                 ^6@&!uaaaaaaaaaui!6888%66&@#6*   +3#6uuuuuuu3##o        v#@&iu6@%;       ^3@!noooooooooo!#8^
                                                  o6@%!!i1uaaaaaaaaauuu111i6#6^   ^3#6uuuuuuui&#v        *%#6+ ~%@%*      +3@%n~nv~o~o~oo!@6^
                                                  *8@&z;a3%%83!!i1uu11uu116##a.   ^6#6uuuuuuui#@i.       -8@%^ .v@%~       v#@63#@6un~ooo!@3+
                                                *8#@&8n. .-^vu3688%%66&&##@@6+    ^6@6uuuuuua16#3-       -6@&*  o&6z.      -u#@@#@#@&iv~~!@6;
                                                ^8@8^              --.-++!#&n.    *%@8uuuuuua16@8+        a@@v   v6&1-       n6@#%*n8@@#8%@@u.
                                                .^vo.                  -a#@1-     *%@8uuuuuuau8#6;        ~#@i-   v&@6*.      -v1;.  -;zi66#i+
                                               .v81^                  .u@#!+      ;&@%uuuuuuau8#6;        *6@3+    o&@%;.
                                              -1@#1.                  .1&#@z      ;&@%uuuuuuau8#6;        +3@6*     o#@8*
                                             .u@@1-                    .1@@!-     ;6@%uuuuuuuu6#6;        .a@#z.    .v#@6+
*/