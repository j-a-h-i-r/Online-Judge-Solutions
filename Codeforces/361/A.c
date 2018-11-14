#include<stdio.h>

static int map[10];

int main()
{
    int n;
    scanf("%d", &n);
    getchar();

    while(n--)
    {
        char c;
        c = getchar();

        map[ c - '0' ] = 1;
    }

    int flag = 0;

    if( !(map[1] || map[4] || map[7] || map[0]) ) flag = 1;
    else if( !(map[3] || map[6] || map[9] || map[0]) ) flag = 1;
    else if ( !(map[1]||map[2]||map[3]) ) flag = 1;
    else if(!(map[7] || map[9] || map[0])) flag = 1;
    else if( !(map[1]||map[2]||map[3]||map[4]||
               map[7]) ) flag = 1;
    else if( !(map[1]||map[2]||map[3]||map[6]||
               map[9]) ) flag = 1;
    else if( !(map[1]||map[4]||map[7]||map[8]||
               map[0]) ) flag = 1;
    else if( !(map[3]||map[6]||map[9]||map[8]||
               map[0]) ) flag = 1;

    if(flag == 1) printf("NO\n");
    else printf("YES\n");

    return 0;
}
