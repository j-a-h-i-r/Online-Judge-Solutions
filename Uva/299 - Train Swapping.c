#include<stdio.h>

void swap(int n[], int i, int j){
    int temp = n[i];
    n[i] = n[j];
    n[j] = temp;
}

int main()
{
    int t;
    scanf("%d", &t);

    while(t--){
        int l, i = 0, j = 0, count = 0, flag = 0;
        scanf("%d", &l);
        int n[l];

        for(i = 0; i<l; i++){
            scanf("%d", &n[i]);
        }
        n[i] = '\0';

        for(i = 0; i<l-1; i++) {
            for(j = 0; j<l-i-1; j++){
                if (n[j]>n[j+1]) {
                    swap(n, j, j+1);
                    count++;
                    flag = 1;
                }
            }
            if(flag == 0) break;
            flag = 0;
        }

        printf("Optimal train swapping takes %d swaps.\n", count);
    }
}
