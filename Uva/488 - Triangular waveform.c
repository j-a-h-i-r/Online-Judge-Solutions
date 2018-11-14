#include<stdio.h>
int main()
{
    /*freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout); */
    int t, s = 0;
    scanf("%d", &t);
    while(t--){
        int a, f;

        scanf("%d%d", &a, &f);
        while(f--){
            int i, j;
            if(s==1) printf("\n");
            else s = 1;

            for(i=1; i<=a; i++){
                for(j=0; j<i; j++)printf("%d", i);
                printf("\n");
            }
            for(i = i-2; i>0; i--){
                for(j=0; j<i; j++)printf("%d", i);
                printf("\n");
            }
        }
    }
    return 0;
}
