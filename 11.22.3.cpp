#include <stdio.h>
#include <string.h>
int main()
{
    char str_1[80];
    char str_2[80];
    gets(str_1);
    gets(str_2);
    char *a = str_1;
    char *b = str_2;
    while (*a && *b)
    {

        if (*a <= 'Z')
        {
            *a = *a + 32;
        }

        if (*b <= 'Z')
        {
            *b = *b + 32;
            b++;
        }

        if (*a == *b)
        {
            a++;
            b++;
        }
        if (*a != *b)
            break;
    }
    if (*a > *b)
    {
        printf(">");
    }
    else if (*a == *b)
    {
        printf("=");
    }
    else if (*a < *b)
        printf("<");
    return 0;
}