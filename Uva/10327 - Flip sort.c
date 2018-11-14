#include<stdio.h>
int main()
{
    int l;

    while(scanf("%d", &l) != EOF ){
        int n[l], count = 0, flag = 0;
        int i,j;
        for(i = 0; i<l; i++){
            scanf("%d", &n[i]);
        }
        n[i] = '\0';

        for(i = 0; i<l-1; i++) {
            for(j = 0; j<l-i-1; j++){
                if (n[j]>n[j+1]) {
                    int a = n[j];
                    n[j] = n[j+1];
                    n[j+1] = a;
                    count++;
                    flag = 1;
                }
            }
            if(flag == 0) break;
            flag = 0;
        }
        printf("Minimum exchange operations : %d\n", count);
    }
    return 0;
}
