#include<stdio.h>

int diff(char a[], char b[])
{
    int d = 0, i;

    for(i=0; a[i] && d<2; i++) {
        if( a[i] != b[i] ) d++;
    }
    return d;
}

int main()
{
    /*freopen("in.txt", "r", stdin);*/

    int t, c = 0;
    scanf("%d", &t);
    getchar();
    while(t--)
    {

        int n, i;
        scanf("%d", &n);
        getchar();

        char s[n][15], p[15];

        for(i=0; i<n; i++) {
            fgets(s[i], 14, stdin);
        }

        fgets(p, 14, stdin);

        printf("Case %d:\n", ++c);

        for(i=0; i<n; i++ )
        {
            if(diff(s[i], p) < 2 ) printf("%s", s[i]);
        }
    }

    return 0;
}
