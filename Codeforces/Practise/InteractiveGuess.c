#include<stdio.h>
int main()
{
    long n = 2000, l=1, h=1000000;

    while(h!=l)
    {
        n = (h+l+1)/2;

        printf("%ld\n", n);

        fflush(stdout);

        char s[3];

        scanf("%s", s);

        if(s[0] == '<')
        {
            h = n-1;
        }
        else
        {
            l = n;
        }
    }

    printf("! %ld\n", l);

    fflush(stdout);

    return 0;
}
