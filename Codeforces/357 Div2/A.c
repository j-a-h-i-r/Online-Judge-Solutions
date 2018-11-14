#include<stdio.h>
int main()
{
    //freopen("in.txt", "r", stdin);

    int t, flag;
    scanf("%d", &t);

    flag = 0;

    while(t--){
        char s[12];
        int a,b;

        scanf("%s %d%d", s, &a, &b);

        if(a>=2400 && (b-a)>0 ) flag = 1;

    }

    if(flag == 1) printf("YES\n");
    else printf("NO\n");
}
