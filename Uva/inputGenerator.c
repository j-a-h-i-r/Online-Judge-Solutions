#include<stdio.h>
#include<stdlib.h>

int main()
{
    srand(time(NULL));

    freopen("in.txt", "w", stdout);

    int i;

    for(i=1; i<=5000; i++) {
        int x = rand()%7490;
        printf("%d\n", x);
    }
    return 0;
}
