#include<stdio.h>

int order(int n[]){
    int i, a;

    if(n[0]<n[1]) a=1;
    else a = 0;

    for(i=1; i<9; i++) {
        if(n[i]<n[i+1] && a==0) return 0;
        else if(n[i]>n[i+1] && a==1) return 0;
    }
    return 1;
}

int main()
{
    /* freopen("in.txt", "r", stdin); */
    int t;
    scanf("%d", &t);
    printf("Lumberjacks:\n");
    while(t--){
        int n[12], i, a=1;

        for(i=0; i<10; i++) {
            scanf("%d", &n[i]);
        }

        if(order(n) == 1) printf("Ordered\n");
        else printf("Unordered\n");

    }
}
