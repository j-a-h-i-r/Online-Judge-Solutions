#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int max(int a, int b)
{
    return (a>b)? a: b;
}
int min(int a, int b)
{
    return (a<b)? a: b;
}

int main()
{
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);*/

    int t, cs = 0;
    scanf("%d", &t);
    getchar();

    while(t--)
    {
        printf("Case #%d:\n", ++cs);

        int i,j, k, h = 100, l = 0;
        int pos[110]; /*position of the last character of a row; */
        memset(pos, 0, sizeof pos);

        char s[60];
        char t[110][110];

        memset(t, ' ', sizeof t);

        i=50, j=2;

        fgets(s, 57, stdin);

        for(k = 0; s[k]!='\n' && s[k]!='\0'; k++)
        {
            /*printf("%c\n", s[k]);*/

            h = min( h, i), l = max(l, i);
            /*pos[i] = j;*/

            if(s[k] == 'R' )
            {
                t[i--][j++] = '/';
                pos[i+1] = j-1;
            }
            else if(s[k] == 'C')
            {
                /*printf("%d %d\n", i, j);*/
                t[i][j++] = '_';
                pos[i] = j-1;
            }
            else if(s[k] == 'F')
            {
                /*printf("%d %d\n", i, j);*/
                t[++i][j++] = '\\';
                pos[i] = j-1;
            }
        }
        l = max(l, i);

        int mr = j;

        if(t[h][pos[h]] == ' ') h++;

        for(i = h; i <= l; i++)
        {
            if( pos[i] < 2 ) continue;

            printf("| ");
            for(j = 2; j <= pos[i]; j++) printf("%c", t[i][j]);
            puts("");
        }

        printf("+");
        for(i=1; i<=mr; i++) printf("-");
        printf("\n\n");
    }

    return 0;
}
