#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d%d", &n,&k);

    while(n--)
    {
        int c;
        scanf("%d", &c);

        if(k%c == 0 || c%k == 0)
        {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");

    return 0;
}
