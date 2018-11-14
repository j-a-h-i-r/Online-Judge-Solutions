#include<stdio.h>
int main()
{
    int ans;

    while(scanf("%d", &ans)==1)
    {
        int i, guess, cnt = 0;
        for(i=1; i<=5; i++)
        {
            scanf("%d", &guess);
            if(ans == guess) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
