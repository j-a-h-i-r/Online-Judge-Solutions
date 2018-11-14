#include<stdio.h>
int main()
{
    int *ptr;

    ptr = (int*)malloc(5*sizeof(int));

    int i;

    for(i=0; i<5; i++) {
        scanf("%d", &ptr[i]);
    }

    ptr = &ptr[0];

    for(i=0; i<5; i++) {
        printf("%d %d\n",ptr, *ptr++);
    }
    free(ptr);
}
