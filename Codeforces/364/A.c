#include<stdio.h>

static int map[120];

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int i, sum = 0, j;


    for(i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    int d = sum/(n/2);


    for(i=0; i<n-1; i++)
    {
        for(j = i+1; j<n; j++)
        {
            if( a[i] + a[j] == d )
            {
                printf("%d %d\n", i+1, j+1);
                a[j] = -1;
                break;
            }
        }
    }

    return 0;
}
