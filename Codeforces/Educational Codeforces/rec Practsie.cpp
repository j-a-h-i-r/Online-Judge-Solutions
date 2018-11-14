#include<stdio.h>

void print( int n)
{
    printf("%d ", n);

    if(n<=0) return;

    print(n-5);

    printf("%d ", n);
}

int main()
{
    int n;
    scanf("%d", &n);

    print(n);
}
