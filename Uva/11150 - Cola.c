#include<stdio.h>
int main()
{
    int t;
    while((scanf("%d", &t)) != EOF ){
        printf("%d\n", t + (t/2) );
    }
    return 0;
}

